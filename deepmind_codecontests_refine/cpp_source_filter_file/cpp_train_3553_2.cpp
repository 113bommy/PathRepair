#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(1 + n);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int m;
  cin >> m;
  vector<int> b(1 + m);
  for (int i = 1; i <= m; ++i) {
    cin >> b[i];
  }
  vector<vector<int>> dp(1 + n, vector<int>(1 + m));
  vector<int> prev(1 + m);
  for (int i = 1; i <= n; ++i) {
    int best = 0;
    int idx = 0;
    for (int j = 1; j <= m; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (a[i] == b[j] && best + 1 > dp[i - 1][j]) {
        dp[i][j] = best + 1;
        prev[j] = idx;
      }
      if (b[j] < a[i] && dp[i - 1][j] > best) {
        best = dp[i - 1][j];
        idx = j;
      }
    }
  }
  int ans = 0;
  int pos = 1;
  for (int i = 1; i <= m; ++i) {
    if (dp[n][i] > ans) {
      ans = dp[n][i];
      pos = i;
    }
  }
  vector<int> ret;
  while (pos != 0) {
    ret.push_back(b[pos]);
    pos = prev[pos];
  }
  reverse(ret.begin(), ret.end());
  cout << ans << '\n';
  for (int i = 0; i < ret.size(); ++i) {
    cout << ret[i] << ' ';
  }
  return 0;
}
