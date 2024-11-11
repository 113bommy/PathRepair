#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long inff = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-9;
const int maxn = 5e3 + 5;
int a[maxn], c[maxn];
long long qp(long long base, long long n) {
  base %= mod;
  long long res = 1;
  while (n) {
    if (n & 1) (res *= base) %= mod;
    (base *= base) %= mod;
    n >>= 1;
  }
  return res;
}
int main() {
  int n, k;
  scanf("%d%d", &(n), &(k));
  for (int i = (1); i <= (int)(n); ++i) scanf("%d", &(a[i]));
  int deg = 1;
  c[0] = 1;
  for (int i = (1); i <= (int)(n); ++i) {
    for (int j = (deg); j >= (int)(0); --j)
      c[j] =
          (1LL * a[i] * c[j] % mod - (j == 0 ? 0 : c[j - 1]) % mod + mod) % mod;
    deg++;
  }
  int _n = qp(n, mod - 2), ans = 1, g = 1, gk = 1;
  for (int i = (1); i <= (int)(n); ++i) ans = 1LL * ans * a[i] % mod;
  for (int i = (0); i <= (int)(min(k, deg - 1)); ++i)
    ans = (ans - 1LL * g * gk % mod * c[i] % mod + mod) % mod,
    g = 1LL * g * _n % mod, gk = 1LL * gk * (k - i) % mod;
  printf("%d\n", ans);
  return ~~(0 - 0);
}
