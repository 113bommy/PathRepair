#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
long long mod;
long long add(long long x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
  return x;
}
long long mul(long long a, long long b) {
  long long r = (a * b - (long long)(((long double)a * b) / mod) * mod);
  return add(r - r / mod * mod, mod);
}
long long powt(long long a, long long b) {
  long long r = 1;
  while (b > 1) {
    if (b & 1) r = mul(r, a);
    a = mul(a, a);
    b >>= 1;
  }
  return r;
}
int f[] = {-1, 0, 1, 3, 2};
int main() {
  int t, n, m, i;
  long long a, b, x, k, phi;
  scanf("%d", &t);
  while (t--) {
    scanf("%lld", &a);
    n = to_string(a).size();
    for (m = 0, b = 1; 1; m++, a *= 10, b *= 10) {
      x = a;
      mod = 1LL << (n + m);
      if (x % mod) x += mod - x % mod;
      if (x % 5 == 0) x += mod;
      if (x % mod == 0 && x % 5 && x - a < b) {
        x >>= n + m;
        k = f[x % 5];
        for (i = 1, phi = 4, mod = 25; i < n + m; i++, mod *= 5, phi *= 5) {
          while (powt(2, k) != x % mod) k += phi;
        }
        printf("%lld\n", n + m + k);
        break;
      }
    }
  }
  return 0;
}
