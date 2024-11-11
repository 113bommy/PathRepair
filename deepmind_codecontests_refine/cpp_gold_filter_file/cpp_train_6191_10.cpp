#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int u, v;
int val[200010];
int head[200010];
int head1[200010];
int id[200010];
int k;
int k1;
int son[200010];
int tid[200010];
int top[200100];
int size[200010];
int tx[200010];
int fa[200010];
int deep[200010];
int cnt;
int col;
int dfn[200100];
int low[200010];
int tot;
stack<int> s;
multiset<int> qaq[200010];
struct node {
  int to, next;
} edge[400100], edge1[400010];
struct qwq {
  int l, r, w;
} tree[1600100];
void build(int now, int l, int r) {
  tree[now].l = l;
  tree[now].r = r;
  if (l == r) {
    tree[now].w = val[tid[l]];
    id[tid[l]] = now;
    return;
  }
  int mid = tree[now].l + tree[now].r >> 1;
  build(now << 1, l, mid);
  build(now << 1 | 1, mid + 1, r);
  tree[now].w = min(tree[now << 1].w, tree[now << 1 | 1].w);
}
int findnum(int now, int l, int r) {
  if (tree[now].l >= l && tree[now].r <= r) return tree[now].w;
  int mid = tree[now].l + tree[now].r >> 1;
  if (mid >= r)
    return findnum(now << 1, l, r);
  else if (mid < l)
    return findnum(now << 1 | 1, l, r);
  else
    return min(findnum(now << 1, l, mid), findnum(now << 1 | 1, mid + 1, r));
}
void dfs1(int now, int f) {
  fa[now] = f;
  size[now] = 1;
  deep[now] = deep[f] + 1;
  for (int i = head[now]; i; i = edge[i].next) {
    int mp = edge[i].to;
    if (mp == f) continue;
    dfs1(mp, now);
    if (now > n) val[now] = min(val[now], val[mp]), qaq[now].insert(val[mp]);
    size[now] += size[mp];
    if (!son[now] || size[mp] > size[son[now]]) son[now] = mp;
  }
}
void dfs2(int now, int top1) {
  top[now] = top1;
  tx[now] = ++cnt;
  tid[cnt] = now;
  if (!son[now]) return;
  dfs2(son[now], top1);
  for (int i = head[now]; i; i = edge[i].next)
    if (edge[i].to != fa[now] && edge[i].to != son[now])
      dfs2(edge[i].to, edge[i].to);
}
inline void adde(int u, int v) {
  edge[++k].to = v;
  edge[k].next = head[u];
  head[u] = k;
  edge[++k].to = u;
  edge[k].next = head[v];
  head[v] = k;
}
inline void adde1(int u, int v) {
  edge1[++k1].to = v;
  edge1[k1].next = head1[u];
  head1[u] = k1;
  edge1[++k1].to = u;
  edge1[k1].next = head1[v];
  head1[v] = k1;
}
void tarjan(int now) {
  ++tot;
  dfn[now] = low[now] = tot;
  s.push(now);
  for (int i = head1[now]; i; i = edge1[i].next) {
    int mp = edge1[i].to;
    if (!dfn[mp]) {
      tarjan(mp);
      low[now] = min(low[now], low[mp]);
      if (low[mp] >= dfn[now]) {
        ++col;
        while (s.top() != mp) adde(s.top(), col), s.pop();
        adde(s.top(), col), adde(now, col), s.pop();
      }
    } else
      low[now] = min(low[now], dfn[mp]);
  }
}
void change(int now, int w) {
  now = id[now];
  tree[now].w = w;
  now >>= 1;
  while (now > 0)
    tree[now].w = min(tree[now << 1].w, tree[now << 1 | 1].w), now >>= 1;
}
int find(int x, int y) {
  int num = 0x7f7f7f7f;
  while (top[x] != top[y]) {
    if (deep[top[x]] < deep[top[y]]) swap(x, y);
    num = min(num, findnum(1, tx[top[x]], tx[x]));
    x = fa[top[x]];
  }
  if (deep[x] > deep[y]) swap(x, y);
  num = min(num, findnum(1, tx[x], tx[y]));
  if (x > n) num = min(num, val[fa[x]]);
  return num;
}
int main() {
  memset(val, 0x3f, sizeof(val));
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
  for (int i = 1; i <= m; i++) scanf("%d%d", &u, &v), adde1(u, v);
  col = n;
  tarjan(1);
  dfs1(1, 1);
  dfs2(1, 1);
  build(1, 1, col);
  for (int i = 1; i <= q; i++) {
    char rp;
    scanf("\n%c%d%d", &rp, &u, &v);
    if (rp == 'A')
      printf("%d\n", find(u, v));
    else {
      if (u == 1)
        val[1] = v, change(1, v);
      else {
        qaq[fa[u]].erase(qaq[fa[u]].find(val[u]));
        val[u] = v;
        qaq[fa[u]].insert(val[u]);
        change(u, v);
        change(fa[u], *qaq[fa[u]].begin());
      }
    }
  }
  return 0;
}
