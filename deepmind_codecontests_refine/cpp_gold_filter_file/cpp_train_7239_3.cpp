#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int s = 0;
  bool f = 0;
  char ch = ' ';
  while (!isdigit(ch)) {
    f |= (ch == '-');
    ch = getchar();
  }
  while (isdigit(ch)) {
    s = (s << 3) + (s << 1) + (ch ^ 48);
    ch = getchar();
  }
  return (f) ? (-s) : (s);
}
inline void write(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x < 10) {
    putchar(x + '0');
    return;
  }
  write(x / 10);
  putchar((x % 10) + '0');
}
const int N = 15;
int n, l[N][N], r[N][N], c[N][N], f[N], ans;
inline void dfs(int s, int t, int fl, int cost) {
  if (s == n) {
    ans = max(ans, cost);
    return;
  }
  if (t > n) {
    if (fl == 0) dfs(s + 1, s + 2, f[s + 1], cost);
  } else {
    int i;
    for (i = l[s][t]; i <= r[s][t] && i <= fl; ++i) {
      f[t] += i;
      dfs(s, t + 1, fl - i, cost + i * i + (i ? c[s][t] : 0));
      f[t] -= i;
    }
  }
}
int main() {
  int i, u, v, p, q, cc;
  n = read();
  for (i = 1; i <= n * (n - 1) / 2; i++) {
    u = read();
    v = read();
    p = read();
    q = read();
    cc = read();
    l[u][v] = p;
    r[u][v] = q;
    c[u][v] = cc;
  }
  for (i = 0; i <= 25; i++) {
    ans = -1;
    dfs(1, 2, i, 0);
    if (ans >= 0) {
      write(i), putchar(' ');
      write(ans), putchar('\n');
      return 0;
    }
  }
  write(-1), putchar(' ');
  puts("-1");
  return 0;
}
