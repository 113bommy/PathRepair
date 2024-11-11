#include <bits/stdc++.h>
using namespace std;
char s[100001];
long long mod = 1e9 + 9;
long long Mul(long long a, long long b, long long mod) {
  long long res = 0;
  while (b > 0) {
    if (b & 1) res = (res + a) % mod;
    b >>= 1;
    a = (a + a) % mod;
  }
  return res;
}
long long modxp(long long a, long long b, long long mod) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = Mul(res, a, mod);
    b >>= 1;
    a = Mul(a, a, mod);
  }
  return res;
}
void extgcd(long long a, long long b, long long& d, long long& x,
            long long& y) {
  if (!b) {
    d = a;
    x = 1;
    y = 0;
  } else {
    extgcd(b, a % b, d, y, x);
    y -= x * (a / b);
  }
}
long long inverse(long long a, long long n) {
  long long d = 0, x = 0, y = 0;
  extgcd(a, n, d, x, y);
  return d == 1 ? (x + n) % n : -1;
}
int main() {
  int n, a, b, k;
  scanf("%d%d%d%d", &n, &a, &b, &k);
  scanf("%s", s);
  long long tmpa = modxp(a, mod - 2, mod), tmpb = modxp(b, mod - 2, mod);
  long long q = modxp(b, k, mod) * modxp(tmpa, k, mod);
  long long now = modxp(a, n, mod);
  long long ans = 0;
  for (int i = 0; i < k; i++) {
    if (s[i] == '+')
      ans += now % mod;
    else
      ans -= now % mod;
    ans = (ans % mod + mod) % mod;
    now = now * tmpa % mod * b % mod;
  }
  long long nn = (n + 1) / k;
  if (q != 1) {
    ans = ans * ((1 - modxp(q, nn, mod)) % mod + mod) % mod *
          modxp(((1 - q) % mod + mod) % mod, mod - 2, mod) % mod;
  } else
    ans = ans * ans * q % mod;
  printf("%lld\n", ans);
  return 0;
}
