#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 9, mod = 998244353;
inline long long read() {
  register long long x = 0, f = 1;
  register char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - 48, c = getchar();
  }
  return x * f;
}
long long n, inv[N], fac[N], ifac[N], ans;
char s[N];
void pre() {
  inv[0] = inv[1] = fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
  for (register long long i = (2); i <= (n); i++)
    inv[i] = inv[mod % i] * (mod - mod / i) % mod;
  for (register long long i = (2); i <= (n); i++) fac[i] = fac[i - 1] * i % mod;
  for (register long long i = (2); i <= (n); i++)
    ifac[i] = ifac[i - 1] * inv[i] % mod;
}
long long C(long long x, long long y) {
  if (x < 0 || y < 0 || x < y)
    return 0;
  else
    return fac[x] * ifac[y] * ifac[x - y] % mod;
}
signed main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  pre();
  long long l = 0, r = 0, x = 0, y = 0;
  for (register long long i = (n); i >= (1); i--) {
    if (s[i] == '?')
      r++;
    else if (s[i] == ')')
      y++;
  }
  for (register long long pos = (1); pos <= (n - 1); pos++) {
    if (s[pos] == '?')
      l++, r--;
    else if (s[pos] == ')')
      y--;
    else
      x++;
    ans = (ans + x * C(l + r, r + y - x) % mod +
           l * C(l + r - 1, r + y - x - 1) % mod) %
          mod;
  }
  printf("%lld\n", ans);
  return 0;
}
