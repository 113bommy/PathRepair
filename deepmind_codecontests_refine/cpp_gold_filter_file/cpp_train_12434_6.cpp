#include <bits/stdc++.h>
using namespace std;
int dp[305][100005];
int a[100005];
int b[100005];
vector<int> g[100005];
int main() {
  ios::sync_with_stdio(false);
  int n, m, s, e;
  cin >> n >> m >> s >> e;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; ++i) {
    cin >> b[i];
    g[b[i]].push_back(i);
  }
  for (int i = 0; i < 100001; ++i) {
    g[i].push_back(1000010);
  }
  int k = s / e;
  for (int i = 0; i < 305; ++i) {
    for (int t = 0; t < 100005; ++t) {
      dp[i][t] = 100000000;
    }
  }
  memset(dp[0], 0, sizeof(dp[0]));
  for (int i = 1; i <= k; ++i) {
    for (int t = 1; t <= n; ++t) {
      if (dp[i - 1][t - 1] <= 100000) {
        dp[i][t] = dp[i][t - 1];
        int pos =
            *lower_bound(g[a[t]].begin(), g[a[t]].end(), dp[i - 1][t - 1] + 1);
        dp[i][t] = min(dp[i][t], pos);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= k; ++i) {
    for (int t = 1; t <= n; ++t) {
      if (dp[i][t] < 100001 && ((t + dp[i][t]) + i * e <= s)) {
        ans = max(ans, i);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
