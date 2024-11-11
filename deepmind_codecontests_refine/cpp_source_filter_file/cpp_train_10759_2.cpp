#include <bits/stdc++.h>
using namespace std;
const int MAXN = 16;
long long n, answer, m, d[MAXN];
long long dist[MAXN][MAXN], dp[1 << MAXN];
bool mark[MAXN];
void dfs(int v) {
  mark[v] = true;
  for (int i = 1; i <= n; i++)
    if (dist[i][v] < 1e18 && !mark[i]) dfs(i);
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) dist[i][j] = 1e18;
  for (int i = 0; i < m; i++) {
    long long u, v, w;
    cin >> u >> v >> w;
    dist[v][u] = min(dist[u][v], w);
    dist[u][v] = dist[v][u];
    answer += w;
    d[v]++;
    d[u]++;
  }
  dfs(1);
  for (int i = 1; i <= n; i++)
    if (!mark[i]) return cout << -1 << endl, 0;
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  vector<int> vec;
  for (int i = 1; i <= n; i++)
    if (d[i] & 1) vec.push_back(i);
  int sz = vec.size();
  memset(dp, 63, sizeof(dp));
  dp[0] = 0;
  for (int mask = 1; mask < (1 << sz); mask++)
    for (int i = 0; i < sz; i++)
      for (int j = 0; j < sz; j++)
        if (mask & ((1 << i) | (1 << j)) && i != j)
          dp[mask] = min(dp[mask], dp[mask ^ ((1 << i) | (1 << j))] +
                                       dist[vec[i]][vec[j]]);
  cout << answer + dp[(1 << sz) - 1] << endl;
  cin >> n;
  return 0;
}
