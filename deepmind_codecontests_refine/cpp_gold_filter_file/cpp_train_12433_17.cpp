#include <bits/stdc++.h>
using namespace std;
int main() {
  int x = 0, o = 0, h = 0, v = 0, d = 0;
  char r;
  char ar[3][3];
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> ar[i][j];
      if (ar[i][j] == 'X')
        x++;
      else if (ar[i][j] == '0')
        o++;
    }
  }
  if (x - o > 1 || x - o < 0) {
    cout << "illegal";
    return 0;
  }
  for (int i = 0; i < 3; ++i) {
    if (ar[i][0] == ar[i][1] && ar[i][1] == ar[i][2] && ar[i][0] != '.') {
      h++;
      r = ar[i][0];
    }
    if (ar[0][i] == ar[1][i] && ar[1][i] == ar[2][i] && ar[0][i] != '.') {
      v++;
      r = ar[0][i];
    }
  }
  if (ar[0][0] == ar[1][1] && ar[1][1] == ar[2][2] && ar[0][0] != '.') {
    d = 1;
    r = ar[0][0];
  }
  if (ar[0][2] == ar[1][1] && ar[1][1] == ar[2][0] && ar[2][0] != '.') {
    d = 1;
    r = ar[0][2];
  }
  if (h == 1 || d == 1 || v == 1) {
    if (r == 'X' && x - o == 1)
      cout << "the first player won";
    else if (r == '0' && x == o)
      cout << "the second player won";
    else
      cout << "illegal";
    return 0;
  }
  if (v > 1 || h > 1) {
    cout << "illegal";
    return 0;
  }
  if (x + o == 9) {
    cout << "draw";
    return 0;
  }
  cout << (x == o ? "first" : "second");
}
