#include <bits/stdc++.h>
using namespace std;
const int OO = (int)1e9 + 7;
int main(void) {
  ios_base::sync_with_stdio(false);
  char x[8][8];
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> x[i][j];
    }
  }
  int mnB = OO, mnW = OO;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (x[i][j] == 'B') {
        int f = 1;
        for (int k = i + 1; k < 8; k++) {
          if (x[k][j] != '.') {
            f = 0;
            break;
          }
        }
        if (f) {
          mnB = min(mnB, 8 - i - 1);
        }
      }
      if (x[i][j] == 'W') {
        int f = 1;
        for (int k = 0; k < i; k++) {
          if (x[k][j] != '.') {
            f = 0;
            break;
          }
        }
        if (f) {
          mnW = min(mnW, i);
        }
      }
    }
  }
  cout << (mnB < mnW ? "B" : "A");
  return 0;
}
