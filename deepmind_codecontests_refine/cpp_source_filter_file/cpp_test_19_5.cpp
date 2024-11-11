#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
const int inf = 0x3f3f3f3f;
int dp[10010][N], a[N];
int n, t;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= 2000; j++) dp[i][j] = inf;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
      for (int k = 0; k <= 2000; k++) {
        if (dp[i - 1][k] == inf) continue;
        if (k + a[i] <= 2000)
          dp[i][k + a[i]] = min(dp[i][k + a[i]], max(dp[i - 1][k], k + a[i]));
        if (k - a[i] >= 0)
          dp[i][k - a[i]] = min(dp[i][k - a[i]], dp[i - 1][k]);
        else
          dp[i][0] = min(dp[i][0], dp[i - 1][k] + a[i] - k);
      }
    int ans = 0x3f3f3f3f;
    for (int i = 0; i <= 2000; i++) ans = min(ans, dp[n][i]);
    cout << ans << endl;
  }
}
