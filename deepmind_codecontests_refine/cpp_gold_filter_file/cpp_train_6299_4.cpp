#include <bits/stdc++.h>
using namespace std;
long long dis[404][404], g[404][404], n;
long long cal() {
  for (long long k = 1; k <= n; k++) {
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= n; j++) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  return dis[1][n];
}
signed main() {
  long long k, ans = 0, x, y, m;
  cin >> n >> m;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= n; j++)
      i == j ? dis[i][j] = 0 : dis[i][j] = INT_MAX;
  for (long long i = 1; i <= m; i++) {
    cin >> x >> y;
    g[x][y] = 1;
    g[y][x] = 1;
    dis[x][y] = 1;
    dis[y][x] = 1;
  }
  ans = cal();
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      i == j ? dis[i][j] = 0 : dis[i][j] = 1;
      if (g[i][j] == 1) dis[i][j] = INT_MAX;
    }
  }
  ans = max(ans, cal());
  if (ans > n)
    cout << "-1\n";
  else
    cout << ans;
}
