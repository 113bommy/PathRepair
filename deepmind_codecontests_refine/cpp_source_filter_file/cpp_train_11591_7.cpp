#include <bits/stdc++.h>
using namespace std;
int n, m, l[4005], d[4005];
int dp[4005][4005];
int main() {
  cin >> n >> m;
  for (int i = 0; i <= m; i++) dp[0][i] = 1;
  for (int i = 1; i <= n; i++) cin >> l[i] >> d[i];
  l[n + 1] = 86401;
  int ans = INT_MIN;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= m; j++) {
      dp[i][j] = max(dp[i - 1][j], l[i]) + d[i];
      if (j) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
      ans = max(ans, l[i + 1] - dp[i][j]);
    }
  cout << ans << endl;
}
