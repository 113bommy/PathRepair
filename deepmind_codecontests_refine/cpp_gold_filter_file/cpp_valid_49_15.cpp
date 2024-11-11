#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
  return s * w;
}
const long long mod = 1e9 + 7;
long long fac[2000010], inf[2000010], iv[2000010], a[14], f[1 << 14], F[2][15],
    ans;
long long ksm(long long x, long long y) {
  long long r = 1;
  while (y) y& 1 ? r = 1ll * r * x % mod : 0, x = 1ll * x * x % mod, y >>= 1;
  return r;
}
void ini(long long n) {
  for (long long i = fac[0] = 1; i <= n; i++)
    fac[i] = 1ll * fac[i - 1] * i % mod;
  inf[n] = ksm(fac[n], mod - 2);
  for (long long i = n - 1; ~i; i--) inf[i] = inf[i + 1] * (i + 1ll) % mod;
  for (long long i = 1; i <= n; i++) iv[i] = 1ll * inf[i] * fac[i - 1] % mod;
}
signed main() {
  ini(2e6);
  long long n = read();
  for (long long i = 0; i < n; i++) a[i] = read();
  for (long long i = 0, t = 1 << n, r; i < t; i++) {
    f[i] = 1;
    for (long long j = (i - 1) & i; j; j = (j - 1) & i) {
      F[0][0] = F[1][0] = 0, r = 1;
      for (long long k = 0; k < n; k++)
        if (i >> k & 1) F[j >> k & 1][++F[j >> k & 1][0]] = k;
      for (long long c1 = 1; c1 <= F[1][0]; c1++)
        for (long long c2 = 1; c2 <= F[0][0]; c2++)
          r = 1ll * r * a[F[1][c1]] % mod * iv[a[F[1][c1]] + a[F[0][c2]]] % mod;
      f[i] = (f[i] + mod - 1ll * f[j] * r % mod) % mod;
    }
    F[0][0] = F[1][0] = 0, r = 1;
    for (long long k = 0; k < n; k++) F[i >> k & 1][++F[i >> k & 1][0]] = k;
    for (long long c1 = 1; c1 <= F[1][0]; c1++)
      for (long long c2 = 1; c2 <= F[0][0]; c2++)
        r = 1ll * r * a[F[1][c1]] % mod * iv[a[F[1][c1]] + a[F[0][c2]]] % mod;
    ans = (ans + 1ll * r * f[i] % mod * F[1][0]) % mod;
  }
  cout << ans << '\n';
  return 0;
}
