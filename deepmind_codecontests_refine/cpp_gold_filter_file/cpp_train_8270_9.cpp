#include <bits/stdc++.h>
using namespace std;
const int base = 1e9 + 7;
const int N = 2e5 + 2, M = 650;
int r, g;
int d[2][N];
int main() {
  cin >> r >> g;
  if (r == 0 || g == 0) {
    cout << 1;
    return 0;
  }
  d[0][0] = d[0][1] = 1;
  int ans = 0, h = 0;
  h = 1;
  for (int i = 2; i * (i + 1) / 2 <= r + g; ++i) {
    for (int j = 0; j <= r; ++j) {
      h = i;
      if (j - i >= 0) d[1][j] = (d[1][j] + d[0][j - i]) % base;
      if (i * (i + 1) / 2 - j <= g) d[1][j] = (d[1][j] + d[0][j]) % base;
    }
    for (int j = 0; j <= r; ++j) d[0][j] = d[1][j], d[1][j] = 0;
  }
  for (int i = 0; i <= r; ++i) ans = (ans + d[0][i]) % base;
  cout << ans;
}
