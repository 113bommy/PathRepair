#include <bits/stdc++.h>
using namespace std;
const int N = 11 + 5, inf = 2e9;
int n, m, deg[N];
long long ans, dist[N][N], dp[(1 << N)];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) dist[i][j] = ((i == j) ? 0 : inf);
  for (int i = 0; i < m; i++) {
    int v, u, w;
    cin >> v >> u >> w;
    ans += w;
    v--, u--;
    deg[v]++, deg[u]++;
    dist[v][u] = dist[u][v] = min(1LL * w, dist[v][u]);
  }
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  vector<int> vec;
  for (int i = 0; i < n; i++) {
    if (deg[i] && dist[i][1] == inf) return cout << -1 << "\n", 0;
    if (deg[i] & 1) vec.push_back(i);
  }
  n = vec.size();
  memset(dp, 31, sizeof dp);
  dp[0] = 0;
  for (int mask = 1; mask < (1 << n); mask++) {
    int l = mask & -mask;
    int cnt = 0;
    while ((1 << cnt) != l) cnt++;
    l = cnt;
    for (int i = 0; i < n; i++) {
      if (i != l && (mask & (1 << i)))
        dp[mask] = min(dp[mask],
                       dp[mask ^ (1 << i) ^ (1 << l)] + dist[vec[l]][vec[i]]);
    }
  }
  ans += dp[(1 << n) - 1];
  cout << ans << "\n";
}
