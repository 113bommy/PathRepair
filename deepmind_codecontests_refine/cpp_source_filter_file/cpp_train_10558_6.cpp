#include <bits/stdc++.h>
using namespace std;
int main() {
  string input = "", alt = "";
  int left = 0, right = 0, half = 0, remain = 0;
  cin >> input >> alt;
  int inpSize = input.size(), altSize = alt.size();
  int i = 0;
  for (i; input[i] != '|'; i++) {
    left++;
  }
  i++;
  for (i; i < inpSize; i++) {
    right++;
  }
  if ((altSize + (inpSize)-1) % 2 == 0) {
    if (left == right && altSize % 2 == 0) {
      half = altSize / 2;
      int j = 0;
      for (j; j < half; j++) {
        cout << alt[j];
      }
      cout << input;
      for (j; j < half; j++) {
        cout << alt[j];
      }
    } else if (left > right && !((right + altSize) < left)) {
      half = ((inpSize - 1) + altSize) / 2;
      remain = (half - left);
      int j = 0;
      for (j; j < remain; j++) {
        cout << alt[j];
      }
      cout << input;
      for (j; j < altSize; j++) {
        cout << alt[j];
      }
    } else if (left < right && !((left + altSize) < right)) {
      half = ((inpSize - 1) + altSize) / 2;
      remain = (half - left);
      int j = 0;
      for (j; j < remain; j++) {
        cout << alt[j];
      }
      cout << input;
      for (j; j < altSize; j++) {
        cout << alt[j];
      }
    } else {
      cout << "Impossible";
    }
  } else {
    cout << "Impossible";
  }
}
