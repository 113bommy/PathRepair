#include <bits/stdc++.h>
using namespace std;
int dp[2][10001][101], f[101];
int n, a[101], ans, s;
void solve() {
  memset(dp, -1, sizeof dp);
  cin >> n;
  for (int i = 1; i < n + 1; i++) {
    cin >> a[i];
    s += a[i];
    f[a[i]]++;
  }
  dp[0][0][0] = 0;
  for (int i = 1; i < n + 1; i++) {
    for (int j = 0; j < s + 1; j++) {
      for (int k = 0; k < n + 1; k++) {
        int f1 = dp[!(i & 1)][j][k] != -1;
        int f2 = (j >= a[i] and k >= 1 and dp[!(i & 1)][j - a[i]][k - 1] != -1);
        if (!f1 and !f2)
          dp[i & 1][j][k] = -1;
        else if (!f1 and f2)
          dp[i & 1][j][k] = dp[!(i & 1)][j - a[i]][k - 1];
        else if (f1 and !f2)
          dp[i & 1][j][k] =
              (!dp[!(i & 1)][j][k] or dp[!(i & 1)][j][k] == a[i] ? a[i]
                                                                 : 1000000007);
        else if (dp[!(i & 1)][j][k] and dp[!(i & 1)][j][k] != a[i])
          dp[i & 1][j][k] = 1000000007;
        else if (dp[!(i & 1)][j - a[i]][k - 1] and
                 dp[!(i & 1)][j - a[i]][k - 1] != a[i])
          dp[i & 1][j][k] = 1000000007;
        else
          dp[i & 1][j][k] = a[i];
      }
    }
  }
  for (int i = 0; i < s + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      if (dp[n & 1][i][j] != -1 and dp[n & 1][i][j] != 1000000007 and
          dp[n & 1][i][j]) {
        int cur = n - j;
        if (i % j == 0 and f[i / j] == j) cur += j;
        ans = max(ans, cur);
      }
    }
  }
  cout << ans << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
