#include <bits/stdc++.h>
using namespace std;
const int MAXN = 6e5 + 10;
const long long INF = 2e18;
int n;
long long change[MAXN];
struct data {
  int u, v;
  long long w1, w2;
} d[MAXN];
struct edge {
  int to, next;
  long long w;
} e[MAXN << 1];
int head[MAXN], cnt = 0;
inline void add(int u, int v, long long w) {
  e[++cnt] = (edge){v, head[u], w}, head[u] = cnt;
  e[++cnt] = (edge){u, head[v], w}, head[v] = cnt;
}
struct hnd {
  int u;
  long long d;
  bool operator<(const hnd& rhs) const { return d > rhs.d; }
};
priority_queue<hnd> q;
long long dis[MAXN];
void dij() {
  for (int i = 1; i <= n; i++) dis[i] = change[i], q.push((hnd){i, dis[i]});
  while (q.size()) {
    hnd x = q.top();
    q.pop();
    int u = x.u;
    if (x.d == dis[u]) continue;
    for (int i = head[u]; i; i = e[i].next) {
      int v = e[i].to;
      long long w = e[i].w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        q.push((hnd){v, dis[v]});
      }
    }
  }
}
int fa[MAXN], dep[MAXN], size[MAXN], hson[MAXN];
long long fav1[MAXN], fav2[MAXN];
void dfs(int u, int father) {
  size[u] = 1;
  dep[u] = dep[father] + 1;
  fa[u] = father;
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if (v == father) continue;
    dfs(v, u);
    size[u] += size[v];
    if ((!hson[u]) || (size[hson[u]] < size[v])) hson[u] = v;
  }
}
int id[MAXN], rl[MAXN], top[MAXN], tim = 0;
void dfs2(int u, int tp) {
  id[u] = ++tim;
  rl[tim] = u;
  top[u] = tp;
  if (hson[u]) dfs2(hson[u], tp);
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if (v == fa[u] || v == hson[u]) continue;
    dfs2(v, v);
  }
}
int lca(int x, int y) {
  int tx = top[x], ty = top[y];
  while (tx != ty) {
    if (dep[x] < dep[y])
      y = fa[ty];
    else
      x = fa[tx];
    tx = top[x], ty = top[y];
  }
  if (dep[x] < dep[y]) return x;
  return y;
}
struct node {
  int l, r, top, bot;
  long long aa, ab, ba, bb;
} tree[MAXN << 2];
node pushup(node a, node b) {
  node ret;
  ret.l = a.l;
  ret.r = b.r;
  ret.top = dep[a.top] < dep[b.top] ? a.top : b.top;
  ret.bot = dep[a.bot] < dep[b.bot] ? b.bot : a.bot;
  if (dep[a.top] < dep[b.top]) swap(a, b);
  long long w1 = fav1[a.top], w2 = fav2[a.top];
  ret.aa = min(a.aa + b.aa + w1, a.ab + b.ba + w2);
  ret.ab = min(a.aa + b.ab + w1, a.ab + b.bb + w2);
  ret.ba = min(a.ba + b.aa + w1, a.bb + b.ba + w2);
  ret.bb = min(a.ba + b.ab + w1, a.bb + b.bb + w2);
  return ret;
}
void build(int o, int l, int r) {
  tree[o].l = l, tree[o].r = r;
  if (l == r) {
    tree[o].top = tree[o].bot = rl[l];
    tree[o].aa = 0;
    tree[o].ab = dis[rl[l]];
    tree[o].ba = dis[rl[l]];
    tree[o].bb = 0;
    return;
  }
  int mid = l + r >> 1;
  build((o << 1), l, mid);
  build((o << 1 | 1), mid + 1, r);
  tree[o] = pushup(tree[(o << 1)], tree[(o << 1 | 1)]);
}
node query(int o, int l, int r, int ql, int qr) {
  if (ql <= l && qr >= r) return tree[o];
  int mid = l + r >> 1;
  if (ql <= mid && qr > mid) {
    return pushup(query((o << 1), l, mid, ql, qr),
                  query((o << 1 | 1), mid + 1, r, ql, qr));
  } else if (ql <= mid)
    return query((o << 1), l, mid, ql, qr);
  else if (qr > mid)
    return query((o << 1 | 1), mid + 1, r, ql, qr);
}
node calc(int u, int lim) {
  bool flag = 0;
  node ret;
  while (dep[top[u]] > dep[lim]) {
    if (!flag) {
      flag = 1;
      ret = query(1, 1, n, id[top[u]], id[u]);
    } else {
      ret = pushup(ret, query(1, 1, n, id[top[u]], id[u]));
    }
    u = fa[top[u]];
  }
  if (!flag) {
    ret = query(1, 1, n, id[lim], id[u]);
  } else {
    ret = pushup(ret, query(1, 1, n, id[lim], id[u]));
  }
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &change[i]);
  }
  for (int i = 1; i < n; i++) {
    scanf("%d%d%I64d%I64d", &d[i].u, &d[i].v, &d[i].w1, &d[i].w2);
    add(d[i].u, d[i].v, d[i].w1 + d[i].w2);
  }
  dfs(1, 1);
  dfs2(1, 1);
  for (int i = 1; i < n; i++) {
    if (dep[d[i].u] < dep[d[i].v]) {
      fav1[d[i].v] = d[i].w1;
      fav2[d[i].v] = d[i].w2;
    } else {
      fav1[d[i].u] = d[i].w1;
      fav2[d[i].u] = d[i].w2;
    }
  }
  dij();
  build(1, 1, n);
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int u, v, ty;
    long long ans = INF;
    scanf("%d%d", &u, &v);
    if ((u & 1) && (v & 1))
      ty = 0;
    else if ((!(u & 1)) && (v & 1))
      ty = 1;
    else if ((u & 1) && (!(v & 1)))
      ty = 2;
    else if ((!(u & 1)) && (!(v & 1)))
      ty = 3;
    u = u + 1;
    v = v + 1;
    u >>= 1;
    v >>= 1;
    int L = lca(u, v);
    node a = calc(u, L);
    node b = calc(v, L);
    if (ty == 0)
      ans = min(min(a.aa + b.aa, a.ab + b.ab),
                min(a.ba + b.aa + dis[u], a.bb + b.ab + dis[u]));
    if (ty == 1)
      ans = min(min(a.ba + b.aa, a.bb + b.ab),
                min(a.aa + b.aa + dis[u], a.ab + b.ab + dis[u]));
    if (ty == 2)
      ans = min(min(a.aa + b.ba, a.ab + b.bb),
                min(a.ba + b.ba + dis[u], a.bb + b.bb + dis[u]));
    if (ty == 3)
      ans = min(min(a.ba + b.ba, a.bb + b.bb),
                min(a.aa + b.ba + dis[u], a.ab + b.bb + dis[u]));
    cout << ans << endl;
  }
  return 0;
}
