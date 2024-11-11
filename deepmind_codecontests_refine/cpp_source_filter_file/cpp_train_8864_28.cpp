#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
const int N = 200010, M = 500010;
int n, m, k, x, y, ans, a[M], f[M][21];
inline void mian() {
  n = read();
  m = read();
  for (int i = 1; i <= n; ++i) {
    x = read();
    y = read();
    a[x] = max(a[x], y);
    k = max(k, y);
  }
  for (int i = 1; i <= k; ++i) f[i][0] = a[i] = max(a[i], a[i - 1]);
  for (int i = 1; i <= 20; ++i)
    for (int j = 1; j <= k; ++j) f[j][i] = f[f[j][i - 1]][i - 1];
  while (m--) {
    x = read();
    y = read();
    ans = 0;
    for (int i = 20; i >= 0; --i)
      if (f[x][i] < y) {
        ans += 1 << i;
        x = f[x][i];
      }
    if (a[x] < y)
      puts("-1");
    else
      printf("%d\n", ans + 1);
  }
}
int main() {
  int qwq = 1;
  while (qwq--) mian();
  return 0;
}
