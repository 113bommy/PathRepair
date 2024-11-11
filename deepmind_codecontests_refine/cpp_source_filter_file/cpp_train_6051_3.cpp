#include <bits/stdc++.h>
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return f * x;
}
int max(int a, int b) { return a > b ? a : b; }
void umax(int& a, int t) {
  if (t > a) a = t;
}
const int INF = 1ll << 58;
struct edge {
  int v, nxt;
} e[200011 << 1 | 1];
int cnt = 0, last[200011];
void adde(int u, int v) {
  e[++cnt].v = v;
  e[cnt].nxt = last[u], last[u] = cnt;
}
int size[200011], mson[200011], fa[200011], dep[200011], len[200011];
void dfs1(int u, int now_dep) {
  size[u] = 1, dep[u] = now_dep;
  for (int i = last[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if (v == fa[u]) continue;
    fa[v] = u;
    dfs1(v, dep[u] + 1);
    size[u] += size[v];
    if (size[v] > size[mson[u]]) mson[u] = v;
  }
}
int top[200011];
void dfs2(int u, int now_top) {
  top[u] = now_top;
  if (mson[u]) dfs2(mson[u], now_top);
  for (int i = last[u]; i; i = e[i].nxt)
    if (e[i].v != fa[u] && e[i].v != mson[u]) dfs2(e[i].v, e[i].v);
}
int LCA(int u, int v) {
  while (top[u] != top[v])
    if (dep[top[u]] >= dep[top[v]])
      u = fa[top[u]];
    else
      v = fa[top[v]];
  return dep[u] > dep[v] ? v : u;
}
bool check_on(int u, int v, int x) {
  int r = LCA(u, v);
  return (LCA(u, x) == x || LCA(v, x) == x) && (LCA(x, r) == r);
}
int n, pos[200011];
struct Segment_Tree {
  struct node {
    int u, v, pos;
    node() {}
    node(int type) { pos = 0; }
    node(int _u, int _v, int p) { u = _u, v = _v, pos = p; }
    node operator+(node t) {
      if (!pos || !t.pos) return node(0);
      int p = max(pos, t.pos);
      if (check_on(u, v, t.u) && check_on(u, v, t.v)) return node(u, v, p);
      if (check_on(t.u, t.v, u) && check_on(t.u, t.v, v))
        return node(t.u, t.v, p);
      if (check_on(t.u, v, t.v) && check_on(t.u, v, u)) return node(t.u, v, p);
      if (check_on(t.u, u, t.v) && check_on(t.u, u, v)) return node(t.u, u, p);
      if (check_on(t.v, u, t.u) && check_on(t.v, u, v)) return node(t.v, u, p);
      if (check_on(t.v, v, t.u) && check_on(t.v, v, u)) return node(t.v, v, p);
      return node(0);
    }
  } t[200011 << 2 | 1];
  void build(unsigned l = 1, unsigned r = n, unsigned num = 1) {
    if (l == r)
      t[num] = node(pos[l], pos[l], l);
    else {
      unsigned mid = (l + r) >> 1;
      build(l, mid, num << 1), build(mid + 1, r, num << 1 | 1);
      t[num] = t[num << 1] + t[num << 1 | 1];
    }
  }
  node _Query(node pre, unsigned l, unsigned r, unsigned num) {
    if ((pre + t[num]).pos) return pre + t[num];
    if (l == r) return pre;
    unsigned mid = (l + r) >> 1;
    if ((pre + t[num << 1]).pos)
      return _Query(pre + t[num << 1], mid + 1, r, num << 1 | 1);
    else
      return _Query(pre, l, mid, num << 1);
  }
  node _Query(unsigned l, unsigned r, unsigned num) {
    if (t[num].pos) return t[num];
    unsigned mid = (l + r) >> 1;
    if (t[num << 1].pos) return _Query(t[num << 1], mid + 1, r, num << 1 | 1);
    return _Query(l, mid, num << 1);
  }
  int Query() { return _Query(1, n, 1).pos; }
  void modify(int x, unsigned l = 1, unsigned r = n, unsigned num = 1) {
    if (l == r) return (void)(t[num] = node(pos[x], pos[x], l));
    unsigned mid = (l + r) >> 1;
    if (x <= mid)
      modify(x, l, mid, num << 1);
    else
      modify(x, mid + 1, r, num << 1 | 1);
    t[num] = t[num << 1] + t[num << 1 | 1];
  }
} sgt;
int w[200011];
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) w[i] = read() + 1, pos[w[i]] = i;
  for (int i = 2; i <= n; ++i) adde(read(), i);
  dfs1(1, 1), dfs2(1, 1);
  sgt.build();
  int query = read();
  while (query--) {
    int op = read();
    if (op == 2)
      printf("%lld\n", sgt.Query());
    else {
      int u = read(), v = read();
      std::swap(w[u], w[v]);
      pos[w[u]] = u, pos[w[v]] = v;
      sgt.modify(w[u]), sgt.modify(w[v]);
    }
  }
  return 0;
}
