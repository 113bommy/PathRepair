#include <bits/stdc++.h>
using namespace std;
int fa[200010], top[200010], dep[200010], he[200010], ne[200010 << 1],
    e[200010 << 1], cnt, sz[200010], son[200010], ans, n, a[200010];
pair<int, int> T[200010 << 2], tmp;
inline int read() {
  char ch = getchar();
  int x = 0;
  for (; ch > '9' || ch < '0'; ch = getchar())
    ;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return x;
}
void add(int u, int v) {
  ne[cnt] = he[u];
  he[u] = cnt;
  e[cnt] = v;
}
int LCA(int u, int v) {
  int tp = 0;
  for (; top[u] != top[v]; u = fa[top[u]])
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
  if (dep[u] > dep[v])
    return v;
  else
    return u;
}
int dis(int u, int v) {
  int t = LCA(u, v);
  return dep[u] + dep[v] - 2 * dep[t];
}
pair<int, int> add(int u, int v, int w) {
  if (!u || !v || !w) return make_pair(0, 0);
  int a = dis(u, v), b = dis(u, w), c = dis(v, w);
  if (a == b + c) return make_pair(u, v);
  if (b == a + c) return make_pair(u, w);
  if (c == a + b) return make_pair(v, w);
  return make_pair(0, 0);
}
pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
  if (a.first == -1) return b;
  a = add(a.first, a.second, b.first);
  a = add(a.first, a.second, b.second);
  return a;
}
void change(int t, int l, int r, int p, int v) {
  if (l == r) {
    T[t] = make_pair(v, v);
    return;
  }
  int mid = l + r >> 1;
  if (p <= mid)
    change(t << 1, l, mid, p, v);
  else
    change(t << 1 | 1, mid + 1, r, p, v);
  T[t] = merge(T[t << 1], T[t << 1 | 1]);
}
void dfs(int x) {
  sz[x] = 1;
  son[x] = 0;
  for (int i = he[x]; i; i = ne[i]) {
    dep[e[i]] = dep[x] + 1;
    dfs(e[i]);
    if (sz[e[i]] > sz[son[x]]) son[x] = e[i];
    sz[x] += sz[e[i]];
  }
}
void dfs(int x, int tp) {
  top[x] = tp;
  if (son[x]) dfs(son[x], tp);
  for (int i = he[x]; i; i = ne[i])
    if (e[i] != son[x]) dfs(e[i], e[i]);
}
bool query(int t, int l, int r) {
  pair<int, int> tt = merge(tmp, T[t]);
  if (tt.first != 0) {
    tmp = tt;
    ans = r;
    return 1;
  }
  if (l == r) return 0;
  int mid = l + r >> 1;
  if (query(t << 1, l, mid)) query(t << 1 | 1, mid + 1, r);
  return 0;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read() + 1;
  for (int i = 2; i <= n; i++) {
    fa[i] = read();
    add(fa[i], i);
  }
  dep[1] = 1;
  dfs(1);
  dfs(1, 1);
  for (int i = 1; i <= n; i++) change(1, 1, n, a[i], i);
  int Q = read();
  while (Q--) {
    int op = read();
    if (op == 1) {
      int u = read(), v = read();
      swap(a[u], a[v]);
      change(1, 1, n, a[u], u);
      change(1, 1, n, a[v], v);
    } else {
      tmp = make_pair(-1, 0);
      ans = 1;
      query(1, 1, n);
      printf("%d\n", ans);
    }
  }
  return 0;
}
