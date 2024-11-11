#include <bits/stdc++.h>
using namespace std;
int main() {
  int i;
  short a = 0;
  cin >> i;
  if (i % 7 == 0) {
    for (int k = 0; k < i / 7; k++) cout << "7";
    a = 1;
  }
  if (i % 7 == 4) {
    cout << "4";
    for (int k = 0; k < (i - 4) / 7; k++) cout << "7";
    a = 1;
  }
  if ((i % 7 == 1) && (i > 7)) {
    cout << "44";
    for (int k = 0; k < (i - 8) / 7; k++) cout << "7";
    a = 1;
  }
  if ((i % 7 == 5) && (i > 11)) {
    cout << "444";
    for (int k = 0; k < (i - 12) / 7; k++) cout << "7";
    a = 1;
  }
  if ((i % 7 == 2) && (i > 15)) {
    cout << "4444";
    for (int k = 0; k < (i - 16) / 7; k++) cout << "7";
    a = 1;
  }
  if ((i % 7 == 6) && (i > 19)) {
    cout << "44444";
    for (int k = 0; k < (i - 20) / 7; k++) cout << "7";
    a = 1;
  }
  if ((i % 7 == 3) && (i > 23)) {
    cout << "444444";
    for (int k = 0; k < (i - 25) / 7; k++) cout << "7";
    a = 1;
  }
  if (a == 0) cout << "-1";
}
