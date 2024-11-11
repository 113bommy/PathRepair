#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 7;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
long long n, f1, f2, f3, c;
struct mat {
  long long o[3][3];
  void clear() {
    for (long long i = 0; i < 3; ++i)
      for (long long j = 0; j < 3; ++j) o[i][j] = 0;
  }
  mat operator*(const mat& a) {
    mat res;
    res.clear();
    for (long long i = 0; i < 3; ++i)
      for (long long j = 0; j < 3; ++j)
        for (long long k = 0; k < 3; ++k)
          res.o[i][j] = (res.o[i][j] + o[i][k] * a.o[k][j]) % (mod);
    return res;
  }
} now;
mat matexp(mat x, long long y) {
  mat res;
  memset(res.o, 0, sizeof(res.o));
  res.o[0][0] = res.o[1][1] = res.o[2][2] = 1;
  while (y) {
    if (y & 1) res = res * x;
    y >>= 1;
    x = x * x;
  }
  return res;
}
long long exp_mod(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  scanf("%lld%lld%lld%lld%lld", &n, &f1, &f2, &f3, &c);
  f1 = f1 * c % mod;
  f2 = f2 * c % mod * c % mod;
  f3 = f3 * c % mod * c % mod * c % mod;
  now.clear();
  now.o[0][1] = now.o[1][2] = now.o[2][0] = now.o[2][1] = now.o[2][2] = 1;
  now = matexp(now, n - 3);
  long long ans = exp_mod(f1, now.o[2][0]) * exp_mod(f2, now.o[2][1]) % mod *
                  exp_mod(f3, now.o[2][2]) % mod;
  long long cx = exp_mod(c, n);
  ans = ans * exp_mod(cx, mod - 2) % mod;
  printf("%lld\n", ans);
  return 0;
}
