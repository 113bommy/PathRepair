#include <bits/stdc++.h>
inline long long read() {
  long long x = 0;
  char c = getchar(), f = 1;
  for (; c < '0' || '9' < c; c = getchar())
    if (c == '-') f = -1;
  for (; '0' <= c && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  return x * f;
}
inline void write(long long x) {
  static char buf[20];
  int len = 0;
  if (x < 0) putchar('-'), x = -x;
  for (; x; x /= 10) buf[len++] = x % 10 + '0';
  if (!len)
    putchar('0');
  else
    while (len) putchar(buf[--len]);
}
inline void writesp(long long x) {
  write(x);
  putchar(' ');
}
inline void writeln(long long x) {
  write(x);
  putchar('\n');
}
struct edge {
  int to, nxt;
} e[2 * 200010];
int fir[200010], a[200010], full[200010], f[200010];
int n, m, tot;
inline void add_edge(int x, int y) {
  e[tot].to = y;
  e[tot].nxt = fir[x];
  fir[x] = tot++;
}
int dfs(int now, int fa, int mid) {
  full[now] = (a[now] >= mid);
  int delta = 1, mx1 = 0, mx2 = 0, ret = 0;
  for (int i = fir[now]; ~i; i = e[i].nxt)
    if (e[i].to != fa) {
      ret = std::max(ret, dfs(e[i].to, now, mid));
      if (full[e[i].to])
        delta += f[e[i].to];
      else if (f[e[i].to] > mx1)
        mx2 = mx1, mx1 = f[e[i].to];
      else if (f[e[i].to] > mx2)
        mx2 = f[e[i].to];
      full[now] &= full[e[i].to];
    }
  if (a[now] >= mid) {
    ret = std::max(ret, mx1 + mx2 + delta);
    f[now] = mx1 + delta;
  } else
    f[now] = 0;
  return ret;
}
int main() {
  n = read();
  m = read();
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    mx = std::max(mx, i);
  }
  int mnid = 1;
  for (int i = 2; i <= n; i++)
    if (a[i] < a[mnid]) mnid = i;
  memset(fir, 255, sizeof(fir));
  tot = 0;
  for (int i = 1; i < n; i++) {
    int x = read(), y = read();
    add_edge(x, y);
    add_edge(y, x);
  }
  int l = 1, r = mx;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (dfs(mnid, -1, mid) >= m)
      l = mid;
    else
      r = mid - 1;
  }
  writeln(l);
  return 0;
}
