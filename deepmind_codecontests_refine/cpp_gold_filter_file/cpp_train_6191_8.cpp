#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, Q;
int val[N];
vector<int> G[N];
int vcnt;
namespace RST {
vector<int> T[N];
int dfn[N], low[N], timer = 0;
int stk[N], top = 0;
void tarjan(int x) {
  dfn[x] = low[x] = ++timer, stk[++top] = x;
  for (int i = 0; i < (int)G[x].size(); i++) {
    int y = G[x][i];
    if (!dfn[y]) {
      tarjan(y), low[x] = min(low[x], low[y]);
      if (low[y] == dfn[x]) {
        ++vcnt;
        for (int k = 0; k != y;) {
          k = stk[top--];
          T[vcnt].push_back(k), T[k].push_back(vcnt);
        }
        T[vcnt].push_back(x), T[x].push_back(vcnt);
      }
    } else
      low[x] = min(low[x], dfn[y]);
  }
}
}  // namespace RST
namespace HLD {
using RST::T;
int fa[N], siz[N], dep[N];
int wson[N], wtop[N];
int dfn[N], ref[N], timer = 0;
multiset<int> ch[N];
namespace segt {
int val[N << 2];
void build(int x, int l, int r) {
  if (l == r) return val[x] = ::val[ref[l]], void();
  build(x << 1, l, ((l + r) >> 1)), build(x << 1 | 1, ((l + r) >> 1) + 1, r);
  val[x] = min(val[x << 1], val[x << 1 | 1]);
}
void update(int x, int l, int r, int p, int v) {
  if (l == r) return val[x] = v, void();
  if (p <= ((l + r) >> 1))
    update(x << 1, l, ((l + r) >> 1), p, v);
  else
    update(x << 1 | 1, ((l + r) >> 1) + 1, r, p, v);
  val[x] = min(val[x << 1], val[x << 1 | 1]);
}
int query(int x, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return val[x];
  if (l > qr || ql > r) return 1e9;
  return min(query(x << 1, l, ((l + r) >> 1), ql, qr),
             query(x << 1 | 1, ((l + r) >> 1) + 1, r, ql, qr));
}
}  // namespace segt
void dfs1(int x, int f) {
  dep[x] = dep[fa[x] = f] + 1, siz[x] = 1;
  for (vector<int>::iterator it = T[x].begin(); it != T[x].end(); it++)
    if (*it != f)
      dfs1(*it, x), siz[x] += siz[*it],
          wson[x] = (siz[wson[x]] < siz[*it]) ? *it : wson[x];
}
void dfs2(int x, int t) {
  wtop[x] = t, ref[dfn[x] = ++timer] = x;
  if (wson[x]) dfs2(wson[x], t);
  for (vector<int>::iterator it = T[x].begin(); it != T[x].end(); it++)
    if (*it != fa[x] && *it != wson[x]) dfs2(*it, *it);
}
void init() {
  dfs1(1, 0), dfs2(1, 1);
  for (int i = n + 1; i <= vcnt; i++) {
    for (int j = 0; j < (int)T[i].size(); j++)
      if (T[i][j] != fa[i]) ch[i].insert(val[T[i][j]]);
    val[i] = *ch[i].begin();
  }
  segt::build(1, 1, vcnt);
}
void modify(int x, int w) {
  segt::update(1, 1, vcnt, dfn[x], w);
  if (fa[x]) {
    ch[fa[x]].erase(val[x]), ch[fa[x]].insert(w);
    val[fa[x]] = *ch[fa[x]].begin();
    segt::update(1, 1, vcnt, dfn[fa[x]], val[fa[x]]);
  }
  val[x] = w;
}
int query(int x, int y) {
  int ans = 1e9;
  for (; wtop[x] != wtop[y]; x = fa[wtop[x]]) {
    if (dep[wtop[x]] < dep[wtop[y]]) swap(x, y);
    ans = min(ans, segt::query(1, 1, vcnt, dfn[wtop[x]], dfn[x]));
  }
  if (dep[x] < dep[y]) swap(x, y);
  ans = min(ans, segt::query(1, 1, vcnt, dfn[y], dfn[x]));
  if (y > n) ans = min(ans, val[fa[y]]);
  return ans;
}
}  // namespace HLD
signed main() {
  scanf("%d%d%d", &n, &m, &Q);
  for (int i = 1; i <= n; i++) scanf("%d", val + i);
  for (int i = 1, u, v; i <= m; i++) {
    scanf("%d%d", &u, &v);
    G[u].push_back(v), G[v].push_back(u);
  }
  vcnt = n, RST::tarjan(1);
  HLD::init();
  while (Q--) {
    char opt[3];
    int x, y;
    scanf("%s%d%d", opt, &x, &y);
    if (opt[0] == 'C')
      HLD::modify(x, y);
    else
      printf("%d\n", HLD::query(x, y));
  }
  return 0;
}
