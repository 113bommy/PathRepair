#include <bits/stdc++.h>
using namespace std;
int i, j, it, k, n, rs[520][520];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> k;
  rs[0][0] = 1;
  for (i = 1; i <= k; ++i) {
    for (j = 0, n = (1 << i) / 2; j < n; ++j)
      for (it = 0; it < n; ++it) {
        rs[j + n][it] = rs[j][it];
        rs[j][it + n] = rs[j][it];
        rs[j + n][it + n] = rs[j][it] ^ 1;
      }
  }
  for (i = 0; i < (1 << k); ++i, cout << '\n')
    for (j = 0; j < (1 << k); ++j) cout << (rs[i][j] ? '+' : '*');
  return 0;
}
