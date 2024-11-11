#include <bits/stdc++.h>
using namespace std;
int b[1000010][10], f[1000010], Tot[1000010], tot[1000010], c[1000010],
    vis[1000010];
int d[1000010];
int i, ans, n, x, now, j;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void write(int x) {
  if (x < 0) x = -x, putchar('-');
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
int main() {
  n = read();
  b[1][0] = b[1][1] = 1;
  f[0] = 1;
  for (i = 1; i <= n; i++) f[i] = 1ll * f[i - 1] * i % 1000000007, c[i] = n / i;
  c[1] = 1;
  int Max = 0;
  for (i = 1; i <= n; i++)
    if (!b[i][0])
      for (j = i; j <= n; j += i) b[j][0]++, b[j][b[j][0]] = i;
  for (i = 1; i <= n; i++) {
    d[i] = 1;
    for (j = 1; j <= b[i][0]; j++) {
      d[i] *= b[i][j];
      if (d[i] > n) break;
    }
    if (d[i] <= n) tot[d[i]]++;
  }
  for (i = 1; i <= n; i++) {
    x = read();
    if (x == 0) continue;
    if (d[x] <= n) tot[d[x]]--;
    if (b[x][0] != b[i][0]) {
      puts("0");
      return 0;
    }
    for (j = 1; j <= b[i][0]; j++) {
      if (c[b[i][j]] != c[b[x][j]]) {
        puts("0");
        return 0;
      }
      if (vis[b[x][j]]) {
        if (vis[b[x][j]] != b[i][j]) {
          puts("0");
          return 0;
        }
      } else
        vis[b[x][j]] = b[i][j];
    }
  }
  ans = 1;
  for (i = 1; i <= n; i++)
    if (b[i][1] == i && vis[i] == 0) Tot[c[i]]++;
  for (i = 1; i <= n; i++)
    if (Tot[i] + tot[i]) {
      x = 1ll * f[Tot[i]] * f[tot[i]] % 1000000007;
      ans = 1ll * ans * x % 1000000007;
    }
  write(ans);
}
