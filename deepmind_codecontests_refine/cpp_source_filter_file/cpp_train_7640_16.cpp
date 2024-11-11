#include <bits/stdc++.h>
long long f[2 * 100000 + 1], fi[2 * 100000 + 1];
void gcdEx(long long a, long long b, long long& x, long long& y, long long& g) {
  if (!b) {
    x = 1;
    y = 0;
    g = a;
    return;
  }
  gcdEx(b, a % b, x, y, g);
  long long x1 = y;
  long long y1 = x - (a / b) * y;
  x = x1;
  y = y1;
}
long long inverse(long long a, long long mod) {
  long long x, y, g;
  gcdEx(a, mod, x, y, g);
  return (x + mod) % mod;
}
void calc() {
  f[0] = fi[0] = 1;
  for (int i = 1; i <= 2 * 100000; ++i)
    f[i] = (i * f[i - 1]) % 1000000007LL,
    fi[i] = (inverse(i, 1000000007LL) * fi[i - 1]) % 1000000007LL;
}
long long mod(long long v) { return v % 1000000007LL; }
int main() {
  calc();
  int z, o, d;
  scanf("%d%d%d", &z, &o, &d);
  long long ans = 0;
  while (1) {
    if (d) {
      if (z)
        d = 0, --z;
      else {
        ans = mod(ans + (o == 1));
        break;
      }
    }
    if (o && (o - 1 + z)) {
      ans += mod(mod(f[o - 1 + z] * fi[o - 1]) * fi[z]);
      ans %= 1000000007LL;
    }
    if (z) {
      if (z == 1) {
        ans = mod(ans + (o == 0));
        break;
      } else
        --z, d = 1;
    } else
      break;
  }
  printf("%d\n", (int)ans);
  return 0;
}
