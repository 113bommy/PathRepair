#include <bits/stdc++.h>
using namespace std;
inline int Read() {
  int num = 0;
  char c = getchar();
  while ('0' > c || c > '9') c = getchar();
  while ('0' <= c && c <= '9') num = num * 10 + c - '0', c = getchar();
  return (num);
}
int n, m, s;
priority_queue<pair<long long, int> > hp;
long long ds[300010];
int tot, l[300010], v[300010];
struct Edge {
  int to, old, w;
} e[300010 * 2];
inline void Lnk(int x, int y, int z) {
  e[++tot].to = y, e[tot].old = l[x], l[x] = tot, e[tot].w = z;
}
inline void Dij() {
  memset(v, 0, sizeof(v));
  for (int i = 1; i <= n; i++) ds[i] = 1e18;
  ds[s] = 0;
  hp.push(make_pair(0, s));
  for (int i = 1; i < n && hp.size(); i++) {
    pair<long long, int> nw = hp.top();
    hp.pop();
    while (v[nw.second] && hp.size()) nw = hp.top(), hp.pop();
    if (v[nw.second]) break;
    v[nw.second] = 1;
    for (int j = l[nw.second]; j; j = e[j].old)
      if (ds[e[j].to] > ds[nw.second] + e[j].w) {
        ds[e[j].to] = ds[nw.second] + e[j].w;
        hp.push(make_pair(-ds[e[j].to], e[j].to));
      }
  }
}
int fa[300010][18], sz[300010], as, p[300010], dep[300010];
inline int Lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = 17; i >= 0; i--)
    if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
  for (int i = 17; i >= 0; i--)
    if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  if (x == y) return (x);
  return (fa[x][0]);
}
bool Cmpd(int a, int b) { return (ds[a] < ds[b]); }
int main() {
  n = Read(), m = Read(), s = Read();
  for (int i = 1; i <= m; i++) {
    int u = Read(), v = Read(), w = Read();
    Lnk(u, v, w), Lnk(v, u, w);
  }
  Dij();
  for (int i = 1; i <= n; i++) p[i] = i;
  sort(p + 1, p + 1 + n, Cmpd);
  dep[s] = 1;
  for (int i = 2; i <= n; i++) {
    int ii = p[i], pa = 0;
    if (ds[ii] > 9e17) continue;
    for (int j = l[ii]; j; j = e[j].old)
      if (ds[e[j].to] + e[j].w == ds[ii]) {
        if (!pa)
          pa = e[j].to;
        else
          pa = Lca(pa, e[j].to);
      }
    fa[ii][0] = pa, dep[ii] = dep[pa] + 1;
    for (int j = 1; j <= 17; j++) fa[ii][j] = fa[fa[ii][j - 1]][j - 1];
  }
  for (int i = n; i >= 1; i--) {
    int ii = p[i];
    if (ds[ii] > 9e17) continue;
    sz[ii]++, sz[fa[ii][0]] += sz[ii];
    if (i > 1) as = max(as, sz[ii]);
  }
  printf("%d\n", as);
}
