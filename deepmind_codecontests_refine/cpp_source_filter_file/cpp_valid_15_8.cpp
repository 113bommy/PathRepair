#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int c[101][101];
int C(int n, int r) {
  if (n == r || r == 0) return 1;
  if (~c[n][r]) return c[n][r];
  return c[n][r] = (C(n - 1, r - 1) + C(n - 1, r)) % mod;
}
void solve(int tc) {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> g(n + 1);
  vector<int> deg(n + 1);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  if (k <= 2) {
    cout << C(n, k) << '\n';
    return;
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (g[i].size() >= k) {
      vector<vector<int>> dep(g[i].size(), vector<int>(n + 1));
      vector<int> dep_cnt(n + 1, 0);
      for (int j = 0; j < g[i].size(); ++j) {
        function<void(int, int, int)> dfs = [&](int u, int p, int d) {
          dep[j][d]++;
          for (int v : g[u])
            if (v != p) dfs(v, u, d + 1);
        };
        dfs(g[i][j], i, 1);
      }
      for (int d = 1; d <= n; ++d) {
        vector<vector<int>> dp(k, vector<int>(g[i].size(), 0));
        int cnt = 0;
        for (int j = 0; j < g[i].size(); ++j) {
          cnt += !!dep[j][d];
          dp[0][j] = dep[j][d];
        }
        if (cnt < k) break;
        for (int l = 1; l < k; ++l) {
          int sum = 0;
          for (int j = l; j < g[i].size(); ++j) {
            sum = (sum + dp[l - 1][j - 1]) % mod;
            dp[l][j] = sum * dp[0][j] % mod;
          }
        }
        for (int j = k - 1; j < g[i].size(); ++j)
          ans = (ans + dp[k - 1][j]) % mod;
      }
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  memset(c, -1, sizeof c);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; ++i) solve(i);
  return 0;
}
