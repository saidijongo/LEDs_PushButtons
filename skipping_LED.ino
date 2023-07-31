//Trying to skip a couple of LEDs
const int numLEDs = 8; // Number of LEDs connected
int ledPins[] = {4, 5, 6, 7, 8, 9, 10, 11}; // Array to store the LED pin numbers

const int stopButtonPin = 12; // Pin number for the stop button
const int startButtonPin = 13; // Pin number for the start button

boolean blinkEnabled = true; // Flag to control blinking

void setup() {
  // Initialize all LED pins as OUTPUT
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  // Initialize push buttons as INPUT with internal pull-up resistors
  pinMode(stopButtonPin, INPUT_PULLUP);
  pinMode(startButtonPin, INPUT_PULLUP);
}

void loop() {
  // Checking if the stop button is pressed
  if (digitalRead(stopButtonPin) == LOW) {
    blinkEnabled = false; // Disable blinking
    turnOffLEDs(); // Turn off all LEDs
    while (digitalRead(stopButtonPin) == LOW) {
      // Wait until the stop button is released
    }
  }

  // Check if the start button is pressed
  if (digitalRead(startButtonPin) == LOW) {
    blinkEnabled = true; // Enable blinking
    while (digitalRead(startButtonPin) == LOW) {
      // Wait until the start button is released
    }
  }

  // Blink LEDs if blinking is enabled
  if (blinkEnabled) {
    for (int i = 0; i < numLEDs; i++) {
      if(i== (sizeof(ledPins)/sizeof(ledPins[0]))-1 ){
        continue; //skipping the last LED just for fun
      }
      
      digitalWrite(ledPins[i], HIGH); // Turn on the current LED
      delay(500);// Wait for half a second
      digitalWrite(ledPins[i], LOW); // Turn off the current LED
      delay(500);// Wait for half a second
    }
  }
}


// Function to turn off all LEDs
void turnOffLEDs() {
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}
