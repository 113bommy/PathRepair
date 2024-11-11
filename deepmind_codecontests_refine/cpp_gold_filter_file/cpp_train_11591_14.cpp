#include <bits/stdc++.h>
using namespace std;
int s[4005], len[4005];
int n, k;
int dp[4005][4005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i] >> len[i];
  }
  s[n + 1] = 86401;
  int ans = s[1] - 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= i; ++j) {
      dp[i][j] = max(dp[i - 1][j], s[i] - 1) + len[i];
      if (j) dp[i][j] = min(dp[i - 1][j - 1], dp[i][j]);
    }
    ans = max(ans, s[i + 1] - dp[i][k] - 1);
  }
  cout << ans;
  return 0;
}
