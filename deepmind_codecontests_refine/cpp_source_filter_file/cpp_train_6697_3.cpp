#include <bits/stdc++.h>
using namespace std;
const int INF = (int)2e9;
const double EPS = 1e-6;
const int MOD = 1000003;
vector<vector<int> > g(50000);
int n, k, dp[50000][500];
long long ans;
void dfs(int v, int p = -1) {
  dp[v][0] = 1;
  for (int i = 0; i < g[v].size(); ++i) {
    int u = g[v][i];
    if (u == p) continue;
    dfs(u, v);
    for (int j = 1; j <= k; ++j) ans += dp[v][j] * dp[u][k - j - 1];
    for (int j = 1; j <= k; ++j) dp[v][j] += dp[u][j - 1];
  }
  ans += dp[v][k];
}
int main() {
  int a, b;
  cin >> n >> k;
  for (int i = 0; i < n - 1; ++i) {
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0);
  cout << ans;
  return 0;
}
