#include <bits/stdc++.h>
#pragma GCC optimize("03")
using namespace std;
const int64_t N = 61;
const int64_t INF = 1e18;
int64_t dist[N][N][N], ans[N][N][N];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int64_t n, m, r, s, t, k;
  cin >> n >> m >> r;
  for (int64_t carN = 1; carN <= m; carN++)
    for (int64_t i = 1; i <= n; i++)
      for (int64_t j = 1; j <= n; j++) cin >> dist[carN][i][j];
  for (int64_t carN = 1; carN <= m; carN++)
    for (int64_t k = 1; k <= n; k++)
      for (int64_t i = 1; i <= n; i++)
        for (int64_t j = 1; j <= n; j++)
          dist[carN][i][j] =
              min(dist[carN][i][k] + dist[carN][k][j], dist[carN][i][j]);
  for (int64_t i = 1; i <= n; i++)
    for (int64_t j = 1; j <= n; j++) {
      ans[0][i][j] = dist[1][i][j];
      for (int64_t carN = 1; carN <= m; carN++)
        ans[0][i][j] = min(ans[0][i][j], dist[carN][i][j]);
    }
  for (int64_t carChange = 1; carChange <= n; carChange++)
    for (int64_t i = 1; i <= n; i++)
      for (int64_t j = 1; j <= n; j++) {
        ans[carChange][i][j] = INF;
        for (int64_t k = 1; k <= n; k++)
          ans[carChange][i][j] = min(ans[carChange][i][j],
                                     ans[carChange - 1][i][k] + ans[0][k][j]);
      }
  while (r--) {
    cin >> s >> t >> k;
    cout << ans[min(n, k)][s][t] << "\n";
  }
  return 0;
}
