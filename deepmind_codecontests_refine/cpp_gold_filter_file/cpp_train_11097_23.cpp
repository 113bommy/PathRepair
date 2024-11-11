#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = (1 << 8);
int Q, xl, yl, xr, yr, K, dp[35][2][2][2], f[35][2][2][2];
int Query(const int& x, const int& y) {
  if (x < 0 || y < 0) return 0;
  int ret = 0;
  f[30][1][1][1] = 1;
  for (int i = 29; i >= 0; --i) {
    for (int j = 0; j < 2; ++j)
      for (int k = 0; k < 2; ++k)
        for (int l = 0; l < 2; ++l) dp[i][j][k][l] = f[i][j][k][l] = 0;
    for (int j = 0; j < 2; ++j)
      for (int k = 0; k < 2; ++k)
        for (int l = 0; l < 2; ++l)
          if (f[i + 1][j][k][l]) {
            (dp[i][j & (!((x >> i) & 1))][k & (!((y >> i) & 1))]
               [l & (!((K >> i) & 1))] =
                   (dp[i][j & (!((x >> i) & 1))][k & (!((y >> i) & 1))]
                      [l & (!((K >> i) & 1))] +
                    dp[i + 1][j][k][l]) %
                   mod),
                (f[i][j & (!((x >> i) & 1))][k & (!((y >> i) & 1))]
                  [l & (!((K >> i) & 1))] =
                      (f[i][j & (!((x >> i) & 1))][k & (!((y >> i) & 1))]
                        [l & (!((K >> i) & 1))] +
                       f[i + 1][j][k][l]) %
                      mod);
            if ((!k || ((y >> i) & 1)) && (!l || ((K >> i) & 1)))
              (dp[i][j & (!((x >> i) & 1))][k][l] =
                   (dp[i][j & (!((x >> i) & 1))][k][l] + dp[i + 1][j][k][l] +
                    1ll * (1 << i) * f[i + 1][j][k][l]) %
                   mod),
                  (f[i][j & (!((x >> i) & 1))][k][l] =
                       (f[i][j & (!((x >> i) & 1))][k][l] + f[i + 1][j][k][l]) %
                       mod);
            if ((!j || ((x >> i) & 1)) && (!l || ((K >> i) & 1)))
              (dp[i][j][k & (!((y >> i) & 1))][l] =
                   (dp[i][j][k & (!((y >> i) & 1))][l] + dp[i + 1][j][k][l] +
                    1ll * (1 << i) * f[i + 1][j][k][l]) %
                   mod),
                  (f[i][j][k & (!((y >> i) & 1))][l] =
                       (f[i][j][k & (!((y >> i) & 1))][l] + f[i + 1][j][k][l]) %
                       mod);
            if ((!j || ((x >> i) & 1)) && (!k || ((y >> i) & 1)))
              (dp[i][j][k][l & (!((K >> i) & 1))] =
                   (dp[i][j][k][l & (!((K >> i) & 1))] + dp[i + 1][j][k][l]) %
                   mod),
                  (f[i][j][k][l & (!((K >> i) & 1))] =
                       (f[i][j][k][l & (!((K >> i) & 1))] + f[i + 1][j][k][l]) %
                       mod);
          }
  }
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
      for (int k = 0; k < 2; ++k)
        (ret = (ret + 1ll * dp[0][i][j][k] + f[0][i][j][k]) % mod);
  return ret;
}
int main() {
  scanf("%d", &Q);
  while (Q--) {
    scanf("%d%d%d%d%d", &xl, &yl, &xr, &yr, &K), --xl, --yl, --xr, --yr, --K,
        K >= (1 << 30) ? K = (1 << 30) - 1 : 0;
    printf("%lld\n", (1ll * Query(xr, yr) - Query(xr, yl - 1) -
                      Query(xl - 1, yr) + Query(xl - 1, yl - 1) + mod + mod) %
                         mod);
  }
  return 0;
}
