#include <bits/stdc++.h>
using namespace std;
char str[16][128];
int dp[16][2];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int mxn = 1;
  for (int i = 0; i < n; i++) {
    scanf("%s", str[n - i]);
    if (mxn == 1) {
      for (int j = 1; j <= m; j++) {
        if (str[n - i][j] == '1') {
          mxn = n - i;
        }
      }
    }
  }
  int ll, rr;
  dp[0][1] = 1e9;
  for (int cf = 1; cf < mxn; cf++) {
    rr = 0;
    ll = 0;
    for (int i = 1; i <= m; i++) {
      if (str[cf][i] == '1') {
        rr = 2 * (m - i + 1);
        break;
      }
    }
    for (int i = m; i > 0; i--) {
      if (str[cf][i] == '1') {
        ll = 2 * (i + 1);
        break;
      }
    }
    dp[cf][0] = min(dp[cf - 1][0] + ll, dp[cf - 1][1] + m + 1);
    dp[cf][1] = min(dp[cf - 1][0] + m + 1, dp[cf - 1][1] + rr);
  }
  rr = 0;
  ll = 0;
  for (int i = 1; i <= m; i++) {
    if (str[mxn][i] == '1') {
      rr = 2 * (m - i + 1);
      break;
    }
  }
  for (int i = m; i > 0; i--) {
    if (str[mxn][i] == '1') {
      ll = 2 * i;
      break;
    }
  }
  dp[mxn][0] = min(dp[mxn - 1][0] + ll / 2, dp[mxn - 1][1] + rr / 2);
  printf("%d", dp[mxn][0] + mxn - 1);
  return 0;
}
