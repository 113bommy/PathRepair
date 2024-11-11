#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char c = getchar();
  int x = 0;
  bool f = 0;
  for (; !isdigit(c); c = getchar()) f ^= !(c ^ 45);
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  if (f) x = -x;
  return x;
}
mt19937 Rand(std::chrono::steady_clock::now().time_since_epoch().count());
int n, k, c[100005], deg[100005];
vector<int> e[100005];
int fa[100005], dep[100005], sz[100005], son[100005], top[100005];
int idx, dfn[100005], que[100005], ed[100005];
namespace DS {
int tot, rt[1600005], siz[1600005], pri[1600005], val[1600005], ch[1600005][2];
int stk[1600005], top;
inline int new_node() {
  int cur = top ? stk[top--] : ++tot;
  return siz[cur] = 1, pri[cur] = Rand(), cur;
}
inline void pushup(int p) { siz[p] = siz[ch[p][0]] + siz[ch[p][1]] + 1; }
void split(int p, int k, int &x, int &y) {
  if (!p) {
    x = y = 0;
    return;
  }
  if (val[p] <= k)
    x = p, split(ch[p][1], k, ch[x][1], y), pushup(x);
  else
    y = p, split(ch[p][0], k, x, ch[y][0]), pushup(y);
}
int merge(int x, int y) {
  if (!x || !y) return x | y;
  if (pri[x] > pri[y]) return ch[x][1] = merge(ch[x][1], y), pushup(x), x;
  return ch[y][0] = merge(x, ch[y][0]), pushup(y), y;
}
void ins(int &p, int k) {
  int x, y;
  split(p, k, x, y);
  int cur = new_node();
  val[cur] = k;
  p = merge(merge(x, cur), y);
}
void del(int &p, int k) {
  int x, y;
  split(p, k, x, y);
  int a, b;
  split(x, k - 1, a, b);
  stk[++top] = b;
  ch[b][0] = ch[b][1] = 0;
  b = merge(ch[b][0], ch[b][1]);
  p = merge(merge(a, b), y);
}
int getrnk(int &p, int k) {
  int a, b;
  split(p, k, a, b);
  int res = siz[a];
  return p = merge(a, b), res;
}
}  // namespace DS
using DS::del;
using DS::getrnk;
using DS::ins;
using DS::rt;
void dfs1(int u) {
  sz[u] = 1;
  for (auto v : e[u]) {
    if (v == fa[u]) continue;
    fa[v] = u, dep[v] = dep[u] + 1, dfs1(v), sz[u] += sz[v];
    if (sz[v] > sz[son[u]]) son[u] = v;
  }
}
void dfs2(int u, int tp) {
  top[u] = tp, dfn[u] = ++idx, que[idx] = u, ed[tp] = u;
  if (son[u]) dfs2(son[u], tp);
  for (auto v : e[u])
    if (v != fa[u] && v != son[u]) dfs2(v, v);
}
inline pair<int, int> merge(pair<int, int> x, pair<int, int> y) {
  return make_pair(min(x.first, max(y.first, x.second)),
                   min(x.first, max(x.second, y.second)));
}
pair<int, int> dat[100005 << 2];
int col[100005];
pair<int, int> qwq[100005];
inline void pushup(int p) { dat[p] = merge(dat[p << 1], dat[p << 1 | 1]); }
void mdf(int p, int l, int r, int x, pair<int, int> v) {
  if (l == r) return dat[p] = v, void();
  int mid = l + r >> 1;
  x <= mid ? mdf(p << 1, l, mid, x, v) : mdf(p << 1 | 1, mid + 1, r, x, v);
  pushup(p);
}
pair<int, int> ask(int p, int l, int r, int ql, int qr) {
  if (l >= ql && r <= qr) return dat[p];
  int mid = l + r >> 1;
  if (qr <= mid) return ask(p << 1, l, mid, ql, qr);
  if (ql > mid) return ask(p << 1 | 1, mid + 1, r, ql, qr);
  return merge(ask(p << 1, l, mid, ql, qr),
               ask(p << 1 | 1, mid + 1, r, ql, qr));
}
inline int ask(int u) { return ask(1, 1, n, dfn[u], dfn[ed[top[u]]]).first; }
bool chk(int u, int k, int delt) {
  int rk = getrnk(rt[u], k);
  return delt + ((int)e[u].size() - 1 - (u != 1) - rk) - rk < k;
}
void getval(int u, int &nd, int delt) {
  while (chk(u, nd - 1, delt)) --nd;
  while (!chk(u, nd, delt)) ++nd;
}
void getval(int u) {
  getval(u, qwq[u].first, 1);
  getval(u, qwq[u].second, -1);
}
void build(int p, int l, int r) {
  if (l == r) {
    int u = que[l];
    if (~col[u])
      dat[p] = qwq[u];
    else {
      for (auto v : e[u])
        if (v != fa[u] && v != son[u]) ins(rt[u], ask(v));
      getval(u);
      dat[p] = qwq[u];
    }
    return;
  }
  int mid = l + r >> 1;
  build(p << 1 | 1, mid + 1, r);
  build(p << 1, l, mid);
  pushup(p);
}
void modify(int u, int x) {
  if (col[u] == x) return;
  col[u] = x, qwq[u] = !x ? make_pair(-0x3f3f3f3f, -0x3f3f3f3f)
                          : make_pair(0x3f3f3f3f, 0x3f3f3f3f);
  for (; u; u = fa[top[u]]) {
    if (fa[top[u]]) DS::del(DS::rt[fa[top[u]]], ask(top[u]));
    if (col[u] == -1) getval(u);
    mdf(1, 1, n, dfn[u], qwq[u]);
    if (fa[top[u]]) DS::ins(DS::rt[fa[top[u]]], ask(top[u]));
  }
}
signed main() {
  n = read(), k = read();
  for (register int i = (2); i <= (n); ++i) {
    int u = read(), v = read();
    e[u].push_back(v), e[v].push_back(u);
  }
  dep[1] = 1, dfs1(1), dfs2(1, 1);
  for (register int i = (1); i <= (n); ++i) {
    col[i] = read();
    if (~col[i])
      qwq[i] = (!col[i] ? make_pair(-0x3f3f3f3f, -0x3f3f3f3f)
                        : make_pair(0x3f3f3f3f, 0x3f3f3f3f));
  }
  build(1, 1, n);
  int Q = read();
  while (Q--) {
    int o = read(), x = read(), v;
    if (o == 1)
      printf("%d\n", 1 - (ask(x) <= k));
    else if (o == 2)
      v = read(), modify(x, v);
    else
      k = x;
  }
  return 0;
}
