#include <bits/stdc++.h>
#pragma Optimize("O3")
using namespace std;
long long n, m, x, y, a, b, t;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    int v[10][10];
    char c;
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        cin >> c;
        v[i][j] = c - '0';
      }
    }
    v[0][0] = (v[0][0] + 1) % 9 + 1;
    v[1][3] = (v[1][3] + 1) % 9 + 1;
    v[2][6] = (v[2][6] + 1) % 9 + 1;
    v[3][1] = (v[3][1] + 1) % 9 + 1;
    v[4][4] = (v[4][4] + 1) % 9 + 1;
    v[5][7] = (v[4][7] + 1) % 9 + 1;
    v[6][2] = (v[6][2] + 1) % 9 + 1;
    v[7][5] = (v[7][5] + 1) % 9 + 1;
    v[8][8] = (v[8][8] + 1) % 9 + 1;
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        cout << v[i][j];
      }
      cout << '\n';
    }
  }
  return 0;
}
