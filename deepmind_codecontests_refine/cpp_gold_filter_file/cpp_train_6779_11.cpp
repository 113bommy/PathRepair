#include <bits/stdc++.h>
using namespace std;
long long M = 998244353;
const long long N = 3e5 + 7;
long long dp[N], f[N], g[N];
vector<long long> ad[N], kid[N];
long long n, rgt[N], lft[N];
void dfs(long long v, long long p = 0) {
  for (auto u : ad[v])
    if (u != p) {
      kid[v].push_back(u);
      dfs(u, v);
    }
}
void solve(long long v) {
  g[v] = 1;
  f[v] = 1;
  for (auto u : kid[v]) {
    solve(u);
    g[v] = (g[v] * ((2 * dp[u] + f[u]) % M)) % M;
    f[v] = (f[v] * ((dp[u] + f[u]) % M)) % M;
  }
  if (kid[v].size()) {
    rgt[kid[v].back()] = 1;
    lft[kid[v][0]] = 1;
    if (kid[v].size() >= 2) {
      for (long long i = kid[v].size() - 2; i >= 0; i--)
        rgt[kid[v][i]] = (rgt[kid[v][i + 1]] *
                          ((2 * dp[kid[v][i + 1]] + f[kid[v][i + 1]]) % M)) %
                         M;
      for (long long i = 1; i < kid[v].size(); i++)
        lft[kid[v][i]] = (lft[kid[v][i - 1]] *
                          ((2 * dp[kid[v][i - 1]] + f[kid[v][i - 1]]) % M)) %
                         M;
    }
    for (auto u : kid[v])
      dp[v] = (dp[v] + ((((lft[u] * rgt[u]) % M) * g[u]) % M)) % M;
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 1; i < n; i++) {
    long long v, u;
    cin >> v >> u;
    ad[v].push_back(u);
    ad[u].push_back(v);
  }
  dfs(1);
  solve(1);
  cout << (dp[1] + f[1]) % M;
}
