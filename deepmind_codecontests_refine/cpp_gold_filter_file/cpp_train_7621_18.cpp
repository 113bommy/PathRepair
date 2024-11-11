#include <bits/stdc++.h>
using namespace std;
inline int read() {
  register int x = 0, f = 1;
  register char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = 0;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + (ch ^ '0');
    ch = getchar();
  }
  return f ? x : -x;
}
const int mod = 998244353;
int n, l[55], r[55], inv[105], b[105], t, f[55][105], s[55][105];
inline void inc(int& x, int y) { x = x + y < mod ? x + y : x + y - mod; }
inline int power(int b, int n) {
  int ans = 1;
  for (; n; n >>= 1, b = 1ll * b * b % mod)
    if (n & 1) ans = 1ll * ans * b % mod;
  return ans;
}
int main() {
  n = read();
  for (int i = (1), _ed = (n); i <= _ed; ++i)
    l[i] = read(), r[i] = read(), b[++t] = l[i], b[++t] = ++r[i];
  inv[0] = inv[1] = 1;
  for (int i = (2), _ed = (n + n); i <= _ed; ++i)
    inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
  sort(b + 1, b + t + 1), t = unique(b + 1, b + t + 1) - b - 1;
  for (int i = (1), _ed = (n); i <= _ed; ++i)
    l[i] = lower_bound(b + 1, b + t + 1, l[i]) - b,
    r[i] = lower_bound(b + 1, b + t + 1, r[i]) - b;
  f[0][t] = s[0][t] = 1;
  for (int i = (1), _ed = (n + 1); i <= _ed; ++i)
    for (int j = (t - 1), _ed = (1); j >= _ed; --j) {
      s[i - 1][j] = (s[i - 1][j + 1] + f[i - 1][j]) % mod;
      if (l[i] > j || r[i] <= j) continue;
      int L = b[j + 1] - b[j], C = 1, cnt = 0;
      for (int k = (i - 1), _ed = (0); k >= _ed; --k) {
        ++cnt;
        C = 1ll * C * (L + cnt - 1) % mod * inv[cnt] % mod;
        inc(f[i][j], 1ll * s[k][j + 1] * C % mod);
        if (l[k] > j || r[k] <= j) break;
      }
    }
  int ans = s[n][1];
  for (int i = (1), _ed = (n); i <= _ed; ++i)
    ans = 1ll * ans * power(b[r[i]] - b[l[i]], mod - 2) % mod;
  printf("%d\n", ans);
  return 0;
}
