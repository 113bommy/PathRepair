#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
int n, ans = 1;
int a[MAX];
int dp[MAX][2];
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  dp[0][0] = dp[0][1] = 1;
  for (int i = 1; i < n; ++i) {
    if (a[i] > a[i - 1])
      dp[i][0] = dp[i - 1][0] + 1;
    else
      dp[i][0] = 1;
    int l = i - dp[i][0];
    if (l == 0) dp[i][1] = i + 1;
    if (dp[i][0] + 1 < i + 1) dp[i][1] = max(dp[i][1], dp[i][0] + 1);
    if (l > 0 && a[l + 1] > a[l - 1])
      dp[i][1] = max(dp[i][1], dp[i][0] + 1 + dp[l - 1][0]);
    if (l + 2 <= i && a[l + 2] > a[l] + 1)
      dp[i][1] = max(dp[i][1], dp[i][0] + dp[l][0]);
    if (dp[i][0] == 1) dp[i][1] = max(dp[i][1], dp[i - 1][0] + 1);
    ans = max(ans, dp[i][0]);
    ans = max(ans, dp[i][1]);
  }
  cout << ans;
  return 0;
}
