#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
const long long N = 15;
const long long M = 2e6 + 5;
const long long SZ = 550;
const double eps = 1e-9;
const long long mod = 1e9 + 7;
const long long inf = 0x3f3f3f3f3f3f3f;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
void wt(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x >= 10) wt(x / 10), putchar(10);
  putchar(x % 10 + '0');
}
long long ksm(long long x, long long y = mod - 2, long long z = mod) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = (ret * x) % z;
    x = (x * x) % z;
    y >>= 1;
  }
  return ret;
}
long long inv[M], fac[M], ifc[M];
void Init(long long n) {
  inv[1] = 1;
  for (long long i = 2; i <= n; i++)
    inv[i] = 1ll * inv[mod % i] * (mod - mod / i) % mod;
  fac[0] = 1;
  for (long long i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifc[0] = 1;
  for (long long i = 1; i <= n; i++) ifc[i] = 1ll * ifc[i - 1] * inv[i] % mod;
}
long long C(long long n, long long m) {
  if (m < 0 || m > n) return 0;
  return 1ll * fac[n] * ifc[m] % mod * ifc[n - m] % mod;
}
long long n, ans;
long long a[N], g[N][N];
long long f[1 << 14];
vector<long long> v1, v2;
signed main() {
  Init(M - 1);
  n = read();
  for (long long i = 0; i < n; i++) a[i] = read();
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < n; j++) g[i][j] = a[i] * inv[a[i] + a[j]] % mod;
  for (long long S = 1; S < (1 << n); S++) {
    f[S] = 1;
    for (long long T = (S - 1) & S; T; T = (T - 1) & S) {
      long long X = S - T;
      v1.clear();
      v2.clear();
      for (long long i = 0; i < n; i++) {
        if (T >> i & 1) v1.push_back(i);
        if (X >> i & 1) v2.push_back(i);
      }
      long long P = 1;
      for (long long i : v1)
        for (long long j : v2) P = P * g[i][j] % mod;
      f[S] = (f[S] - P * f[T] % mod + mod) % mod;
    }
  }
  for (long long S = 1; S < (1 << n); S++) {
    v1.clear();
    v2.clear();
    for (long long i = 0; i < n; i++)
      if (S >> i & 1)
        v1.push_back(i);
      else
        v2.push_back(i);
    long long P = 1;
    for (long long i : v1)
      for (long long j : v2) P = P * g[i][j] % mod;
    ans = (ans + P * f[S] % mod * v1.size()) % mod;
  }
  cout << (ans + mod) % mod << "\n";
}
