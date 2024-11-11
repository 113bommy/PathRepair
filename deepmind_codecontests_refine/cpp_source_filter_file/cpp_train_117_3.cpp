#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long sum = 0, nega = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') nega = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
  return sum * nega;
}
const long long N = 2e5 + 9, INF = 1e18 + 7;
long long n, dp[N][12], cnt1[N], max2, max3, c, d;
long long k, len1;
signed main() {
  n = read();
  memset(dp, -INF, sizeof(dp));
  dp[0][0] = 0;
  for (long long i = 1; i <= n; i++) {
    k = read();
    max2 = 0, max3 = 0;
    len1 = 0;
    for (long long j = 1; j <= k; j++) {
      c = read(), d = read();
      if (c == 1)
        cnt1[++len1] = d;
      else if (c == 2)
        max2 = max(max2, d);
      else
        max3 = max(max3, d);
    }
    sort(cnt1, cnt1 + len1 + 1);
    for (long long j = 0; j < 10; j++) {
      long long p = j;
      dp[i][j] = dp[i - 1][j];
      p = (p + 9) % 10;
      if (j == 0) {
        dp[i][j] =
            max(dp[i - 1][p] + 2 * max(max(max2, max3), cnt1[len1]), dp[i][j]);
      } else {
        dp[i][j] =
            max(dp[i - 1][p] + max(max(max2, max3), cnt1[len1]), dp[i][j]);
      }
      p = (p + 9) % 10;
      if (len1 >= 2) {
        if (j <= 1)
          dp[i][j] =
              max(dp[i][j], dp[i - 1][p] + cnt1[len1] * 2 + cnt1[len1 - 1]);
        else
          dp[i][j] = max(dp[i][j], dp[i - 1][p] + cnt1[len1] + cnt1[len1 - 1]);
      }
      if (len1 >= 1 && max2 != 0) {
        if (j <= 1)
          dp[i][j] = max(dp[i][j], dp[i - 1][p] + cnt1[len1] + max2 +
                                       max(max2, cnt1[len1]));
        else
          dp[i][j] = max(dp[i][j], dp[i - 1][p] + cnt1[len1] + max2);
      }
      p = (p + 9) % 10;
      if (len1 >= 3) {
        if (j <= 2)
          dp[i][j] = max(dp[i][j], dp[i - 1][p] + cnt1[len1] * 2 +
                                       cnt1[len1 - 1] + cnt1[len1 - 2]);
        else
          dp[i][j] = max(dp[i][j], dp[i - 1][p] + cnt1[len1] + cnt1[len1 - 1] +
                                       cnt1[len1 - 2]);
      }
    }
  }
  long long ans = 0;
  for (long long i = 0; i < 10; i++) ans = max(ans, dp[n][i]);
  cout << ans << endl;
  return 0;
}
