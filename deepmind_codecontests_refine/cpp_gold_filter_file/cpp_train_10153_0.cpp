#include <bits/stdc++.h>
using namespace std;
int n;
int head[100011];
struct ways {
  int now, next;
} way[100011 << 1];
int fa[100011];
int val[100011];
long long f[100011][5];
int que[100011], root, ap = 1;
inline int rd() {
  register char ch = getchar();
  register int res = 0;
  register bool flag = false;
  while (ch < '0' || ch > '9') {
    flag = (ch == '-');
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    res = (res << 3) + (res << 1) + ch - '0';
    ch = getchar();
  }
  return flag ? -res : res;
}
inline void link(int u, int v) {
  way[++ap].now = v;
  way[ap].next = head[u];
  head[u] = ap;
  way[++ap].now = u;
  way[ap].next = head[v];
  head[v] = ap;
}
void work() {
  n = rd();
  register int i, j, fir, las, x, y, to;
  register long long res = 0, ans = 0, rev = 0;
  for (i = 1; i <= n; i++) val[i] = rd();
  for (i = 1; i < n; i++) {
    link(rd(), rd());
  }
  root = 1;
  for (que[fir = las = 1] = root; fir <= las; fir++) {
    x = que[fir];
    for (y = head[x]; to = way[y].now, y; y = way[y].next)
      if (to != fa[x]) {
        fa[to] = x;
        que[++las] = to;
      }
  }
  for (i = las; i >= 1; i--) {
    x = que[i];
    f[x][1] = val[x];
    res = 0;
    rev = 0;
    for (y = head[x]; to = way[y].now, y; y = way[y].next)
      if (to != fa[x]) {
        f[x][4] = max(f[x][4], f[to][4]);
        f[x][4] = max(f[x][4], f[x][2] + f[to][2]);
        f[x][4] = max(f[x][4], f[x][3] + f[to][1]);
        f[x][4] = max(f[x][4], f[to][3] + f[x][1]);
        f[x][3] = max(f[x][3], f[to][3] + val[x]);
        f[x][3] = max(f[x][3], res + f[to][1] + val[x]);
        f[x][3] = max(f[x][3], f[x][1] + f[to][2]);
        f[x][2] = max(f[x][2], f[to][2]);
        f[x][2] = max(f[x][2], f[to][1] + f[x][1]);
        f[x][1] = max(f[x][1], f[to][1] + val[x]);
        res = max(res, f[to][2]);
      }
    f[x][2] = max(f[x][2], f[x][1]);
    f[x][4] = max(f[x][3], f[x][4]);
    ans = max(max(max(max(ans, f[x][1]), f[x][2]), f[x][3]), f[x][4]);
  }
  printf("%I64d\n", ans);
}
int main() {
  work();
  return 0;
}
