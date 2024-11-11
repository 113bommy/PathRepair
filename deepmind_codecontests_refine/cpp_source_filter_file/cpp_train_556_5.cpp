#include <bits/stdc++.h>
using namespace std;
int m[3][3];
int main() {
  int s = 0;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> m[i][j];
      s += m[i][j];
    }
  }
  m[0][0] = s / 2 - m[1][0] - m[2][0];
  m[2][2] = s / 2 - m[2][0] - m[2][1];
  m[1][1] = s / 2 - m[0][0] - m[1][1];
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      cout << m[i][j] << " \n"[j == 2];
    }
  }
  return 0;
}
