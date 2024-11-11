#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j;
  int b = 0;
  int n = 0;
  char c[8][8];
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      cin >> c[i][j];
      if (c[i][j] == 'q') {
        n = n + 6;
      } else if (c[i][j] == 'r') {
        n = n + 5;
      } else if (c[i][j] == 'b' || c[i][j] == 'n') {
        n = n + 3;
      } else if (c[i][j] == 'p') {
        n = n + 1;
      } else if (c[i][j] == 'Q') {
        b = b + 6;
      } else if (c[i][j] == 'R') {
        b = b + 5;
      } else if (c[i][j] == 'B' || c[i][j] == 'N') {
        b = b + 3;
      } else if (c[i][j] == 'P') {
        b = b + 1;
      }
    }
  }
  if (n < b) {
    cout << "White" << endl;
  } else if (b < n) {
    cout << "Black" << endl;
  } else
    cout << "Draw" << endl;
}
