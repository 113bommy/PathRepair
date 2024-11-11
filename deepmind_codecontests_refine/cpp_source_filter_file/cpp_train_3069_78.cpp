#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, w = 0, b = 0;
  char a[8][8];
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      cin >> a[i][j];
      if (a[i][j] >= 'a' && a[i][j] <= 'z') {
        if (a[i][j] == 'q') {
          b += 9;
        } else if (a[i][j] == 'r') {
          b += 5;
        } else if (a[i][j] == 'b') {
          b += 3;
        } else if (a[i][j] == 'k') {
          b += 3;
        } else if (a[i][j] == 'p') {
          b += 1;
        }
      } else {
        if (a[i][j] == 'Q') {
          w += 9;
        } else if (a[i][j] == 'R') {
          w += 5;
        } else if (a[i][j] == 'B') {
          w += 3;
        } else if (a[i][j] == 'K') {
          w += 3;
        } else if (a[i][j] == 'P') {
          w += 1;
        }
      }
    }
  }
  if (b > w) {
    cout << "Black";
  } else if (w > b) {
    cout << "White";
  } else {
    cout << "Draw";
  }
}
