#include <bits/stdc++.h>
using namespace std;
int n, m, K;
long long Cost[303][303], ans = 1e15, f[303][303];
int main() {
  scanf("%d%d%d", &n, &m, &K);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) Cost[i][j] = 1e15;
  for (int i = 1, L, R, W; i <= m; i++) {
    scanf("%d%d%d", &L, &R, &W);
    Cost[L][R] = min(Cost[L][R], (long long)W);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i - 1; j++)
      Cost[j + 1][i] = min(Cost[j + 1][i], Cost[j][i]);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) f[i][j] = j ? 1e15 : 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++) {
      f[i][j] = min(f[i][j], f[i - 1][j]);
      for (int k = 1; k <= i; k++)
        if (j >= i - k + 1)
          f[i][j] = min(f[i][j], f[k - 1][j - (i - k + 1)] + Cost[k][i]);
    }
  for (int i = K; i <= n; i++) ans = min(ans, f[n][i]);
  if (ans == 1e15) ans = -1;
  printf("%I64d\n", ans);
}
