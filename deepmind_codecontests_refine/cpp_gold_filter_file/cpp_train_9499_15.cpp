#include <bits/stdc++.h>
using namespace std;
int read() {
  int s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
  return s * w;
}
int n, o[5010][5010], fac[5010], inf[5010];
int ksm(int x, int y) {
  int r = 1;
  while (y)
    y& 1 ? r = 1ll * r * x % 998244353 : 0, x = 1ll * x * x % 998244353,
           y >>= 1;
  return r;
}
signed main() {
  n = read();
  o[0][0] = fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % 998244353;
  inf[n] = ksm(fac[n], 998244353 - 2);
  for (int i = n - 1; ~i; i--) inf[i] = 1ll * inf[i + 1] * (i + 1) % 998244353;
  for (int i = 1; i <= n; o[i][0] = 1, i++)
    for (int j = 1; j <= i; j++)
      o[i][j] =
          (1ll * o[i - 1][j] * (j + 1) + 1ll * (i - j) * o[i - 1][j - 1]) %
          998244353;
  for (int i = 1, ans; ans = 0, i <= n; cout << ans << ' ', i++)
    for (int j = 1; j <= n; j++)
      ans = (ans + 1ll * o[j][i - 1] * fac[n] % 998244353 * inf[j]) % 998244353;
  return 0;
}
