#include <bits/stdc++.h>
#pragma comment(linker, "/STACK: 1024000000,1024000000")
using namespace std;
const int MOD = 1e9 + 7;
const int N = 55;
int n, T;
int f[N][N][N][3], f0[N][N * N], f12[N][N][N * N], t0, t12, ct[3];
void add(int& x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}
int main() {
  scanf("%d%d", &n, &T);
  f0[0][0] = f12[0][0][0] = 1;
  t0 = t12 = 0;
  for (int o = 0, x, y; o < n; o++) {
    scanf("%d%d", &x, &y);
    --y;
    if (!y) {
      for (int i = t0; i >= 0; i--)
        for (int j = ct[0]; j >= 0; j--) add(f0[j + 1][i + x], f0[j][i]);
      t0 += x;
    } else {
      for (int i = t12; i >= 0; i--)
        for (int j = ct[1]; j >= 0; j--)
          for (int k = ct[2]; k >= 0; k--)
            add(f12[j + (y == 1)][k + (y == 2)][i + x], f12[j][k][i]);
      t12 += x;
    }
    ct[y]++;
  }
  f[1][0][0][0] = f[0][1][0][1] = f[0][0][1][2] = 1;
  for (int i = 0; i <= ct[0]; i++)
    for (int j = 0; j <= ct[1]; j++)
      for (int k = 0; k <= ct[2]; k++) {
        if (i + j + k <= 1) continue;
        if (i)
          f[i][j][k][0] =
              1ll * i * (f[i - 1][j][k][1] + f[i - 1][j][k][2]) % MOD;
        if (j)
          f[i][j][k][1] =
              1ll * j * (f[i][j - 1][k][0] + f[i][j - 1][k][2]) % MOD;
        if (k)
          f[i][j][k][2] =
              1ll * k * (f[i][j][k - 1][0] + f[i][j][k - 1][1]) % MOD;
      }
  int ans = 0;
  for (int t = 0; t <= T && t <= t0; t++)
    for (int i = 0; i <= ct[0]; i++) {
      if (!f0[i][t]) continue;
      for (int j = 0; j <= ct[1]; j++)
        for (int k = 0; k <= ct[2]; k++) {
          if (!f12[j][k][T - t]) continue;
          add(ans, (1ll * f[i][j][k][0] + f[i][j][k][1] + f[i][j][k][2]) % MOD *
                       f0[i][t] % MOD * f12[j][k][T - t] % MOD);
        }
    }
  printf("%d\n", ans);
  return 0;
}
