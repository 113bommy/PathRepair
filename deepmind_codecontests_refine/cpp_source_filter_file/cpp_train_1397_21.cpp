#include <bits/stdc++.h>
using namespace std;
int dp[105][200005];
int n, k;
int a[105], b[105];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  int i, j;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n; i++) cin >> b[i];
  memset(dp[0], -19999999, sizeof(dp[0]));
  dp[0][100002] = 0;
  for (i = 1; i <= n; i++) {
    for (j = 0; j <= 200004; j++) {
      dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + a[i] - b[i] * k] + a[i]);
    }
  }
  if (dp[n][100002])
    cout << dp[n][100002];
  else
    cout << -1;
  return 0;
}
