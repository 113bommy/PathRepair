#include <bits/stdc++.h>
using namespace std;
int main() {
  string x[3];
  long long rock = 0, paper = 0, scissors = 0, pos;
  for (int i = 0; i < 3; i++) {
    cin >> x[i];
    if (x[i] == "rock") {
      rock++;
    } else if (x[i] == "paper") {
      paper++;
    } else {
      scissors++;
    }
  }
  if (scissors == 1 && paper == 2) {
    for (int i = 0; i < 3; i++) {
      if (x[i] == "scissors") {
        pos = i;
      }
    }
  } else if (paper == 1 && rock == 2) {
    for (int i = 0; i < 3; i++) {
      if (x[i] == "paper") {
        pos = i;
      }
    }
  } else if (rock == 1 && paper == 2) {
    for (int i = 0; i < 3; i++) {
      if (x[i] == "rock") {
        pos = i;
      }
    }
  } else {
    cout << "?";
    return 0;
  }
  if (pos == 0) {
    cout << "F";
  } else if (pos == 1) {
    cout << "M";
  } else {
    cout << "S";
  }
  return 0;
}
