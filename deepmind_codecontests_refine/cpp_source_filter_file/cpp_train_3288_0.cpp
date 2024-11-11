#include <bits/stdc++.h>
using namespace std;
inline int read() {
  register int x = 0;
  register bool f = 0;
  register char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - 48;
    c = getchar();
  }
  return f ? -x : x;
}
char cr[200], str[200];
int tt;
inline void print(int x, char k = '\n') {
  if (!x) putchar('0');
  if (x < 0) putchar('-'), x = -x;
  while (x) cr[++tt] = x % 10 + '0', x /= 10;
  while (tt) putchar(cr[tt--]);
  putchar(k);
}
const int maxn = 510;
const long long inf = 1e18;
bitset<maxn> b[65][2][maxn], pre, tmp;
int n, m;
long long ans;
signed main() {
  n = read();
  m = read();
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read(), t = read();
    b[0][t][u][v] = 1;
  }
  for (int s = 1; s <= 60; s++)
    for (int j = 0; j < 2; j++)
      for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
          if (b[s - 1][j][u][v]) b[s][j][u] |= b[s - 1][j ^ 1][v];
  for (int i = 1; i <= n; i++) {
    if (b[60][0][1][i]) return printf("-1"), 0;
  }
  int t = 0;
  pre[1] = 1;
  for (int i = 59; i >= 0; i--) {
    tmp = 0;
    for (int j = 1; j <= n; j++)
      if (pre[j]) tmp |= b[i][t][j];
    if (tmp.count()) {
      pre = tmp;
      t ^= 1;
      ans += (1ll << i);
      if (ans > inf) return printf("-1"), 0;
    }
  }
  if (ans > inf) return printf("-1"), 0;
  print(ans);
  return 0;
}
