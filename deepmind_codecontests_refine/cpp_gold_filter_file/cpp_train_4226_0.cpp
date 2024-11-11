#include <bits/stdc++.h>
using namespace std;
const long long INF = 2147483647;
inline long long read() {
  long long x = 0, k = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') k = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * k;
}
struct edge {
  long long u, v, g, s;
} e[50086];
long long fa[50286], son[2][50286], v[50286], mx[50286], f[50286];
long long tree[200086];
bool rv[50286];
long long n, m, g, s, ans, tot;
long long cmp(edge a, edge b) { return a.g < b.g; }
bool isroot(long long x) {
  return (son[0][fa[x]] != x) && (son[1][fa[x]] != x);
}
void rvers(long long x) {
  rv[x] ^= 1;
  swap(son[0][x], son[1][x]);
}
void pushdown(long long x) {
  if (!rv[x]) return;
  if (son[0][x]) rvers(son[0][x]);
  if (son[1][x]) rvers(son[1][x]);
  rv[x] = 0;
}
void update(long long x) {
  mx[x] = x;
  if (son[0][x] && v[mx[son[0][x]]] > v[mx[x]]) mx[x] = mx[son[0][x]];
  if (son[1][x] && v[mx[son[1][x]]] > v[mx[x]]) mx[x] = mx[son[1][x]];
}
void rotate(long long x) {
  long long y = fa[x], z = fa[y];
  bool t = (son[1][y] == x);
  if (!isroot(y)) son[son[1][z] == y][z] = x;
  fa[x] = z;
  fa[y] = x;
  son[t][y] = son[!t][x];
  son[!t][x] = y;
  if (son[t][y]) fa[son[t][y]] = y;
  update(y);
  update(x);
}
void pathdown(long long x) {
  if (!isroot(x)) pathdown(fa[x]);
  pushdown(x);
}
void splay(long long x) {
  pathdown(x);
  for (; !isroot(x); rotate(x))
    if (!isroot(fa[x]))
      (son[0][fa[x]] == x) ^ (son[0][fa[fa[x]]] == fa[x]) ? rotate(x)
                                                          : rotate(fa[x]);
}
void access(long long x) {
  long long y = 0;
  while (x) {
    splay(x);
    son[1][x] = y;
    update(x);
    y = x;
    x = fa[x];
  }
}
void makeroot(long long x) {
  access(x);
  splay(x);
  rvers(x);
}
void split(long long x, long long y) {
  makeroot(x);
  access(y);
  splay(y);
}
void link(long long x, long long y) {
  split(x, y);
  fa[x] = y;
}
void cut(long long x, long long y) {
  split(x, y);
  fa[x] = son[0][y] = 0;
  update(y);
}
long long find(long long x) {
  if (x != f[x]) return f[x] = find(f[x]);
  return f[x];
}
long long query(long long x, long long y) {
  split(x, y);
  return mx[y];
}
void pushup(long long root) {
  tree[root] = v[tree[root << 1]] >= v[tree[root << 1 | 1]]
                   ? tree[root << 1]
                   : tree[root << 1 | 1];
}
void modify(long long root, long long l, long long r, long long pos,
            long long k) {
  if (l == r && l == pos) {
    tree[root] = k;
    return;
  }
  long long mid = (l + r) >> 1;
  if (pos <= mid) modify(root << 1, l, mid, pos, k);
  if (pos > mid) modify(root << 1 | 1, mid + 1, r, pos, k);
  pushup(root);
}
signed main() {
  n = read(), m = read(), g = read(), s = read();
  for (long long i = (1); i <= (n + m); i++) f[i] = i;
  for (long long i = (1); i <= (m); i++) {
    e[i].u = read(), e[i].v = read(), e[i].g = read(), e[i].s = read();
  }
  sort(e + 1, e + 1 + m, cmp);
  for (long long i = (1); i <= (m); i++) v[i + n] = e[i].s;
  ans = INF * INF;
  for (long long i = (1); i <= (m); i++) {
    long long x = e[i].u, y = e[i].v, now = e[i].g;
    long long fx = find(x), fy = find(y);
    if (fx != fy) {
      f[fx] = fy;
      link(x, i + n), link(i + n, y);
      modify(1, 1, m, i, i + n);
      tot++;
    } else {
      long long w = query(x, y);
      if (v[w] > e[i].s) {
        cut(e[w - n].u, w), cut(w, e[w - n].v);
        modify(1, 1, m, w - n, 0);
        link(x, i + n), link(i + n, y);
        modify(1, 1, m, i, i + n);
      }
    }
    if (tot >= n - 1) ans = min(ans, now * g + v[tree[1]] * s);
  }
  printf("%lld", ans < 2e18 ? ans : -1);
  return 0;
}
