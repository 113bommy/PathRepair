#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> a(k, vector<int>(n)), idx(k, vector<int>(n));
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
      a[i][j]--;
      idx[i][a[i][j]] = j;
    }
  }
  vector<int> dp(n, 1);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      bool pos = 1;
      for (int l = 0; l < k; ++l)
        if (idx[l][a[0][j]] > idx[l][a[0][i]]) ans = 0;
      if (ans == 0) continue;
      dp[a[0][i]] = max(dp[a[0][i]], dp[a[0][j]] + 1);
    }
    ans = max(ans, dp[a[0][i]]);
  }
  cout << ans << endl;
  return 0;
}
