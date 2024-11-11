#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
char s[2005][2005];
int suf1[2005][2005];
int suf2[2005][2005];
long long dp[2005][2005][2], pre[2005][2005][2];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = m; j >= 1; j--)
      suf1[i][j] = suf1[i][j + 1] + (int)(s[i][j] == 'R');
  for (int j = 1; j <= m; j++)
    for (int i = n; i >= 1; i--)
      suf2[i][j] = suf2[i + 1][j] + (int)(s[i][j] == 'R');
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (i == 1 && j == 1) {
        if (s[i][j] != 'R') dp[i][j][0] = dp[i][j][1] = 1;
        continue;
      }
      if (j == 1)
        if (suf2[1][j] <= n - i)
          dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][0]) % mod;
      if (i == 1)
        if (suf1[i][1] <= m - j)
          dp[i][j][1] = (dp[i][j][1] + dp[i][j - 1][1]) % mod;
      if (i > 1 && j > 1) {
        int l = 1, r = i - 1, ans = i;
        while (l <= r) {
          int mid = (l + r) >> 1;
          if (suf2[mid + 1][j] <= n - i)
            ans = mid, r = mid - 1;
          else
            l = mid + 1;
        }
        dp[i][j][0] =
            ((dp[i][j][0] + pre[i - 1][j][0] - pre[ans - 1][j][0]) % mod +
             mod) %
            mod;
      }
      if (j > 1 && j > 1) {
        int l = 1, r = j - 1, ans = j;
        while (l <= r) {
          int mid = (l + r) >> 1;
          if (suf1[i][mid + 1] <= m - j)
            ans = mid, r = mid - 1;
          else
            l = mid + 1;
        }
        dp[i][j][1] =
            ((dp[i][j][1] + pre[i][j - 1][1] - pre[i][ans - 1][1]) % mod +
             mod) %
            mod;
      }
      pre[i][j][0] = (pre[i - 1][j][0] + dp[i][j][1]) % mod;
      pre[i][j][1] = (pre[i][j - 1][1] + dp[i][j][0]) % mod;
    }
  if (n == 1 && m == 1 && s[1][1] == '.') dp[n][m][0] = 0;
  printf("%lld\n", (dp[n][m][0] + dp[n][m][1]) % mod);
  return 0;
}
