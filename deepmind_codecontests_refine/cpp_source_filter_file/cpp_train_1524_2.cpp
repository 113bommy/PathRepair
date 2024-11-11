#include <bits/stdc++.h>
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
using namespace std;
inline long long maxx(long long a, long long b) { return (a < b ? b : a); }
inline long long minn(long long a, long long b) { return (a > b ? b : a); }
using namespace std;
const int maxn = 1000500, mod = 1000000007;
inline int che(int a) { return a >= mod ? a - mod : a; }
inline int sub(int a, int b) { return che(a - b + mod); }
int f[maxn], inc[maxn], fac[maxn];
inline int ksm(int a, int b) {
  int res = 1;
  for (; b; b >>= a, a = 1ll * a * a % mod)
    if (b & 1) res = 1ll * res * a % mod;
  return res;
}
inline int C(int n, int m) {
  return 1ll * fac[n] * inc[m] % mod * inc[n - m] % mod;
}
int main() {
  register int n, k;
  scanf("%d %d", &n, &k);
  fac[0] = 1;
  for (register int i = 1; i <= n; ++i) fac[i] = 1ll * fac[i - 1] * i % mod;
  inc[n] = ksm(fac[n], mod - 2);
  for (register int i = n; i; --i) inc[i - 1] = 1ll * inc[i] * i % mod;
  register int sum = 1, ans = 0;
  f[0] = 1;
  for (register int i = 1; i <= n; i++) {
    f[i] = 1ll * sum * fac[i - 1] % mod;
    if (i - k >= 0) sum = sub(sum, 1ll * f[i - k] * inc[i - k] % mod);
    sum = (sum + 1ll * f[i] * inc[i]) % mod;
    ans = (ans + 1ll * f[i - 1] * C(n - 1, n - i) % mod * fac[n - i]) % mod;
  }
  printf("%d\n", sub(fac[n], ans));
  return 0;
}
