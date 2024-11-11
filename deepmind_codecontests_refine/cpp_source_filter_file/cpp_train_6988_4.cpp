#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
const long long INF = 1LL << 60;
const int INT_INF = 1000000000;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int calc(vector<vector<int>> &dp, vector<vector<int>> &mn1,
         vector<vector<int>> &mn2, int mask, int v, int n) {
  if (dp[mask][v] != -1) return dp[mask][v];
  dp[mask][v] = 0;
  for (int u = 0; u < n; u++) {
    if (v != u && ((mask >> u) & 1))
      dp[mask][v] =
          max(dp[mask][v],
              min(mn1[u][v], calc(dp, mn1, mn2, mask ^ (1 << v), u, n)));
  }
  return dp[mask][v];
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  vector<vector<int>> mn1(n, vector<int>(n)), mn2(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int val = INT_INF;
      for (int k = 0; k < m; k++) {
        val = min(val, abs(a[i][k] - a[j][k]));
      }
      mn1[i][j] = val;
      val = INT_INF;
      for (int k = 0; k < m - 1; k++) {
        val = min(val, abs(a[i][k] - a[j][k + 1]));
      }
      mn2[i][j] = val;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    vector<vector<int>> dp(1 << n, vector<int>(n, -1));
    for (int j = 0; j < n; j++) {
      dp[1 << j][j] = (j == i ? INT_INF : 0);
    }
    for (int j = 0; j < n; j++) {
      ans = max(ans, min(mn2[j][i], calc(dp, mn1, mn2, (1 << n) - 1, j, n)));
    }
  }
  cout << ans << endl;
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
