#include <bits/stdc++.h>
using namespace std;
int main() {
  char ara[8][8];
  int a[8][2] = {{0}}, b[8][2] = {{0}};
  int i, j, k = 0, m, n, min1 = 1000, min2 = 1000;
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      cin >> ara[i][j];
    }
  }
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      if (ara[j][i] == 'B') {
        break;
      }
    }
    for (k = 0; k < j; k++) {
      if (ara[k][i] == 'W') {
        m = k;
        if (m < min1) min1 = m;
      }
    }
  }
  for (i = 0; i < 8; i++) {
    for (j = 8; j > -1; j--) {
      if (ara[j][i] == 'W') {
        break;
      }
    }
    for (k = 8; k > j; k--) {
      if (ara[k][i] == 'B') {
        m = 8 - k - 1;
        if (m < min2) min2 = m;
      }
    }
  }
  if (min1 <= min2)
    cout << "A";
  else
    cout << "B";
  return 0;
}
