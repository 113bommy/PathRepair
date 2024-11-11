#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool GetMin(T &a, T b) {
  return ((a <= b) ? false : (a = b, true));
}
template <typename T>
bool GetMax(T &a, T b) {
  return ((a >= b) ? false : (a = b, true));
}
const long long N = 233;
const long long SX = 2333 + 10;
const long long MOD = 1e9 + 7;
long long n, x[N], y[N], C[SX][SX], jc[SX], njc[SX];
long long f[SX], g[SX];
long long Qpow(long long x, long long y = MOD - 2) {
  long long res = 1;
  for (; y; y >>= 1, x = x * x % MOD)
    if (y & 1) res = res * x % MOD;
  return res;
}
void Prework() {
  for (long long i = 0; i < SX; ++i) {
    C[i][0] = 1;
    for (long long j = 1; j <= i; ++j)
      if ((C[i][j] = C[i - 1][j - 1] + C[i - 1][j]) >= MOD) C[i][j] -= MOD;
  }
  jc[0] = 1;
  for (long long i = 1; i < SX; ++i) jc[i] = jc[i - 1] * i % MOD;
  njc[SX - 1] = Qpow(jc[SX - 1]);
  for (long long i = SX - 2; i >= 0; --i) njc[i] = njc[i + 1] * (i + 1) % MOD;
}
signed main() {
  Prework();
  scanf("%lld", &n);
  for (long long i = 1; i <= n; ++i) scanf("%lld", x + i);
  for (long long i = 1; i <= n; ++i) scanf("%lld", y + i);
  f[0] = 1;
  for (long long k = 1; k <= n; ++k) {
    memset(g, 0, sizeof g);
    for (long long i = x[k]; i < SX; ++i) g[i] = f[i - x[k]];
    memset(f, 0, sizeof f);
    for (long long i = 0; i <= y[k]; ++i)
      for (long long j = i; j < SX; ++j)
        if (g[j])
          if ((f[j - i] += g[j] * C[j][i] % MOD) >= MOD) f[j - i] -= MOD;
  }
  long long sm = 0;
  for (long long i = 1; i <= n; ++i) sm += x[i];
  long long ans = f[0] * jc[sm] % MOD;
  for (long long i = 1; i <= n; ++i) ans = ans * njc[x[i]] % MOD;
  printf("%lld", ans);
  return 0;
}
