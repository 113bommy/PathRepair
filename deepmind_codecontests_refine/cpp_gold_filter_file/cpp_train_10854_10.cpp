#include <bits/stdc++.h>
using namespace std;
inline int read() {
  register int x = 0, f = 1;
  register char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
  return x * f;
}
inline int qpow(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = 1ll * r * a % 998244353;
    a = 1ll * a * a % 998244353, b >>= 1;
  }
  return r;
}
int ans, pax, pay;
int n, m, inv[4000006];
signed main() {
  n = read(), m = read(), inv[1] = 1;
  for (register int i = (2); i <= (n + m); ++i)
    inv[i] = 1ll * (998244353 - 998244353 / i) * inv[998244353 % i] % 998244353;
  for (register int i = (1); i <= (n); ++i) ans = (ans + inv[i]) % 998244353;
  pax = pay = 1;
  for (register int i = (1); i <= (n); ++i) {
    pay = 1ll * pay * (n - i + 1) % 998244353 * inv[n + m - i + 1] % 998244353;
    pax = (pax + 1ll * pay * m % 998244353 * inv[n + m - i] % 998244353 * i %
                     998244353) %
          998244353;
  }
  ans = 1ll * (1ll * m * ans + 1) % 998244353 * pax % 998244353;
  cout << ans;
  return 0;
}
