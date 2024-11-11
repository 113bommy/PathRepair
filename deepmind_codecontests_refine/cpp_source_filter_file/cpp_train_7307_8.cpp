#include <bits/stdc++.h>
using namespace std;
long long n, K;
vector<vector<long long>> g;
vector<long long> d;
vector<vector<long long>> dp;
void dfs(long long v, long long pr, long long k) {
  for (auto c : g[v]) {
    if (c != pr) dfs(c, v, k + 1);
  }
  dp[v][k] = d[v];
  for (auto c : g[v]) {
    if (c != pr) {
      if (k + K < 201) {
        dp[v][k] += dp[c][k + K];
      }
    }
  }
  for (long long i = k + 1; i < 201; i++) {
    for (auto c : g[v]) {
      if (c != pr) {
        long long ans = dp[c][i];
        for (auto u : g[v]) {
          if (u != pr && u != c) {
            long long l = K - i + 2 * k;
            if (l >= k && l < 201) {
              ans += dp[u][l];
            }
          }
        }
        dp[v][i] = max(dp[v][i], ans);
      }
    }
  }
  for (long long i = 200; i >= k; i--) {
    dp[v][i] = max(dp[v][i], dp[v][i + 1]);
  }
}
signed main() {
  cin >> n >> K;
  K++;
  g.resize(n);
  d.resize(n);
  dp.resize(n, vector<long long>(210, 0));
  for (long long i = 0; i < n; i++) {
    cin >> d[i];
  }
  for (long long i = 0; i < n - 1; i++) {
    long long x, y;
    cin >> x >> y;
    g[x - 1].push_back(y - 1);
    g[y - 1].push_back(x - 1);
  }
  dfs(0, -1, 0);
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < 10; j++) {
    }
  }
  cout << dp[0][0];
}
