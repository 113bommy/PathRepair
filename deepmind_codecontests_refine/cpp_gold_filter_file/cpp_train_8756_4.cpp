#include <bits/stdc++.h>
using namespace std;
namespace zyt {
template <typename T>
inline bool read(T &x) {
  char c;
  bool f = false;
  x = 0;
  do c = getchar();
  while (c != EOF && c != '-' && !isdigit(c));
  if (c == EOF) return false;
  if (c == '-') f = true, c = getchar();
  do x = x * 10 + c - '0', c = getchar();
  while (isdigit(c));
  if (f) x = -x;
  return true;
}
template <typename T>
inline void write(T x) {
  static char buf[20];
  char *pos = buf;
  if (x < 0) putchar('-'), x = -x;
  do *pos++ = x % 10 + '0';
  while (x /= 10);
  while (pos > buf) putchar(*--pos);
}
const int N = 2e5 + 10, B = 20;
int head[N], ecnt, pos[N], euler[N << 1], dfn[N], dep[N], w[N], dfncnt, n;
struct edge {
  int to, next;
} e[N];
void add(const int a, const int b) {
  e[ecnt] = (edge){b, head[a]}, head[a] = ecnt++;
}
void dfs(const int u) {
  euler[++dfncnt] = u;
  dfn[u] = dfncnt;
  for (int i = head[u]; ~i; i = e[i].next) {
    int v = e[i].to;
    dep[v] = dep[u] + 1;
    dfs(v);
    euler[++dfncnt] = u;
  }
}
namespace ST {
int st[B][N << 1], lg2[N << 1];
int min(const int a, const int b) { return dfn[a] < dfn[b] ? a : b; }
void build() {
  int tmp = 0;
  for (int i = 1; i < (N << 1); i++) {
    lg2[i] = tmp;
    if (i == (1 << (tmp + 1))) ++tmp;
  }
  for (int i = 1; i <= dfncnt; i++) st[0][i] = euler[i];
  for (int i = 1; i < B; i++)
    for (int j = 1; j + (1 << i) - 1 <= dfncnt; j++)
      st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
}
inline int query(const int l, const int r) {
  int len = lg2[r - l + 1];
  return min(st[len][l], st[len][r - (1 << len) + 1]);
}
}  // namespace ST
int lca(const int u, const int v) {
  return ST::query(min(dfn[u], dfn[v]), max(dfn[u], dfn[v]));
}
int dis(const int u, const int v) {
  return dep[u] + dep[v] - (dep[lca(u, v)] << 1);
}
bool check(const int u, const int v, const int x) {
  return dis(u, v) == dis(u, x) + dis(v, x);
}
namespace Segment_Tree {
struct node {
  int x, y;
} tree[N << 2];
void update(node &a, const node &b, const node &c) {
  if (b.x == -1 || c.x == -1) {
    a.x = a.y = -1;
    return;
  }
  if (check(b.x, b.y, c.x) && check(b.x, b.y, c.y))
    a.x = b.x, a.y = b.y;
  else if (check(b.x, c.x, b.y) && check(b.x, c.x, c.y))
    a.x = b.x, a.y = c.x;
  else if (check(b.x, c.y, b.y) && check(b.x, c.y, c.x))
    a.x = b.x, a.y = c.y;
  else if (check(b.y, c.x, b.x) && check(b.y, c.x, c.y))
    a.x = b.y, a.y = c.x;
  else if (check(b.y, c.y, b.x) && check(b.y, c.y, c.x))
    a.x = b.y, a.y = c.y;
  else if (check(c.x, c.y, b.x) && check(c.x, c.y, b.y))
    a.x = c.x, a.y = c.y;
  else
    a.x = a.y = -1;
}
void update(const int rot) {
  update(tree[rot], tree[rot << 1], tree[rot << 1 | 1]);
}
void build(const int rot, const int lt, const int rt) {
  if (lt == rt) {
    tree[rot].x = tree[rot].y = pos[lt];
    return;
  }
  int mid = (lt + rt) >> 1;
  build(rot << 1, lt, mid);
  build(rot << 1 | 1, mid + 1, rt);
  update(rot);
}
void update(const int rot, const int lt, const int rt, const int p) {
  if (lt == rt) {
    tree[rot].x = tree[rot].y = pos[lt];
    return;
  }
  int mid = (lt + rt) >> 1;
  if (p <= mid)
    update(rot << 1, lt, mid, p);
  else
    update(rot << 1 | 1, mid + 1, rt, p);
  update(rot);
}
node query(const int rot, const int lt, const int rt, const int ls,
           const int rs) {
  if (ls <= lt && rt <= rs) return tree[rot];
  int mid = (lt + rt) >> 1;
  if (rs <= mid)
    return query(rot << 1, lt, mid, ls, rs);
  else if (ls > mid)
    return query(rot << 1 | 1, mid + 1, rt, ls, rs);
  else {
    node a, b, c;
    a = query(rot << 1, lt, mid, ls, rs);
    b = query(rot << 1 | 1, mid + 1, rt, ls, rs);
    update(c, a, b);
    return c;
  }
}
bool query(const int l, const int r) { return query(1, 1, n, l, r).x != -1; }
}  // namespace Segment_Tree
int work() {
  using namespace Segment_Tree;
  read(n);
  memset(head, -1, sizeof(int[n + 1]));
  for (int i = 1; i <= n; i++) {
    read(w[i]), ++w[i];
    pos[w[i]] = i;
  }
  for (int i = 2; i <= n; i++) {
    int a;
    read(a);
    add(a, i);
  }
  dfs(1);
  ST::build();
  build(1, 1, n);
  int q;
  read(q);
  while (q--) {
    int opt;
    read(opt);
    if (opt == 1) {
      int i, j;
      read(i), read(j);
      swap(pos[w[i]], pos[w[j]]);
      swap(w[i], w[j]);
      update(1, 1, n, w[i]), update(1, 1, n, w[j]);
    } else {
      int l = 1, r = n, ans = n + 1;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (query(1, mid))
          l = mid + 1;
        else
          r = mid - 1, ans = mid;
      }
      write(ans - 1), putchar('\n');
    }
  }
  return 0;
}
}  // namespace zyt
int main() { return zyt::work(); }
