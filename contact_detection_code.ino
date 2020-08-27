#define dataout 12        // rf transmitter pin 
const int SENSOR_PIN = 7; 
int lastState = LOW;      // the previous state from the input pin
int currentState;         // the current reading from the input pin

void setup() {
  // initialize serial communication with monitor at 9600 bits per second:
  Serial.begin(9600);
  // initialize the Arduino's pin as aninput
  pinMode(SENSOR_PIN, INPUT);
  pinMode(dataout, OUTPUT);		// rf output 
}

void loop() {
  // read the state of the the input pin:
  currentState = digitalRead(SENSOR_PIN);

  if(lastState == LOW && currentState == HIGH){
    Serial.println("The sensor is touched");
    digitalWrite(dataout, HIGH);	// transmit HIGH bit on wearing 
  }
  //else Serial.println("No contact");

  // save the the last state
  digitalWrite(dataout, LOW);
  lastState = currentState;
  
  //delay(2000);
}