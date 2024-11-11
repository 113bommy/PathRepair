#include <bits/stdc++.h>
using namespace std;
int qpow(int x, int y) {
  int ret = 1, p = x;
  while (y) {
    if (y & 1) ret = 1ll * ret * p % 1000000007;
    y >>= 1;
    p = 1ll * p * p % 1000000007;
  }
  return ret;
}
inline int add(int x, int y) {
  return x + y >= 1000000007 ? x + y - 1000000007 : x + y;
}
inline int sub(int x, int y) { return x >= y ? x - y : x - y + 1000000007; }
int n, m, q, hs[200010], a[200010], S[200010][32], k = 29, sm[200010],
                                                   INV2 = 500000004;
int fac[100], inv[100];
inline int C(int n, int m) {
  return 1ll * fac[n] * inv[m] % 1000000007 * inv[n - m] % 1000000007;
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]), hs[i] = add(hs[i - 1], qpow(a[i], k)),
                        sm[i] = add(sm[i - 1], a[i]);
  fac[0] = inv[0] = 1;
  for (int i = 1; i <= k; i++) fac[i] = 1ll * fac[i - 1] * i % 1000000007;
  inv[k] = qpow(fac[k], 1000000007 - 2);
  for (int i = k - 1; i >= 1; i--)
    inv[i] = 1ll * inv[i + 1] * (i + 1) % 1000000007;
  S[0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 0, tmp = 1; j <= k; j++, tmp = 1ll * tmp * i % 1000000007)
      S[i][j] = add(S[i - 1][j], tmp);
  while (q--) {
    int L, R, D;
    scanf("%d%d%d", &L, &R, &D);
    n = R - L + 1;
    int val =
        1ll * sub(sm[R], sm[L - 1]) * 2 * qpow(n, 1000000007 - 2) % 1000000007;
    int fir =
            1ll * sub(val, 1ll * (n - 1) * D % 1000000007) * INV2 % 1000000007,
        now = 0;
    for (int i = 0, tmp = 1; i <= k; i++, tmp = 1ll * tmp * fir % 1000000007)
      now = add(now, 1ll * C(k, i) * tmp % 1000000007 * S[n - 1][k - i] %
                         1000000007 * qpow(D, k - i) % 1000000007);
    if (now == sub(hs[R], hs[L - 1]))
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
