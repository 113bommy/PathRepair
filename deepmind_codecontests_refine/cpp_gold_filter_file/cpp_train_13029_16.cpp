#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  bool flag = false;
  while (!isdigit(c)) {
    if (c == '-') flag = true;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  if (flag) x = -x;
}
long long n, m, s, s1, s2;
long long a[200010], w[200010], f[3010][3010], g[3010][3010];
long long inv(long long x) {
  long long v = 1, y = 998244353 - 2;
  while (y) {
    if (y & 1) v = v * x % 998244353;
    x = x * x % 998244353, y >>= 1;
  }
  return v;
}
int main() {
  read(n), read(m);
  for (int i = 1; i <= n; ++i) read(a[i]);
  for (int i = 1; i <= n; ++i) {
    read(w[i]), s += w[i];
    if (a[i])
      s1 += w[i];
    else
      s2 += w[i];
  }
  for (int i = m; i >= 0; --i) {
    f[i][m - i] = g[i][m - i] = 1;
    for (int j = min(s2, m - i - 1); j >= 0; --j) {
      long long iv = inv(s + i - j);
      f[i][j] = ((s1 + i + 1) * iv % 998244353 * f[i + 1][j] % 998244353 +
                 (s2 - j) * iv % 998244353 * f[i][j + 1] % 998244353) %
                998244353;
      g[i][j] = ((s1 + i) * iv % 998244353 * g[i + 1][j] % 998244353 +
                 (s2 - j - 1) * iv % 998244353 * g[i][j + 1] % 998244353) %
                998244353;
    }
  }
  for (int i = 1; i <= n; ++i)
    printf("%lld\n", w[i] * (a[i] ? f[0][0] : g[0][0]) % 998244353);
  return 0;
}
