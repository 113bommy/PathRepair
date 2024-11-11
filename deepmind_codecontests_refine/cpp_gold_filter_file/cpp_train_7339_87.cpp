#include <bits/stdc++.h>
using namespace std;
int main() {
  char c[8][8];
  int minW = 100, minB = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> c[i][j];
    }
  }
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (c[j][i] == 'B') {
        break;
      } else if (c[j][i] == 'W') {
        if (minW > j) {
          minW = j;
        }
      }
    }
  }
  for (int i = 7; i >= 0; i--) {
    for (int j = 7; j >= 0; j--) {
      if (c[j][i] == 'W') {
        break;
      } else if (c[j][i] == 'B') {
        if (minB < j) {
          minB = j;
        }
      }
    }
  }
  if (7 - minB < minW) {
    cout << 'B' << '\n';
  } else {
    cout << 'A' << '\n';
  }
  return 0;
}
