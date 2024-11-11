#include <bits/stdc++.h>
using namespace std;
int main() {
  char chess[8][8];
  int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
  for (int i = 0, j = 0; i < 8; j++) {
    cin >> chess[i][j];
    if (j == 7) {
      j = -1;
      i++;
    }
  }
  for (int i = 0, j = 0; i < 8; j++) {
    if (chess[j][i] == 'B') {
      c1++;
    }
    if (j == 7 && c1 == 8) {
      r1++;
      c1 = 0;
    }
    if (j == 7) {
      j = -1;
      i++;
      c1 = 0;
    }
  }
  for (int i = 0, j = 0; i < 8; j++) {
    if (chess[i][j] == 'B') {
      c2++;
    }
    if (j == 7 && c2 == 8) {
      r2++;
      c2 = 0;
    }
    if (j == 7) {
      j = -1;
      i++;
      c2 = 0;
    }
  }
  if (r1 == 8 && r2 == 8) {
    cout << (r2 + r1) / 2 << endl;
  } else {
    cout << (r2 + r1) << endl;
  }
  return 0;
}
