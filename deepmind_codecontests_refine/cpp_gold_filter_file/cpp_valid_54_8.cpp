#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast", "-funroll-all-loops", "-ffast-math")
#pragma GCC target("avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long Linf = 0x7f7f7f7f7f7f7f7f;
const long long Inf = 0x3f3f3f3f;
const long long MAXN = 1e6;
const long long P = 1e9 + 7;
long long qpow(long long a, long long b) {
  long long res = 1;
  a %= P;
  while (b) {
    if (b & 1) res = res * a % P;
    a = 1ll * a * a % P;
    b >>= 1;
  }
  return res % P;
}
long long fac[MAXN], inv[MAXN];
long long C(long long n, long long m) {
  return ((1ll * fac[n] * inv[n - m] % P) * inv[m]) % P;
}
long long n, m, dp[MAXN][2];
void doit() {
  cin >> n >> m;
  long long res1 = 0, res0 = 0;
  for (long long i = 0; i < n; i++) {
    if (i & 1)
      (res1 += C(n, i)) %= P;
    else
      (res0 += C(n, i)) %= P;
  }
  long long ans = 0;
  if (n & 1) {
    (ans = qpow(1 + res0, m)) %= P;
  } else {
    long long mul = 1;
    ans = 0;
    for (long long i = m; i >= 1; i--, (mul *= res0) %= P) {
      long long tp = qpow(qpow(2, i - 1), n);
      (ans += mul * tp % P) %= P;
    }
    (ans += mul) %= P;
  }
  cout << ans % P << '\n';
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  fac[0] = 1;
  inv[0] = 1;
  for (long long i = 1; i < MAXN; i++) fac[i] = 1ll * fac[i - 1] * i % P;
  for (long long i = 1; i < MAXN; i++) inv[i] = qpow(fac[i], P - 2);
  long long _;
  cin >> _;
  while (_--) doit();
  return 0;
}
