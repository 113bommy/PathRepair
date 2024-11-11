#include <bits/stdc++.h>
using namespace std;
int get() {
  char ch;
  while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-')
    ;
  if (ch == '-') {
    int s = 0;
    while (ch = getchar(), ch >= '0' && ch <= '9') s = s * 10 + ch - '0';
    return -s;
  }
  int s = ch - '0';
  while (ch = getchar(), ch >= '0' && ch <= '9') s = s * 10 + ch - '0';
  return s;
}
const int N = 200010;
int fa[N][20];
int dep[N];
int n, m;
int f[N], son[N];
int Fa[N], val[N];
struct info {
  int id, x, y, v;
  friend bool operator<(info a, info b) { return a.id < b.id; }
} e[N];
int lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = 17; i >= 0; i--)
    if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
  if (x == y) return x;
  for (int i = 17; i >= 0; i--)
    if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  return fa[x][0];
}
int getv(int x, int y) {
  if (x == y) return 0;
  if (Fa[x] != y) {
    val[x] = val[x] + getv(Fa[x], y);
    Fa[x] = y;
  }
  return val[x];
}
int main() {
  n = get();
  m = get();
  dep[1] = 1;
  for (int i = 2; i <= n; i++) {
    int x = get();
    Fa[i] = x;
    dep[i] = dep[fa[i][0] = x] + 1;
    for (int t = 1; t <= 17; t++) fa[i][t] = fa[fa[i][t - 1]][t - 1];
  }
  for (int i = 1; i <= m; i++) {
    int x = get(), y = get(), v = get();
    e[i].id = lca(x, y);
    e[i].x = x;
    e[i].y = y;
    e[i].v = v;
  }
  sort(e + 1, e + 1 + m);
  int w = m;
  for (int i = n; i >= 1; i--) {
    f[i] = son[i];
    for (; w && e[w].id == i; w--)
      f[i] = max(f[i], getv(e[w].x, i) + getv(e[w].y, i) + e[w].v + son[i]);
    if (fa[i][0]) {
      son[fa[i][0]] += f[i];
    }
    val[i] = son[i] - f[i];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) ans = max(ans, f[i]);
  printf("%d\n", ans);
  return 0;
}
