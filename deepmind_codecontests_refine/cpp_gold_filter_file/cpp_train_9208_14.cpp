#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 101 * 1001, MOD = 1e9 + 7;
vector<long long> child[MAXN];
long long dp[MAXN][2];
void dfs(long long u) {
  if (!child[u].size()) {
    dp[u][1] = 1;
    return;
  }
  for (auto v : child[u]) dfs(v);
  long long x = 0, y = 1;
  for (auto v : child[u]) {
    long long X = x + dp[v][0] * x + dp[v][1] * y;
    long long Y = y + dp[v][1] * x + dp[v][0] * y;
    X %= MOD;
    Y %= MOD;
    x = X;
    y = Y;
  }
  dp[u][0] = x, dp[u][1] = y;
  x = 0, y = 1;
  reverse(child[u].begin(), child[u].end());
  for (auto v : child[u]) {
    long long X = x + dp[v][0] * x + dp[v][1] * y;
    long long Y = y + dp[v][1] * x + dp[v][0] * y;
    X %= MOD;
    Y %= MOD;
    x = X;
    y = Y;
  }
  dp[u][0] += x, dp[u][1] += y;
  dp[u][0] %= MOD, dp[u][1] %= MOD;
  {
    long long x[2][2] = {};
    x[1][0] = x[0][0] = 1;
    for (auto v : child[u]) {
      long long X[2][2];
      X[0][0] = x[0][0] + x[0][1] * dp[v][1];
      X[0][1] = x[0][1] + x[0][0] * dp[v][1];
      X[1][0] = x[1][0] + x[1][1] * dp[v][0];
      X[1][1] = x[1][1] + x[1][0] * dp[v][0];
      for (long long i = 0; i < 2; i++)
        for (long long j = 0; j < 2; j++) x[i][j] = X[i][j] % MOD;
    }
    dp[u][0] -= x[0][1];
    dp[u][1] -= x[1][1] + x[1][0];
    dp[u][1] %= MOD;
    if (dp[u][0] < 0) dp[u][0] += MOD;
    if (dp[u][1] < 0) dp[u][1] += MOD;
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, x;
  cin >> n;
  for (long long i = 2; i <= n; i++) cin >> x, child[x].push_back(i);
  dfs(1);
  cout << (dp[1][0] + dp[1][1]) % MOD;
}
