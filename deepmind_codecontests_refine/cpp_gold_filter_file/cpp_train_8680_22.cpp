#include <bits/stdc++.h>
using namespace std;
const int mo = 1000000007;
int f[52][52][52][102];
int i, j, k, l, x, t, C[120][120], n, m, K, v, ans;
int main() {
  for (i = 0; i <= 100; ++i)
    for (j = 0; j <= i; ++j)
      C[i][j] = !j ? 1 : min(110, C[i - 1][j] + C[i - 1][j - 1]);
  scanf("%d%d%d", &n, &m, &K);
  n /= 2;
  for (i = 1; i <= n; ++i) f[i][i][1][1] = 1;
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j)
      for (k = 0; k <= n && k <= m; ++k)
        for (l = 1; l <= K; ++l) {
          v = f[i][j][k][l];
          if (!v) continue;
          ans = (ans + (long long)v * (m - k)) % mo;
          for (x = 1; i + x <= n; ++x) {
            int t = l * C[j + x - 1][j - 1];
            if (t > K) continue;
            f[i + x][x][k + 1][t] = (f[i + x][x][k + 1][t] + v) % mo;
          }
        }
  printf("%d\n", ans);
}
