#include <bits/stdc++.h>
using namespace std;
const int mo = 1e6 + 3;
long long n, k, tot;
int mol, den, tmp;
long long mul(long long x, long long y) {
  long long ret = 1;
  x %= mo;
  while (y) {
    if (y % 2) ret = 1LL * ret * x % mo;
    y /= 2;
    x = 1LL * x * x % mo;
  }
  return ret;
}
int main() {
  scanf("%I64d%I64d", &n, &k);
  if (n < 63) {
    long long a = 1;
    for (int i = 1; i <= n; i++) a *= 2;
    if (a < k) {
      printf("1 1\n");
      return 0;
    }
  }
  long long kk = k - 1;
  tot = n;
  while (kk > 1) tot += (kk /= 2);
  mol = den = mul(2, (1LL * (n % (mo - 1)) * (k % (mo - 1)) % (mo - 1) -
                      tot % (mo - 1) + mo - 1) %
                         (mo - 1));
  int l = (mul(2, n % (mo - 1)) - k + 1 + mo) % mo;
  tmp = 1;
  for (long long i = 1; i <= k; i++) {
    tmp = 1LL * tmp * l % mo;
    if (!tmp) break;
    l = (l + 1) % mo;
  }
  tmp = 1LL * tmp * mul(mul(2, tot % (mo - 1)), mo - 2) % mo;
  mol = (mol - tmp + mo) % mo;
  printf("%d %d\n", mol, den);
  return 0;
}
