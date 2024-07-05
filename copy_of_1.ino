// CODE C++

// Definimos los pines de los sensores
const int pinHumedadSuelo = A0;
const int pinTemp = A1;

// Variables para almacenar los valores leídos
int valorHumedad;
float valorTemp;
float temperaturaC;
float promedioTemperatura = 0.0;
int numMediciones = 0;
float humedadPorcentaje;

void setup() {
  // Iniciamos la comunicación serial
  Serial.begin(9600);
}

void loop() {
  // Leer el valor del sensor de humedad de suelo
  valorHumedad = analogRead(pinHumedadSuelo);
  // Escalar el valor de humedad de 0-1023 a 0-100%
  humedadPorcentaje = map(valorHumedad, 0, 1023, 0, 100);

  // Leer el valor del sensor TMP36
  valorTemp = analogRead(pinTemp);
  // Convertir el valor analógico a voltaje (en milivoltios)
  float voltaje = valorTemp * (5000.0 / 1023.0);
  // Convertir el voltaje a temperatura en grados Celsius
  temperaturaC = (voltaje - 500.0) / 10.0;

  // Calcular promedio de temperatura
  promedioTemperatura = ((promedioTemperatura * numMediciones) + temperaturaC) / (numMediciones + 1);
  numMediciones++;
  
  // Mostrar mensaje de espera 
     Serial.println("Esperar 10 segundos para la proxima lectura");

  // Llamar subrutina para mostrar datos
  mostrarDatos();

  // Esperar 10 segundos antes de la siguiente lectura
  delay(10000);
}

void mostrarDatos() {
  Serial.println("Sacon Macias Silvia Yajaira");
  Serial.println("------------------------");
  Serial.print("Numero de medicion: ");
  Serial.println(numMediciones);
  Serial.print("Humedad del suelo: ");
  Serial.print(humedadPorcentaje);
  Serial.println("%");
  Serial.print("Temperatura actual: ");
  Serial.print(temperaturaC);
  Serial.println("C");
  Serial.print("Promedio de temperatura: ");
  Serial.print(promedioTemperatura);
  Serial.println("C");
}
