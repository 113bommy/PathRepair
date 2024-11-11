#include <bits/stdc++.h>
const int mod = 998244353;
int n, k;
long long f[1000 + 5][1000 + 5][4];
int main() {
  scanf("%d%d", &n, &k);
  f[1][1][0] = 1, f[1][1][3] = 1;
  f[1][2][1] = 1, f[1][2][2] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= n * 2; j++) {
      f[i][j][0] = (f[i - 1][j][0] + f[i - 1][j][1] + f[i - 1][j][2] +
                    f[i - 1][j - 1][3]) %
                   mod;
      f[i][j][1] =
          (f[i - 1][j - 1][0] + f[i - 1][j][1] + f[i - 1][j - 1][3]) % mod;
      if (j != 1) f[i][j][1] = (f[i][j][1] + f[i - 1][j - 2][2]) % mod;
      f[i][j][2] =
          (f[i - 1][j - 1][0] + f[i - 1][j][2] + f[i - 1][j - 1][3]) % mod;
      if (j != 1) f[i][j][2] = (f[i][j][2] + f[i - 1][j - 2][1]) % mod;
      f[i][j][3] = (f[i - 1][j - 1][0] + f[i - 1][j][1] + f[i - 1][j][2] +
                    f[i - 1][j][3]) %
                   mod;
    }
  }
  printf("%lld", (f[n][k][0] + f[n][k][1] + f[n][k][2] + f[n][k][3]) % mod);
}
