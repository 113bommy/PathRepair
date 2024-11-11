#include <bits/stdc++.h>
const int N = 500005, M = 105, INF = 0x3f3f3f3f;
int n, K, p, sum[N], f[M][N], t[105], g[N];
void solveC2() {
  for (int i = 1; i <= n; i++) f[0][i] = INF;
  for (int i = 1; i <= K; i++) {
    for (int j = 0; j < p; j++) t[j] = INF;
    if (i == 1) t[0] = 0;
    for (int j = 1; j <= n; j++) {
      f[i][j] = INF;
      for (int k = 0; k < p; k++)
        f[i][j] = std::min(f[i][j], t[k] + (sum[j] - k + p) % p);
      t[sum[j]] = std::min(t[sum[j]], f[i - 1][j]);
    }
  }
  printf("%d", f[K][n]);
}
void solveC3() {
  memset(g, 0x3f, sizeof g);
  for (int i = 1; i < n; i++)
    *std::upper_bound(g + 1, g + 1 + n, sum[i]) = sum[i];
  if (g[K - 1] <= sum[n])
    printf("%d", sum[n]);
  else
    printf("%d", sum[n] + p);
}
int main() {
  scanf("%d%d%d", &n, &K, &p);
  for (int i = 1; i <= n; i++)
    scanf("%d", &sum[i]), sum[i] = (sum[i] + sum[i - 1]) % p;
  if (K * p > n)
    solveC2();
  else
    solveC3();
  return 0;
}
