#include <bits/stdc++.h>
const int MAXN = 550;
int n, k;
double dp[2][MAXN + 5];
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= MAXN; j++)
      dp[i & 1][j] =
          (dp[(i - 1) & 1][j] * ((k - 1) * 1.0 / k) +
           (dp[(i - 1) & 1][j + 1] + j) * (1.0 / (k * (j + 1))) +
           (dp[(i - 1) & 1][j] + (1 + j) / 2.0) * (j * 1.0 / (k * (j + 1))));
  printf("%.10f\n", dp[n & 1][1] * k);
  return 0;
}
