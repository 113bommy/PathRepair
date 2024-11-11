#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, c = 0, d = 0;
  char s[100][100];
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      cin >> s[i][j];
    }
  }
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      if (s[i][j] == 'q') {
        c += 9;
      } else if (s[i][j] == 'Q') {
        d += 9;
      } else if (s[i][j] == 'r') {
        c += 5;
      } else if (s[i][j] == 'b') {
        c += 3;
      } else if (s[i][j] == 'k') {
        c += 3;
      } else if (s[i][j] == 'p') {
        c += 1;
      } else if (s[i][j] == 'P') {
        d += 1;
      } else if (s[i][j] == 'K') {
        d += 3;
      } else if (s[i][j] == 'B') {
        d += 3;
      } else if (s[i][j] == 'R') {
        d += 5;
      }
    }
  }
  if (c > d) {
    cout << "Black";
  } else if (c < d) {
    cout << "White";
  } else {
    cout << "Draw";
  }
}
