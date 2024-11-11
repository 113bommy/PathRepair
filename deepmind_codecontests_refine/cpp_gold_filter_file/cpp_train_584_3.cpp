#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1, c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return f == 1 ? x : -x;
}
inline long long ksm(long long x, long long r, long long mod) {
  long long ret = 1;
  for (long long i = 0; (1ll << i) <= r; i++) {
    if ((r >> i) & 1) ret = (__int128)ret * x % mod;
    x = (__int128)x * x % mod;
  }
  return ret;
}
inline void solve() {
  long long a = read(), b, x = a, xm = 1, n = 0, m, w, g, pw, phi;
  while (x) {
    x /= 10;
    ++n;
  }
  for (m = 0;; m++, a *= 10, xm *= 10) {
    b = (-a) & ((1ll << (n + m)) - 1);
    if ((a + b) % 5 == 0) b += 1ll << (n + m);
    if (b >= xm) continue;
    w = (a + b) >> (n + m);
    for (long long i = 0; i < 5; i++)
      if (ksm(2, i, 5) == w % 5) {
        g = i;
        break;
      }
    phi = 4;
    pw = 5;
    for (long long T = 2; T <= n + m; T++) {
      pw *= 5;
      for (long long i = 0; i < 5; i++)
        if (ksm(2, g + i * phi, pw) == w % pw) {
          g += i * phi;
          break;
        }
      phi *= 5;
    }
    cout << g + n + m << "\n";
    break;
  }
}
signed main() {
  for (long long T = read(); T--;) solve();
  return (0 - 0);
}
