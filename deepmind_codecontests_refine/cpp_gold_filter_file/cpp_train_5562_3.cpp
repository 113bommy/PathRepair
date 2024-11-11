#include <bits/stdc++.h>
using namespace std;
const int N = 40, M = 1000000007;
int n = 30;
int f[N][N], g[N][N];
int main() {
  int k;
  scanf("%d", &k);
  k <<= 1;
  for (int i = 0; i <= n; i++) f[i][0] = g[i][0] = 1;
  for (int j = 1; j <= n; j++)
    for (int i = 0; i <= n; i++) {
      f[i][j] = ((1ll << i) * f[i][j - 1] + f[i + 1][j - 1]) % M;
      if (k >> j & 1) {
        if (i)
          g[i][j] = (g[i + 1][j - 1] +
                     (1ll << (i - 1)) * (f[i][j - 1] + g[i][j - 1])) %
                    M;
        else
          g[i][j] = (g[i + 1][j - 1] + f[i][j - 1]) % M;
      } else {
        if (i)
          g[i][j] = (1ll << (i - 1)) * g[i][j - 1] % M;
        else
          g[i][j] = g[i][j - 1];
      }
    }
  printf("%d\n", g[0][n]);
}
