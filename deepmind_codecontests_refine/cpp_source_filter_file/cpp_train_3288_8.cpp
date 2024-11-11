#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
const long long MX = 1000000000000;
int n, m;
bitset<maxn> f[2][75][maxn], p, tmp;
long long ans;
inline int read() {
  int res = 0, f_f = 1;
  int ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f_f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    res = (res << 3) + (res << 1) + (ch - '0'), ch = getchar();
  return res * f_f;
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read(), tp = read();
    f[tp][0][x][y] = 1;
  }
  for (int i = 1; i <= 64; i++)
    for (int u = 1; u <= n; u++)
      for (int k = 1; k <= n; k++) {
        if (f[0][i - 1][u][k]) f[0][i][u] |= f[1][i - 1][k];
        if (f[1][i - 1][u][k]) f[1][i][u] |= f[0][i - 1][k];
      }
  int cur = 0;
  for (int i = 1; i <= n; i++) p[i] = 1;
  for (int i = 62; ~i; i--) {
    for (int j = 1; j <= n; j++) tmp[j] = 0;
    for (int u = 1; u <= n; u++)
      if (p[u]) tmp |= f[cur][i][u];
    if (tmp.count()) cur ^= 1, p = tmp, ans |= 1ll << i;
  }
  if (ans > MX)
    printf("-1\n");
  else
    printf("%lld\n", ans);
  return 0;
}
