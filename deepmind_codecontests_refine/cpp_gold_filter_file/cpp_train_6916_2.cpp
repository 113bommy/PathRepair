#include <bits/stdc++.h>
using namespace std;
int dp[510][510], f[510 * 510];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  f[0] = 1;
  for (int i = 1; i <= n * n; i++) f[i] = (f[i - 1] << 1) % 1000000007;
  for (int i = 0; i <= n; i++) dp[i][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= min(m, i); j++)
      for (int k = j - 1; k <= i; k++)
        (dp[i][j] += dp[k][j - 1] * 1ll * (f[i - k] - 1) % 1000000007 *
                     f[k * (i - k)] % 1000000007) %= 1000000007;
  printf("%d\n", (dp[n][m] + 1000000007) % 1000000007);
  return 0;
}
