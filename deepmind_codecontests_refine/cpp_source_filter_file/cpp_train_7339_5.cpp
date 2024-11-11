#include <bits/stdc++.h>
using namespace std;
char board[8][8];
int main() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) scanf(" %c", &board[i][j]);
  }
  int minA = 100, minB = 100;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (board[i][j] == 'W') {
        int k;
        for (k = i; k >= 0; k--) {
          if (k == i) continue;
          if (board[k][j] != '.') break;
        }
        if (k < 0 and i - 1 < minA) minA = i - 1;
      }
      if (board[i][j] == 'B') {
        int k;
        for (k = i; k < 8; k++) {
          if (k == i) continue;
          if (board[k][j] != '.') break;
        }
        if (k >= 8 and 7 - i < minB) minB = 7 - i;
      }
    }
  }
  if (minA <= minB)
    cout << 'A' << endl;
  else
    cout << 'B' << endl;
  return 0;
}
