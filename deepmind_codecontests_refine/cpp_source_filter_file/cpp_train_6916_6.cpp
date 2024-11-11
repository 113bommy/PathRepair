#include <bits/stdc++.h>
using namespace std;
int dp[501][501];
int b[501 * 501];
int main() {
  int n, m;
  scanf("%d %d", &n, &m), b[0] = 1;
  for (int i = 1; i <= n; i++) dp[i][0] = 1;
  for (int i = 1; i <= n * n; i++)
    b[i] = ((long long)b[i - 1] << 1) % 1000000007;
  for (int i = 1; i <= n; i++)
    for (int j = min(m, i); j >= 1; j--)
      for (int k = j - 1; k <= i; k++)
        dp[i][j] += (long long)dp[k][j - 1] * (b[i - k] - 1) % 1000000007 *
                    b[(i - k) * k] % 1000000007,
            dp[i][j] %= 1000000007;
  printf("%d\n", dp[n][m]);
  return 0;
}
