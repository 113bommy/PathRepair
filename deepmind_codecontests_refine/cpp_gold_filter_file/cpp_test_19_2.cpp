#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n;
void solve() {
  cin >> n;
  int maxl = 0;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  maxl = *max_element(a.begin(), a.end());
  vector<vector<int>> dp(n + 1, vector<int>(2 * maxl + 1, INF));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= 2 * maxl; j++) {
      if (dp[i][j] == INF) continue;
      dp[i + 1][max(j - a[i], 0)] =
          min(dp[i + 1][max(j - a[i], 0)], dp[i][j] + a[i]);
      if (j + a[i] <= 2 * maxl)
        dp[i + 1][j + a[i]] = min(dp[i + 1][j + a[i]], max(dp[i][j] - a[i], 0));
    }
  }
  int ans = INF;
  for (int i = 0; i <= 2 * maxl; i++) {
    ans = min(ans, i + dp[n][i]);
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
