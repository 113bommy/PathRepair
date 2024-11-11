#include <bits/stdc++.h>
using namespace std;
int n, T, m = 6;
inline long long mul(long long x, long long y, long long mod) {
  long long res = 0;
  while (y) {
    if (y & 1) res = (res + x) % mod;
    x = (x + x) % mod;
    y >>= 1;
  }
  return res;
}
inline long long power(long long x, long long y, long long mod) {
  long long res = 1;
  while (y) {
    if (y & 1) res = mul(res, x, mod);
    x = mul(x, x, mod);
    y >>= 1;
  }
  return res;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    long long a, b;
    cin >> a;
    n = (int)to_string(a).length();
    a *= 1000000;
    b = (-a) & ((1ll << (n + m)) - 1);
    if ((a + b) % 5 == 0) b += (1ll << (n + m));
    long long x = (a + b) >> (n + m), d = 0, p = 5, phi = 4;
    for (register int i = 0; i <= 4; i++)
      if (power(2, i, p) == x % p) {
        d = i;
        break;
      }
    for (register int i = 1; i <= n + m - 1; i++) {
      p = p * 5;
      for (int j = 0;; j++)
        if (power(2, d + phi * j, p) == x % p) {
          d = d + phi * j;
          break;
        }
      phi = phi * 5;
    }
    cout << n + m + d << endl;
  }
}
