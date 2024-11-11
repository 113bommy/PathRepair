#include <bits/stdc++.h>
using namespace std;
mt19937 rng(time(0));
uniform_int_distribution<int> uid(-1e9, 1e9);
long long d[71][71][71][71];
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m, s;
  cin >> n >> m >> s;
  vector<vector<int>> v(n, vector<int>(m));
  for (auto& i : v)
    for (auto& j : i) cin >> j;
  for (int i = 0; i < 71; ++i)
    for (int j = 0; j < 71; ++j)
      for (int ii = 0; ii < 71; ++ii) fill(d[i][j][ii], d[i][j][ii] + 71, -1e9);
  d[0][0][0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k <= m / 2; ++k) {
        for (int x = 1; x <= s; ++x) {
          if (d[i][j][k][x] != -1e9) {
            if (j == m - 1)
              d[i + 1][0][0][x] = max(d[i + 1][0][0][x], d[i][j][k][x]);
            else
              d[i][j + 1][k][x] = max(d[i][j + 1][k][x], d[i][j][k][x]);
            if (k + 1 <= m / 2) {
              if (j == m - 1)
                d[i + 1][0][0][(x + v[i][j]) % s] = max(
                    d[i + 1][0][0][(x + v[i][j]) % s], d[i][j][k][x] + v[i][j]);
              else
                d[i][j + 1][k + 1][(x + v[i][j]) % s] =
                    max(d[i][j + 1][k + 1][(x + v[i][j]) % s],
                        d[i][j][k][x] + v[i][j]);
            }
          }
        }
      }
    }
  }
  cout << max(0LL, d[n][0][0][0]);
}
