#include <bits/stdc++.h>
using namespace std;
int n, m, k, l, r, a[5001];
long long as[5001];
long long dp[5001][5001];
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) as[i] = as[i - 1] + a[i];
  for (int i = 1; i <= k; i++)
    for (int j = 1; j <= n; j++) {
      if (i * m > j)
        dp[i][j] = 0;
      else
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - m] + as[j] - as[j - m]);
    }
  printf("%I64d\n", dp[k][n]);
}
