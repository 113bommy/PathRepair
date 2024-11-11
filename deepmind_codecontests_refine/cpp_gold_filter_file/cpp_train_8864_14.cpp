#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, w = 0;
  char ch = getchar();
  while (!isdigit(ch)) w |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
  return w ? -x : x;
}
int n, m, to[560000], f[560000][22], mx;
signed main() {
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) {
    int x = read(), y = read();
    to[x] = max(to[x], y);
    mx = max(mx, y);
  }
  for (int i = 0; i <= mx; ++i) f[i][0] = to[i] = max(to[i], to[i - 1]);
  for (int j = 1; j <= 20; ++j)
    for (int i = 0; i <= mx; ++i) f[i][j] = f[f[i][j - 1]][j - 1];
  while (m--) {
    int x = read(), y = read(), ans = 0;
    for (int i = 20; i >= 0; --i) {
      if (f[x][i] < y && f[x][i] > x) x = f[x][i], ans += (1 << i);
    }
    if (to[x] >= y)
      printf("%d\n", ans + 1);
    else
      puts("-1");
  }
  return 0;
}
