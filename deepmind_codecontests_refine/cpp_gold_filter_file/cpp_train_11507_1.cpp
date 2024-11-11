#include <bits/stdc++.h>
typedef long long LL;
const double INF = 1e100;
const int oo = ~0u >> 2;
const double pi = acos(-1.0);
const double EPS = 1e-8;
const int MAXN = 100033;
LL n;
LL dp[1233][1233];
int main() {
  scanf("%I64d", &n);
  ++n;
  dp[0][0] = 1;
  for (int i = (1), __ = (778); i <= __; ++i) dp[i][i] = dp[i][1] = 1;
  for (int i = (1), __ = (778); i <= __; ++i)
    for (int j = (2), __ = (i); j < __; ++j)
      dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
  printf("%I64d\n", dp[n][6] + dp[n][7] + dp[n][8]);
  return 0;
}
