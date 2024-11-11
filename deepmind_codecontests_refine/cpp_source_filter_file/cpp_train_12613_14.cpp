#include <bits/stdc++.h>
using namespace std;
const int maxn = 400010;
struct Node {
  int t, u, o;
};
int n, m, c[maxn], fa[maxn], sz[maxn], vsz[maxn], ch[maxn][2], pa[maxn];
long long sz2[maxn], vsz2[maxn], ans[maxn];
vector<int> E[maxn];
vector<Node> eve[maxn];
void dfs(int u) {
  for (auto v : E[u])
    if (v ^ pa[u]) pa[v] = u, dfs(v);
}
long long sqr(int x) { return 1ll * x * x; }
void pushup(int x) {
  sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + vsz[x] + 1;
  sz2[x] = vsz2[x] + sqr(sz[ch[x][0]]) + sqr(sz[ch[x][1]]);
}
bool isroot(int x) { return ch[fa[x]][0] != x && ch[fa[x]][1] != x; }
void rotate(int x) {
  int y = fa[x], z = fa[y], w = ch[y][1] == x;
  if (!isroot(y)) ch[z][ch[z][1] == y] = x;
  ch[y][w] = ch[x][w ^ 1];
  fa[ch[y][w]] = y;
  ch[x][w ^ 1] = y;
  fa[y] = x;
  fa[x] = z;
  pushup(y);
  pushup(x);
}
void splay(int x) {
  while (!isroot(x)) {
    int y = fa[x], z = fa[y];
    if (!isroot(y)) (ch[y][0] == x) ^ (ch[z][0] == y) ? rotate(x) : rotate(y);
    rotate(x);
  }
}
void access(int x) {
  for (int t = 0; x; t = x, x = fa[x]) {
    splay(x);
    vsz[x] += sz[ch[x][1]];
    vsz2[x] += sqr(sz[ch[x][1]]);
    ch[x][1] = t;
    vsz[x] -= sz[t];
    vsz2[x] -= sqr(sz[t]);
    pushup(x);
  }
}
int findroot(int x) {
  access(x);
  splay(x);
  while (ch[x][0]) x = ch[x][0];
  splay(x);
  return x;
}
void link(int x, int ff) {
  access(ff);
  splay(ff);
  splay(x);
  vsz[ff] += sz[x];
  vsz2[ff] += sqr(sz[x]);
  fa[x] = ff;
  pushup(ff);
}
void cut(int x, int ff) {
  access(ff);
  splay(ff);
  splay(x);
  vsz[ff] -= sz[x];
  vsz2[ff] -= sqr(sz[x]);
  fa[x] = 0;
  pushup(ff);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
  for (int i = 1, u, v; i < n; i++) {
    scanf("%d%d", &u, &v);
    E[u].push_back(v), E[v].push_back(u);
  }
  dfs(1), pa[1] = n + 1;
  for (int i = 1; i <= n + 1; i++) sz[i] = 1;
  for (int i = 1; i <= n; i++) link(i, pa[i]);
  for (int i = 1; i <= n; i++) eve[c[i]].push_back((Node){0, i, 0});
  int u, x;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &u, &x);
    eve[c[u]].push_back((Node){i, u, 1});
    eve[c[u] = x].push_back((Node){i, u, 0});
  }
  for (int i = 1; i <= n; i++) eve[c[i]].push_back((Node){m + 1, i, 1});
  for (int i = 1; i <= n; i++)
    for (auto x : eve[i]) {
      int t = x.t, u = x.u, ff = findroot(pa[u]);
      if (x.o) {
        splay(ff), splay(u), ans[t] += sz2[ff] + sz2[u];
        link(u, pa[u]), splay(ff), ans[t] -= sz2[ff];
      } else {
        splay(ff), ans[t] += sz2[ff], cut(u, pa[u]);
        splay(ff), splay(u), ans[t] -= sz2[ff] + sz2[u];
      }
    }
  for (int i = 1; i <= m; i++) ans[i] += ans[i - 1];
  for (int i = 0; i <= m; i++) printf("%lld", ans[i]);
  return 0;
}
