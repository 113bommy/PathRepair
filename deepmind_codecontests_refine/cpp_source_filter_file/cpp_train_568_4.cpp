#include <bits/stdc++.h>
using namespace std;
int n, m;
char c[30][30];
int a[30][30], f[2000000], g[30][30], b[30][30];
int main() {
  scanf("%d%d\n", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) scanf("%c", &c[i][j]);
    scanf("\n");
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int vmax = 0;
      for (int k = 1; k <= n; k++) {
        if (c[i][j] == c[k][j]) {
          vmax = max(vmax, a[k][j]);
          g[i][j] += a[k][j];
          b[i][j] += (1 << (k - 1));
        }
      }
      g[i][j] -= vmax;
    }
  }
  for (int i = 0; i < (1 << n); i++) f[i] = 2000000000;
  f[0] = 0;
  for (int i = 1; i < (1 << n); i++) {
    int lb = 0;
    for (lb = 0; ((i >> lb) & 1) == 0; lb++)
      ;
    for (int j = 1; j <= m; j++) {
      f[i] = min(f[i], f[i & (b[lb + 1][j] ^ ((1 << n) - 1))] + g[lb + 1][j]);
      f[i] = min(f[i], f[i ^ (1 << lb)] + c[lb + 1][j]);
    }
  }
  printf("%d", f[(1 << n) - 1]);
}
