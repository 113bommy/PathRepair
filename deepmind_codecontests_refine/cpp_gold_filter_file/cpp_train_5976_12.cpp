#include <bits/stdc++.h>
using namespace std;
const long long inf = INT_MAX, df = 3e5 + 7;
struct edge {
  long long to, nxt;
} e[df << 2];
long long i, j, k, l, m, n, o = 1, p, q, r, s, t, u, v, w, x, y, z, vis[df],
                            head[df], siz[df], rt, opg, mn = inf, all, fa[df];
inline void add(long long u, long long v) {
  e[++o] = (edge){v, head[u]}, head[u] = o;
  return;
}
char ans[df];
inline long long read() {
  long long x = 0, y = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') y = (ch == '-') ? -1 : 1, ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return x * y;
}
void getrt(long long u, long long faa) {
  siz[u] = 1;
  long long mx = 0;
  fa[u] = faa;
  for (long long i = head[u], v; i; i = e[i].nxt) {
    v = e[i].to;
    if (v == faa || vis[v]) continue;
    getrt(v, u);
    siz[u] += siz[v];
    mx = max(mx, siz[v]);
  }
  mx = max(mx, all - siz[u]);
  if (mx < mn) mn = mx, rt = u;
}
void solve(long long u, long long dep) {
  ans[u] = dep + 'A';
  vis[u] = 1;
  long long tmp = all;
  for (long long i = head[u], v; i; i = e[i].nxt) {
    v = e[i].to;
    if (vis[v]) continue;
    all = (fa[u] == v) ? tmp - siz[u] : siz[v];
    mn = inf;
    getrt(v, u);
    solve(rt, dep + 1);
  }
  return;
}
int main() {
  all = n = read();
  for (long long i = (2); i <= (n); ++i) {
    long long u = read(), v = read();
    add(u, v), add(v, u);
  }
  getrt(1, 0), solve(rt, 0);
  for (long long i = (1); i <= (n); ++i) putchar(ans[i]), putchar(' ');
  return 0;
}
