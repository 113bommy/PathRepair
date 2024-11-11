#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, mod = 1e9 + 7;
int la, lb, a, b, c, d;
char A[N], B[N];
long long fac[N], ifac[N];
void up(long long &x, long long y) { x = (x + y) % mod; }
long long upm(long long x) { return x >= mod ? x % mod : x; }
long long qpow(long long x, long long y) {
  long long res = 1;
  for (; y; y >>= 1, x = x * x % mod)
    if (y & 1) res = res * x % mod;
  return res;
}
long long C(int x, int y) {
  if (y < 0 || y > x) return 0;
  return fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
void init() {
  fac[0] = 1;
  for (int i = 1; i < N; ++i) fac[i] = fac[i - 1] * i % mod;
  ifac[N - 1] = qpow(fac[N - 1], mod - 2);
  for (int i = N - 2; ~i; --i) ifac[i] = ifac[i + 1] * (i + 1) % mod;
}
long long calc(int a, int b, int c, int d, int n) {
  if (a < 0 || b < 0 || c < 0 || d < 0) return 0;
  if (b ^ c && b ^ (c + 1)) return 0;
  if ((a + b + c + d + 1) ^ n) return 0;
  return C(a + 1 + (c + 1) - 2, (c + 1) - 1) *
         ((!d && !b) ? 1 : C(d + 1 + b - 2, b - 1)) % mod;
}
long long solve(char *s, int n) {
  long long res = 0;
  if (!a && !b && !c && !d) ++res;
  for (int i = 1; i < n; ++i) up(res, calc(d, c, b, a, i));
  int ta = a, tb = b, tc = c, td = d;
  for (int i = 1; i < n; ++i) {
    if (s[i] == '0') {
      if (s[i - 1] == '1')
        --tc;
      else
        --ta;
    } else {
      if (s[i - 1] == '1')
        up(res, calc(ta, tb, tc - 1, td, n - i)), --td;
      else
        up(res, calc(ta - 1, tb, tc, td, n - i)), --tb;
    }
  }
  if (ta | tb | tc | td)
    return res;
  else
    return upm(res + 1);
}
int main() {
  scanf("%s%s", A, B);
  la = strlen(A);
  lb = strlen(B);
  scanf("%d%d%d%d", &a, &b, &c, &d);
  int p;
  for (p = la - 1; ~p; --p)
    if (A[p] == '1') break;
  if (!p) {
    --la;
    for (int i = 0; i < la; ++i) A[i] = '1';
  } else {
    A[p] = '0';
    for (int i = p + 1; i < la; ++i) A[i] = '1';
  }
  init();
  printf("%lld\n", (solve(B, lb) - solve(A, la) + mod) % mod);
  return 0;
}
