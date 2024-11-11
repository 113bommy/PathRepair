#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
#pragma GCC target("avx")
using namespace std;
inline char gc() {
  static char buf[1 << 16], *p1 = buf, *p2 = buf;
  if (p1 == p2) {
    p2 = (p1 = buf) + fread(buf, 1, 1 << 16, stdin);
    if (p2 == p1) return EOF;
  }
  return *p1++;
}
template <class t>
inline t read(t &x) {
  char c = gc();
  bool f = 0;
  x = 0;
  while (!isdigit(c)) f |= c == '-', c = gc();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = gc();
  if (f) x = -x;
  return x;
}
template <class t>
inline void write(t x) {
  if (x < 0)
    putchar('-'), write(-x);
  else {
    if (x > 9) write(x / 10);
    putchar('0' + x % 10);
  }
}
const int N = 1005;
int sz[N], l[N], r[N], n, m, op, val[2][N][N], f[N];
vector<int> g[N];
void dfs(int x) {
  sz[x] = x != 1;
  for (int y : g[x]) {
    dfs(y);
    sz[x] += sz[y];
    l[x] = min(l[x], l[y]);
    r[x] = max(r[x], r[y]);
  }
  val[op][l[x]][r[x]] = max(val[op][l[x]][r[x]], sz[x]);
}
signed main() {
  read(n);
  for (; op <= 1; op++) {
    read(m);
    for (int i = 1; i <= m; i++) l[i] = m + 1, r[i] = 0, g[i].clear();
    for (int i = 2, x; i <= m; i++) g[read(x)].push_back(i);
    for (int i = 1, x; i <= n; i++) {
      read(x);
      l[x] = r[x] = i;
    }
    dfs(1);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++)
      f[i] = max(f[i], f[j - 1] + max(val[0][j][i], val[1][j][i]));
  ;
  write(f[n]);
}
