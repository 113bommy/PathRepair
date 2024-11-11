#include <bits/stdc++.h>
using namespace std;
const int N = 410;
int n, v[N], w[N], F[N], f[N][N], g[N][N][2];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++) f[i][j] = g[i][j][0] = g[i][j][1] = -1 << 30;
  for (int i = 1; i <= n; i++) f[i][i] = v[1], g[i][i][0] = g[i][i][1] = 0;
  for (int len = 1; len <= n; len++) {
    for (int l = 1; l <= n - len + 1; l++) {
      int r = l + len - 1;
      for (int i = l; i <= r - 1; i++) {
        if (w[i] - 1 == w[r])
          g[l][r][0] = max(g[l][r][0], g[l][i][0] + f[i + 1][r - 1]);
        if (w[i] + 1 == w[r])
          g[l][r][1] = max(g[l][r][1], g[l][i][1] + f[i + 1][r - 1]);
      }
      for (int i = l; i <= r - 1; i++)
        f[l][r] = max(f[l][r], f[l][i] + f[i + 1][r]);
      if (w[l] >= w[r] && w[l] - w[r] + 1 <= n)
        f[l][r] = max(f[l][r], g[l][r][0] + v[w[l] - w[r] + 1]);
      if (w[l] <= w[r] && w[r] - w[l] + 1 <= n)
        f[l][r] = max(f[l][r], g[l][r][1] + v[w[r] - w[l] + 1]);
      for (int i = l; i <= r; i++)
        if (w[i] >= w[l] && w[i] >= w[r] && w[i] - w[l] + w[i] - w[r] + 1 <= n)
          f[l][r] = max(f[l][r], g[l][i][1] + g[i][r][0] +
                                     v[w[i] - w[l] + w[i] - w[r] + 1]);
    }
  }
  for (int i = 1; i <= n; i++) {
    F[i] = F[i - 1];
    for (int j = 1; j <= i; j++) F[i] = max(F[i], F[j - 1] + f[j][i]);
  }
  printf("%d\n", F[n]);
  return 0;
}
