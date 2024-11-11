#include <bits/stdc++.h>
long long const mod = 1000000007, inv2 = (mod + 1) / 2;
inline long long pls(long long a, long long b) {
  return a + b < mod ? a + b : a + b - mod;
}
int n = 0, k = 0;
long long f[51][51][2], C[51][51];
int main() {
  scanf("%d %d", &n, &k);
  C[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= n; ++j) C[i][j] = pls(C[i - 1][j - 1], C[i - 1][j]);
  }
  f[1][0][0] = f[0][0][1] = 1;
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= k && 2 * j <= i; ++j) {
      for (int ls = 0; ls <= i - 1 - ls; ++ls) {
        int rs = i - 1 - ls;
        long long v =
            C[i - 1][ls] * (ls == rs ? inv2 : 1) % mod * (i == n ? 1 : i) % mod;
        for (int lmat = 0; lmat <= j; ++lmat) {
          if (lmat * 2 > ls || (j - lmat) * 2 > rs) continue;
          f[i][j][0] = pls(f[i][j][0],
                           f[ls][lmat][1] * f[rs][j - lmat][1] % mod * v % mod);
        }
        for (int lmat = 0; lmat <= j - 1; ++lmat) {
          if (lmat * 2 > ls || (j - 1 - lmat) * 2 > rs) continue;
          f[i][j][1] = pls(f[i][j][1], f[ls][lmat][1] * f[rs][j - 1 - lmat][0] %
                                           mod * v % mod);
          f[i][j][1] = pls(f[i][j][1], f[ls][lmat][0] * f[rs][j - 1 - lmat][1] %
                                           mod * v % mod);
          f[i][j][1] = pls(f[i][j][1], f[ls][lmat][0] * f[rs][j - 1 - lmat][0] %
                                           mod * v % mod);
        }
      }
    }
  }
  long long ans = pls(f[n][k][0], f[n][k][1]);
  printf("%lld", ans);
  return 0;
}
