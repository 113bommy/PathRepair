#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, k;
long long f[65][65][2], C[65][65], sum = 0;
inline void init(int x) {
  for (register int i = 0; i <= x; ++i) {
    C[i][0] = 1;
    for (register int j = 1; j <= i; ++j) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
  }
}
int main() {
  scanf("%d%d", &n, &k);
  init(n);
  f[1][0][0] = f[0][0][1] = 1;
  for (register int i = 2; i <= n; ++i) {
    for (register int r = i - 1, l = 0; l <= r; --r, ++l) {
      if (!(l ^ r))
        sum = C[i - 2][l - 1];
      else
        sum = C[i - 1][l];
      if (i != n) sum *= i, sum %= mod;
      for (register int k = 0; k + k <= l; ++k) {
        for (register int kk = 0; kk + kk <= r; ++kk) {
          for (register int tmp = 0; tmp <= 1; ++tmp) {
            for (register int tmp1 = 0; tmp1 <= 1; ++tmp1) {
              if (f[l][k][tmp] && f[r][kk][tmp1]) {
                int pleat = (tmp == 1 && tmp1 == 1) ? 0 : 1;
                long long prune =
                    ((f[l][k][tmp] * f[r][kk][tmp1]) % mod * sum) % mod;
                f[i][k + kk + pleat][pleat] =
                    (f[i][k + kk + pleat][pleat] + prune) % mod;
              }
            }
          }
        }
      }
    }
  }
  printf("%lld\n", (f[n][k][0] + f[n][k][1]) % mod);
  return 0;
}
