#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 998244353;
long long dp[maxn][105];
int a[maxn];
int cnt[maxn][105];
int main() {
  int n, k, len;
  scanf("%d %d %d", &n, &k, &len);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) cnt[i][j] = cnt[i - 1][j];
    if (a[i] != -1) cnt[i][a[i]]++;
    if (i > len && a[i - len] != -1) cnt[i][a[i - len]]--;
    for (int j = 1; j <= k; ++j) cnt[i][0] += (cnt[i][j] > 0);
  }
  dp[0][0] = 1;
  for (int i = 1, tmp; i <= n; ++i) {
    if (a[i] != -1) {
      dp[i][a[i]] = dp[i - 1][0];
      if (i >= len && cnt[i][0] == 1)
        dp[i][a[i]] = (dp[i][a[i]] - dp[i - len][0] +
                       (i == len ? 0 : dp[i - len][a[i]]) + mod) %
                      mod;
    } else if (i < len || cnt[i][0] > 1) {
      for (int j = 1; j <= k; ++j) dp[i][j] = dp[i - 1][0];
    } else if (cnt[i][0] == 1) {
      for (int j = 1; j <= k; ++j)
        dp[i][j] = dp[i - 1][0], tmp = (cnt[i][j] > 0 ? j : 0);
      if (i >= len)
        dp[i][tmp] = (dp[i][tmp] - dp[i - len][0] +
                      (i == len ? 0 : dp[i - len][tmp]) + mod) %
                     mod;
    } else {
      for (int j = 1; j <= k; ++j) dp[i][j] = dp[i - 1][0];
      if (i >= len)
        for (int j = 1; j <= k; ++j)
          dp[i][j] = (dp[i][j] - dp[i - len][0] +
                      (i == len ? 0 : dp[i - len][j]) + mod) %
                     mod;
    }
    for (int j = 1; j <= k; ++j) dp[i][0] = (dp[i][0] + dp[i][j]) % mod;
  }
  long long ans = 0;
  for (int i = 1; i <= k; ++i) ans = (ans + dp[n][i]) % mod;
  printf("%lld", ans);
  return 0;
}
