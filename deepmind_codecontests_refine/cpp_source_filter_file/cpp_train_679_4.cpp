#include <bits/stdc++.h>
using namespace std;
int pos;
long long dp[2][400345], sum[2][400345];
int main() {
  int a, b, t, i, j, k;
  scanf("%d %d %d %d", &a, &b, &k, &t);
  pos = 101 + (t * (2 * k));
  int lim = ((4 * k + 1) * t) + 101;
  dp[0][a - b + pos] = 1LL;
  sum[0][0] = 0LL;
  for (i = 1; i <= lim; i++) sum[0][i] = dp[0][i] + sum[0][i - 1];
  int c = 1;
  for (i = 1; i <= t; i++) {
    long long an = 0LL, p = 2 * k + 1LL;
    for (j = 0; j <= 2 * k; j++, p--)
      an = (an + (p * dp[!c][j])) % 1000000007LL;
    dp[c][0] = an;
    for (j = 1; j <= lim; j++) {
      long long pre = dp[c][j - 1];
      long long suff = sum[!c][min(lim, j + 2 * k)] - sum[!c][j - 1];
      long long pref = sum[!c][j - 1] - sum[!c][max(0, j - 2 * k - 2)];
      dp[c][j] = (pre + suff - pref) % 1000000007LL;
      dp[c][j] += 1000000007LL;
      dp[c][j] %= 1000000007LL;
    }
    sum[c][0] = dp[c][0];
    for (j = 1; j <= lim; j++)
      sum[c][j] = (dp[c][j] + sum[c][j - 1]) % 1000000007LL;
    c = !c;
  }
  long long ans = 0LL;
  for (j = pos + 1; j <= lim; j++) ans = (ans + dp[!c][j]) % 1000000007LL;
  printf("%lld\n", ans);
  return 0;
}
