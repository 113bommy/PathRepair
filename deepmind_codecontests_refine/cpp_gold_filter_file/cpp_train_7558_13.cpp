#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
const int BLKSZ = 317;
int nowarn;
void noprint(...) {}
int n, c[MAXN], w[MAXN], q;
namespace Discrete {
int *a[MAXN], sz;
void init() { sz = 0; }
void add(int *p) { a[sz++] = p; }
bool cmp(int *a, int *b) { return *a < *b; }
void solve() {
  sort(a, a + sz, cmp);
  int last = *a[0], id = 1;
  for (int i = 0; i < sz; ++i)
    if (*a[i] == last)
      *a[i] = id;
    else
      last = *a[i], *a[i] = ++id;
}
}  // namespace Discrete
namespace Tree {
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], m;
void init() {
  m = 0;
  memset(head, -1, sizeof(head));
}
void adde(int u, int v) {
  to[m] = v, nxt[m] = head[u], head[u] = m++;
  to[m] = u, nxt[m] = head[v], head[v] = m++;
}
}  // namespace Tree
namespace Block {
int dfn[MAXN], dfn_cnt, blkno[MAXN], blkcnt;
stack<int> stk;
int dfs(int u, int fa) {
  using namespace Tree;
  dfn[u] = ++dfn_cnt;
  int sz = 0;
  for (int i = head[u]; ~i; i = nxt[i]) {
    int v = to[i];
    if (v == fa) continue;
    sz += dfs(v, u);
    if (sz >= BLKSZ) {
      ++blkcnt;
      for (; sz; --sz, stk.pop()) {
        int o = stk.top();
        blkno[o] = blkcnt;
      }
    }
  }
  ++sz, stk.push(u);
  return sz;
}
void solve() {
  dfn_cnt = blkcnt = 0;
  dfs(1, 0);
  while (!stk.empty()) {
    int u = stk.top();
    stk.pop();
    blkno[u] = blkcnt;
  }
}
}  // namespace Block
struct Query {
  int u, v, idx;
  Query() {}
  Query(int u, int v, int idx) : u(u), v(v), idx(idx) {}
  bool operator<(const Query &rhs) const {
    using Block::blkno;
    using Block::dfn;
    if (blkno[u] == blkno[rhs.u])
      return dfn[v] < dfn[rhs.v];
    else
      return blkno[u] < blkno[rhs.u];
  }
};
Query qy[MAXN];
namespace LCA {
int dfn[MAXN], dfn_cnt, sz[MAXN], top[MAXN], son[MAXN], dep[MAXN], pa[MAXN];
void dfs1(int u, int fa, int d) {
  using namespace Tree;
  pa[u] = fa, dep[u] = d, sz[u] = 1, son[u] = 0;
  for (int i = head[u]; ~i; i = nxt[i]) {
    int v = to[i];
    if (v == fa) continue;
    dfs1(v, u, d + 1);
    sz[u] += sz[v];
    if (sz[v] > sz[son[u]]) son[u] = v;
  }
}
void dfs2(int u, int tp) {
  using namespace Tree;
  dfn[u] = ++dfn_cnt, top[u] = tp;
  if (son[u]) dfs2(son[u], tp);
  for (int i = head[u]; ~i; i = nxt[i]) {
    int v = to[i];
    if (v == pa[u] || v == son[u]) continue;
    dfs2(v, v);
  }
}
void solve() {
  dfn_cnt = 0;
  dfs1(1, 0, 1);
  dfs2(1, 1);
}
int lca(int u, int v) {
  noprint("lca(%d %d) = ", u, v);
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
    u = pa[top[u]];
  }
  int ans = dep[u] < dep[v] ? u : v;
  noprint("%d\n", ans);
  return ans;
}
}  // namespace LCA
long long ans[MAXN], now;
int cnt[MAXN][2], vis[MAXN];
void flip(int x) {
  if (vis[x]) {
    now -= cnt[w[x]][!c[x]];
    --cnt[w[x]][c[x]];
    vis[x] = 0;
  } else {
    now += cnt[w[x]][!c[x]];
    ++cnt[w[x]][c[x]];
    vis[x] = 1;
  }
}
void move(int u, int v) {
  using LCA::lca;
  using LCA::pa;
  int w = lca(u, v);
  while (u != w) flip(u), u = pa[u];
  while (v != w) flip(v), v = pa[v];
}
void solve() {
  using LCA::lca;
  LCA::solve();
  now = 0;
  memset(vis, 0, sizeof(vis));
  memset(cnt, 0, sizeof(cnt));
  int u = 1, v = 1;
  for (int i = 0; i < q; ++i) {
    int uu = qy[i].u, vv = qy[i].v, idx = qy[i].idx;
    noprint("uu = %d, vv = %d\n", uu, vv);
    move(u, uu), move(v, vv), flip(lca(uu, vv));
    ans[idx] = now, flip(lca(uu, vv));
    u = uu, v = vv;
  }
}
int main() {
  nowarn = scanf("%d", &n);
  for (int i = 1; i <= n; ++i) nowarn = scanf("%d", c + i);
  Discrete::init();
  for (int i = 1; i <= n; ++i) {
    nowarn = scanf("%d", w + i);
    Discrete::add(w + i);
  }
  Discrete::solve();
  Tree::init();
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    nowarn = scanf("%d%d", &u, &v);
    Tree::adde(u, v);
  }
  nowarn = scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int u, v;
    nowarn = scanf("%d%d", &u, &v);
    if (u > v) swap(u, v);
    qy[i] = Query(u, v, i);
  }
  Block::solve();
  sort(qy, qy + q);
  solve();
  for (int i = 0; i < q; ++i) printf("%lld\n", ans[i]);
  return 0;
}
