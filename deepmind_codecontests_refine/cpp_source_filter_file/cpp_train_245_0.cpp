#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, fl = 1;
  char st = getchar();
  while (st < '0' || st > '9') {
    if (st == '-') fl = -1;
    st = getchar();
  }
  while (st >= '0' && st <= '9') x = x * 10 + st - '0', st = getchar();
  return x * fl;
}
const int N = 1e6 + 10, mod = 1e9 + 9;
int n, b, w;
long long ans, fac[8005], invfac[8005];
inline long long ksm(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return res;
}
inline long long C(int x, int y) {
  return fac[x] * invfac[y] % mod * invfac[x - y] % mod;
}
int main() {
  ans = 1;
  n = read();
  w = read();
  b = read();
  fac[0] = 1;
  fac[1] = 1;
  for (int i = 2; i <= 8000; i++) fac[i] = fac[i - 1] * i % mod;
  invfac[0] = invfac[1] = 1;
  invfac[8000] = ksm(fac[8000], mod - 2);
  for (int i = 7999; i >= 2; i--) {
    invfac[i] = invfac[i + 1] * (i + 1) % mod;
  }
  ans = fac[w] * fac[b] % mod;
  ans = ans * (w - 1) % mod;
  ans = ans * C(w + b - 3, n - 3);
  printf("%lld", ans);
  return 0;
}
