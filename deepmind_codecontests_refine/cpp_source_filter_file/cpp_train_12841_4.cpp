#include <bits/stdc++.h>
using namespace std;
const int maxn = 300 + 10;
int a[maxn][maxn];
int f[maxn << 1][maxn][maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
  memset(f, 0xc0, sizeof(f));
  f[2][1][1] = a[1][1];
  for (int i = 3; i <= 2 * n; i++) {
    for (int j = 1; j <= min(i - 1, n); j++) {
      for (int k = 1; k <= min(i - 1, n); k++) {
        f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k - 1]);
        f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k]);
        f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - 1]);
        f[i][j][k] = max(f[i][j][k], f[i - 1][j][k]);
        if (j == k)
          f[i][j][k] += a[j][i - j];
        else
          f[i][j][k] += a[j][i - j] + a[k][i - k];
      }
    }
  }
  printf("%lld\n", f[2 * n][n][n]);
  return 0;
}
