#include <bits/stdc++.h>
using namespace std;
int n, q;
int a[300005];
const int B = 20;
int f[300005][B], lst[B];
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
    if (ch == -1) return 0;
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void write(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
signed main() {
  n = read(), q = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  memset(f, 0x3f, sizeof(f));
  for (int i = n; i >= 1; i--)
    for (int j = 0; j < B; j++)
      if (a[i] >> j & 1) {
        for (int k = 0; k < B; k++) f[i][k] = min(f[i][k], f[lst[j]][k]);
        f[i][j] = i, lst[j] = i;
      }
  while (q--) {
    int x, y, ans = 300005;
    x = read(), y = read();
    for (int i = 0; i < B; i++)
      if (a[y] >> i & 1) ans = min(ans, f[x][i]);
    puts(ans <= y ? "Shi" : "Fou");
  }
  return 0;
}
