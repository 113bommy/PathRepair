#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
long long int n, k;
vector<vector<long long int>> g;
vector<vector<long long int>> dp;
long long int ans = 0;
void dfs(long long int v, long long int p = -1) {
  for (auto to : g[v]) {
    if (to == p) continue;
    dfs(to, v);
    ans += dp[to][k - 1] + dp[v][k - 1];
    for (long long int j = 1; j < k - 1; j++) {
      ans += dp[v][k - j - 1] * dp[to][j];
    }
    for (long long int j = 0; j < k; j++) {
      dp[v][j + 1] += dp[to][j];
    }
  }
  dp[v][0]++;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  g.resize(n);
  dp.resize(n, vector<long long int>(k + 1));
  for (long long int i = 1; i < n; i++) {
    long long int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0);
  cout << ans;
  return 0;
}
