#include <bits/stdc++.h>
using namespace std;
int main() {
  char c;
  int d;
  int chess[8][8];
  for (int i = 1; i <= 6; i++) {
    for (int j = 1; j <= 6; j++) {
      chess[i][j] = 8;
    }
  }
  for (int i = 1; i <= 6; i++) {
    chess[i][0] = 5;
    chess[i][7] = 5;
    chess[0][i] = 5;
    chess[7][i] = 5;
  }
  chess[0][0] = 3;
  chess[0][7] = 3;
  chess[7][0] = 3;
  chess[7][7] = 3;
  cin >> c >> d;
  c = c - 'a';
  cout << chess[c][d - 1];
  return 0;
}
