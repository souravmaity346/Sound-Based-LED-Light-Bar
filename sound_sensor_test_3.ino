#include <Adafruit_NeoPixel.h>

#define SOUND_SENSOR_PIN 34  // Analog input from HW-484
#define NEOPIXEL_PIN 27      // Data pin for NeoPixel
#define NUM_LEDS 4

#define NO_COLOR   0 
#define COLOR_RED   strip.Color(255, 0, 0) 
#define COLOR_ORANGE   strip.Color(255, 255, 0)  
#define COLOR_BLUE   strip.Color(0, 0, 255)  
#define COLOR_GREEN   strip.Color(0, 255, 0)  

Adafruit_NeoPixel strip(NUM_LEDS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  strip.begin();

  // Initialize all pixels to 'off'
  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, NO_COLOR);
  }
  strip.show();  // Show the cleared strip
}

void loop() {
  int soundValue = analogRead(SOUND_SENSOR_PIN);
  Serial.println(soundValue);

  // Normalize to number of LEDs
  int ledCount = map(soundValue, 1900, 2200, 0, NUM_LEDS);

  // Light up based on sound level
  switch(ledCount)
  {
    case 1:
      strip.setPixelColor(0, COLOR_GREEN);
      strip.setPixelColor(1, NO_COLOR);
      strip.setPixelColor(2, NO_COLOR);
      strip.setPixelColor(3, NO_COLOR);
    break;
    case 2:
      strip.setPixelColor(0, COLOR_BLUE);
      strip.setPixelColor(1, COLOR_BLUE);
      strip.setPixelColor(2, NO_COLOR);
      strip.setPixelColor(3, NO_COLOR);
    break;
    case 3:
      strip.setPixelColor(0, COLOR_ORANGE);
      strip.setPixelColor(1, COLOR_ORANGE);
      strip.setPixelColor(2, COLOR_ORANGE);
      strip.setPixelColor(3, NO_COLOR);
    break;
    case 4:
      strip.setPixelColor(0, COLOR_RED);
      strip.setPixelColor(1, COLOR_RED);
      strip.setPixelColor(2, COLOR_RED);
      strip.setPixelColor(3, COLOR_RED);
    break;
    default:
      strip.setPixelColor(0, NO_COLOR);
      strip.setPixelColor(1, NO_COLOR);
      strip.setPixelColor(2, NO_COLOR);
      strip.setPixelColor(3, NO_COLOR);
    break;
  }
  strip.show();
  delay(50);  // Small delay for visual effect
}
