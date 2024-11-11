#include <bits/stdc++.h>
using namespace std;
int n, i, j, v[155], dp[155][155 * 155], s, ind, k;
int main() {
  scanf("%d%d%d", &n, &k, &s);
  for (i = 1; i <= n; i++) scanf("%d", &v[i]);
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  for (i = 1; i <= n; i++) {
    for (j = i - 1; j >= 0; j--)
      for (ind = 0; ind <= i * j; ind++)
        if (dp[j][ind] != -1)
          if (dp[j + 1][ind + i - j - 1] == -1 ||
              dp[j + 1][ind + i - j - 1] > dp[j][k] + v[i])
            dp[j + 1][ind + i - j - 1] = dp[j][ind] + v[i];
  }
  int sol = INT_MAX;
  for (i = 0; i <= min(s, n * (n - 1) / 2); i++)
    if (dp[k][i] >= 0) sol = min(sol, dp[k][i]);
  printf("%d", sol);
  return 0;
}
