#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z, w, cyc;
long long a, b, p, k, tmp, ans;
int v[1000005];
long long f(long long x, int y, long long mod) {
  if (y == 0)
    return 1ll % mod;
  else {
    long long tmp = f(x, y / 2, mod);
    tmp = tmp * tmp % mod;
    if (y % 2 == 1) tmp = tmp * x % mod;
    return tmp;
  }
}
long long extend_gcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long gcd = extend_gcd(b, a % b, x, y);
  long long tmp = x;
  x = y;
  y = tmp - a / b * x;
  return gcd;
}
long long solve(long long a1, long long b1, long long a2, long long b2,
                long long k) {
  long long x, y;
  long long gcd = extend_gcd(a1, a2, x, y);
  long long t = a2 / gcd;
  x = (x * (b2 - b1)) / gcd;
  x = (x % t + t) % t;
  long long bx = a1 * x + b1;
  long long ax = (a1 * a2) / gcd;
  bx = (bx % ax + ax) % ax;
  long long res;
  if (k < bx)
    res = 0ll;
  else
    res = (k - bx) / ax + 1 - (bx == 0 ? 1 : 0);
  return res;
}
int main() {
  scanf("%lld %lld %lld %lld", &a, &b, &p, &k);
  for (int i = (0); i <= (p); i++) v[i] = -1;
  for (int i = (0); i < (p); i++) {
    tmp = f(a, i, p);
    if (v[(int)tmp] == -1)
      v[(int)tmp] = i;
    else {
      cyc = i;
      break;
    }
  }
  for (int i = (0); i < (p); i++) {
    if (v[i] == -1) continue;
    tmp = b * f(i, (int)p - 2, p) % p;
    ans += solve(1ll * cyc, 1ll * v[i], p, tmp, k);
  }
  printf("%lld\n", ans);
  return 0;
}
