#include <bits/stdc++.h>
using namespace std;
const int M = 400200;
const int N = 200100;
int dep[N], fa[N][21], fin[N][21], bng[N], fvl[N][21], n, m, u, v, w, ans[M],
    F[N], lca;
struct Edge {
  int u, v, w, pos;
  Edge(int u = 0, int v = 0, int w = 0, int pos = 0)
      : u(u), v(v), w(w), pos(pos) {}
  bool operator<(const Edge &b) const { return w < b.w; }
} e[M];
struct Tree {
  int to, val, pos;
  Tree(int to = 0, int val = 0, int pos = 0) : to(to), val(val), pos(pos) {}
};
vector<Tree> g[N];
int Ask(int x) { return F[x] == x ? x : F[x] = Ask(F[x]); }
void Vis_Dfs(int x, int f, int p) {
  fa[x][0] = f;
  dep[x] = dep[f] + 1;
  bng[x] = p;
  for (int i = 0; i < g[x].size(); i++) {
    Tree v = g[x][i];
    if (v.to == f) continue;
    fvl[v.to][0] = v.val;
    Vis_Dfs(v.to, x, v.pos);
  }
}
void Lca(int &lca, int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = 20; i >= 0; i--)
    if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
  if (x == y) {
    lca = x;
    return;
  }
  for (int i = 20; i >= 0; i--)
    if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  lca = fa[x][0];
}
int Get(int x, int y, int val) {
  int t = 0;
  for (int i = 20; i >= 0; i--) {
    if (dep[fa[x][i]] <= dep[y]) continue;
    fin[x][i] = min(fin[x][i], val);
    t = max(t, fvl[x][i]);
    x = fa[x][i];
  }
  return t - 1;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) F[i] = i;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &u, &v, &w);
    e[i] = Edge(u, v, w, i);
  }
  sort(e + 1, e + m + 1);
  for (int i = 1; i <= m; i++) {
    int fx = Ask(e[i].u), fy = Ask(e[i].v);
    if (fx != fy) {
      F[fx] = fy;
      g[e[i].u].push_back(Tree(e[i].v, e[i].w, e[i].pos));
      g[e[i].v].push_back(Tree(e[i].u, e[i].w, e[i].pos));
      e[i].pos = 0;
    }
  }
  Vis_Dfs(1, 0, 0);
  for (int i = 1; i <= 20; i++)
    for (int j = 1; j <= n; j++) {
      fa[j][i] = fa[fa[j][i - 1]][i - 1];
      fvl[j][i] = max(fvl[j][i - 1], fvl[fa[j][i - 1]][i - 1]);
    }
  memset(fin, 0x3f, sizeof(fin));
  for (int i = 1; i <= m; i++) {
    if (!e[i].pos) continue;
    Lca(lca, e[i].u, e[i].v);
    ans[e[i].pos] = max(Get(e[i].u, lca, e[i].w), Get(e[i].v, lca, e[i].w));
  }
  for (int i = 20; i >= 0; i--)
    for (int j = 1; j <= n; j++) {
      fin[j][i - 1] = min(fin[j][i - 1], fin[j][i]);
      fin[fa[j][i - 1]][i - 1] = min(fin[fa[j][i - 1]][i - 1], fin[j][i]);
    }
  for (int i = 1; i <= n; i++) {
    ans[bng[i]] = fin[i][0] > 1e9 ? -1 : fin[i][0] - 1;
  }
  for (int i = 1; i <= m; i++) printf("%d ", ans[i]);
  return 0;
}
