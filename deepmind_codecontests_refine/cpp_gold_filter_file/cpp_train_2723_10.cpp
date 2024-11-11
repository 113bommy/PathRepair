#include <bits/stdc++.h>
using namespace std;
inline int gi() {
  int data = 0, fu = 1;
  char ch = 0;
  while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
  if (ch == '-') fu = -1, ch = getchar();
  while ('0' <= ch && ch <= '9')
    data = (data << 1) + (data << 3) + (ch ^ 48), ch = getchar();
  return data * fu;
}
int n, m, A[200005], W0, W1, iW0, iW1, f[3005][3005], w[200005], ans[200005],
    inv[200005];
inline void add(int &x, int y) {
  x += y;
  if (x >= 998244353) x -= 998244353;
}
inline int Pow(int ts, int js) {
  int al = 1;
  while (js) {
    if (js & 1) al = 1ll * al * ts % 998244353;
    ts = 1ll * ts * ts % 998244353;
    js >>= 1;
  }
  return al;
}
int main() {
  n = gi();
  m = gi();
  for (int i = 1; i <= n; ++i) A[i] = gi();
  W0 = 0;
  W1 = 0;
  for (int i = 1; i <= n; ++i)
    if (A[i])
      w[i] = gi(), W1 += w[i];
    else
      w[i] = gi(), W0 += w[i];
  for (int i = -m; i <= m; ++i) inv[i + m] = Pow(W0 + W1 + i, 998244353 - 2);
  f[0][0] = 1;
  for (int i = 0; i < m; ++i)
    for (int j = 0; j <= i; ++j)
      if (f[i][j] && W0 - (i - j) >= 0) {
        add(f[i + 1][j + 1], 1ll * (W1 + j) * inv[m + j - (i - j)] % 998244353 *
                                 f[i][j] % 998244353);
        if (W0 - (i - j) - 1 >= 0)
          add(f[i + 1][j], 1ll * (W0 - (i - j)) * inv[m + j - (i - j)] %
                               998244353 * f[i][j] % 998244353);
      }
  iW0 = Pow(W0, 998244353 - 2);
  iW1 = Pow(W1, 998244353 - 2);
  for (int t = 0; t <= m; ++t)
    for (int i = 1; i <= n; ++i)
      if (!A[i]) {
        add(ans[i], 1ll * w[i] * iW0 % 998244353 * f[m][t] % 998244353 *
                        (m - t) % 998244353);
      } else
        add(ans[i],
            1ll * w[i] * iW1 % 998244353 * f[m][t] % 998244353 * t % 998244353);
  for (int i = 1; i <= n; ++i)
    if (!A[i])
      ans[i] = (w[i] - ans[i] + 998244353) % 998244353;
    else
      ans[i] = (ans[i] + w[i]) % 998244353;
  for (int i = 1; i <= n; ++i) printf("%d\n", ans[i]);
  return 0;
}
