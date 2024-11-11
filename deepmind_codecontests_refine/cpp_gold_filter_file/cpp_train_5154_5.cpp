#include <bits/stdc++.h>
using namespace std;
const int maxn = 100050;
struct seg {
  int to, v;
} edge[maxn << 1];
int siz[maxn], dep[maxn], son[maxn], fa[maxn], top[maxn], pos[maxn], dfn;
int tot, head[maxn];
priority_queue<int> qu[maxn];
int n, m, q;
struct node {
  int v[10];
  node() { memset(v, 0x3f, sizeof v); }
} tree[maxn << 2];
void addedge(int u, int v) {
  edge[tot].v = v;
  edge[tot].to = head[u];
  head[u] = tot++;
}
void dfs(int x, int d) {
  siz[x] = 1;
  dep[x] = d;
  for (int i = head[x]; ~i; i = edge[i].to) {
    int y = edge[i].v;
    if (y == fa[x]) continue;
    fa[y] = x;
    dfs(y, d + 1);
    siz[x] += siz[y];
    if (son[x] == -1 || siz[y] > siz[son[x]]) son[x] = y;
  }
}
void build(int x, int tp) {
  pos[x] = ++dfn;
  top[x] = tp;
  if (son[x] != -1) build(son[x], tp);
  for (int i = head[x]; ~i; i = edge[i].to) {
    int y = edge[i].v;
    if (y == son[x] || y == fa[x]) continue;
    build(y, y);
  }
}
node operator+(node a, node b) {
  node ans;
  int p1 = 0, p2 = 0;
  for (int i = 0; i < 10; i++) {
    if (a.v[p1] < b.v[p2]) {
      ans.v[i] = a.v[p1];
      p1++;
    } else {
      ans.v[i] = b.v[p2];
      p2++;
    }
  }
  return ans;
}
void push_up(int rt) { tree[rt] = tree[rt << 1] + tree[rt << 1 | 1]; }
void build_tree(int l, int r, int rt) {
  if (l == r) {
    int tt = 0;
    while (!qu[l].empty() && tt < 10) {
      tree[rt].v[tt++] = -qu[l].top();
      qu[l].pop();
    }
    return;
  }
  int mid = (l + r) >> 1;
  build_tree(l, mid, rt << 1);
  build_tree(mid + 1, r, rt << 1 | 1);
  push_up(rt);
}
node query(int L, int R, int l, int r, int rt) {
  if (l >= L && r <= R) {
    return tree[rt];
  }
  int mid = (l + r) >> 1;
  node ans;
  if (mid >= L) ans = ans + query(L, R, l, mid, rt << 1);
  if (mid < R) ans = ans + query(L, R, mid + 1, r, rt << 1 | 1);
  return ans;
}
node find(int x, int y) {
  int f1 = top[x], f2 = top[y];
  node ans;
  while (f1 != f2) {
    if (dep[f1] < dep[f2]) {
      swap(f1, f2);
      swap(x, y);
    }
    ans = ans + query(pos[f1], pos[x], 1, n, 1);
    x = fa[f1];
    f1 = top[x];
  }
  if (dep[x] < dep[y]) swap(x, y);
  ans = ans + query(pos[y], pos[x], 1, n, 1);
  return ans;
}
void init() {
  tot = dfn = 0;
  memset(head, -1, sizeof head);
  memset(son, -1, sizeof head);
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  int x, y, z;
  init();
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    addedge(y, x);
    addedge(x, y);
  }
  fa[1] = -1;
  dfs(1, 0);
  build(1, 1);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &x);
    qu[pos[x]].push(-i);
  }
  build_tree(1, n, 1);
  for (int i = 1; i <= q; i++) {
    scanf("%d%d%d", &x, &y, &z);
    node ans = find(x, y);
    int tt = 0;
    for (int i = 0; i < 10; i++) {
      if (ans.v[i] != 0x3f3f3f3f) tt++;
    }
    printf("%d", min(tt, z));
    for (int i = 0; i < min(tt, z); i++) {
      printf(" %d", ans.v[i]);
    }
    printf("\n");
  }
  return 0;
}
