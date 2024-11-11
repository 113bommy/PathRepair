#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[8][8];
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> a[i][j];
    }
  }
  int r1 = 7, r2 = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (a[j][i] == 'B') {
        break;
      }
      if (a[j][i] == 'W') {
        if (j < r1) r1 = j;
        break;
      }
    }
  }
  for (int i = 0; i < 8; i++) {
    for (int j = 7; j > -1; j--) {
      if (a[j][i] == 'W') {
        break;
      }
      if (a[j][i] == 'B') {
        if (j > r2) r2 = j;
        break;
      }
    }
  }
  if (r1 <= 7 - r2)
    cout << 'A';
  else
    cout << 'B';
  return 0;
}
