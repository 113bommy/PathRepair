#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int a = 0, f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) a = (a << 3) + (a << 1) + ch - '0';
  return a * f;
}
const int mod = 1e9 + 7;
const int N = 1e6 + 5;
int n, m, tim;
int U[N], V[N];
inline int ls(int pos) { return pos << 1; }
inline int rs(int pos) { return pos << 1 | 1; }
struct tree {
  int sum[N << 2];
  inline void push_up(int pos) { sum[pos] = sum[ls(pos)] + sum[rs(pos)]; }
  void build(int pos, int l, int r) {
    if (l == r) {
      sum[pos] = 1;
      return;
    }
    int mid = (l + r) >> 1;
    build(ls(pos), l, mid);
    build(rs(pos), mid + 1, r);
    push_up(pos);
    return;
  }
  void update(int pos, int l, int r, int k, int val) {
    if (l == r) {
      sum[pos] = val;
      return;
    }
    int mid = (l + r) >> 1;
    if (k <= mid)
      update(ls(pos), l, mid, k, val);
    else
      update(rs(pos), mid + 1, r, k, val);
    push_up(pos);
    return;
  }
  int query(int pos, int l, int r, int L, int R) {
    if (L > R) return 0;
    if (L <= l && r <= R) return sum[pos];
    int mid = (l + r) >> 1, ans = 0;
    if (L <= mid) ans += query(ls(pos), l, mid, L, R);
    if (R > mid) ans += query(rs(pos), mid + 1, r, L, R);
    return ans;
  }
  inline void print_tree(void) {
    puts("==========================");
    for (int i = 1; i <= 10; i++) printf("tr[%2d]= %2d\n", i, sum[i]);
    puts("==========================");
  }
} tr;
struct edge {
  int to, next;
} e[N << 2];
int head[N], cnt;
inline void add(int u, int v) {
  e[++cnt].to = v;
  e[cnt].next = head[u];
  head[u] = cnt;
}
struct node {
  int dfn, fa, son;
  int siz, top, dep;
} p[N];
void prework(int u, int fa, int deep) {
  p[u].fa = fa;
  p[u].dep = deep;
  p[u].siz = 1;
  int max_subtree = -1;
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if (v == fa) continue;
    prework(v, u, deep + 1);
    p[u].siz += p[v].siz;
    if (p[v].siz > max_subtree) max_subtree = p[v].siz, p[u].son = v;
  }
  return;
}
void dfs(int u, int fa) {
  p[u].top = fa;
  p[u].dfn = ++tim;
  if (!p[u].son) return;
  dfs(p[u].son, fa);
  for (int i = head[u]; i; i = e[i].next)
    if (e[i].to != p[u].fa && e[i].to != p[u].son) dfs(e[i].to, e[i].to);
}
inline int query_sum(int x, int y) {
  int ans = 0, sum = 0;
  while (p[x].top != p[y].top) {
    if (p[p[x].top].dep < p[p[y].top].dep) swap(x, y);
    ans += tr.query(1, 1, n, p[p[x].top].dfn, p[x].dfn);
    sum += p[x].dfn - p[p[x].top].dfn + 1;
    x = p[p[x].top].fa;
  }
  if (p[x].dep > p[y].dep) swap(x, y);
  ans += tr.query(1, 1, n, p[x].dfn + 1, p[y].dfn);
  sum += p[y].dfn - p[x].dfn;
  if (ans == sum)
    return sum;
  else
    return -1;
}
signed main() {
  n = read();
  for (int i = 1; i < n; i++) {
    int x = read(), y = read();
    add(x, y);
    add(y, x);
    U[i] = x;
    V[i] = y;
  }
  prework(1, 0, 1);
  dfs(1, 0);
  tr.build(1, 1, n);
  m = read();
  for (int i = 1; i <= m; i++) {
    int opt = read();
    if (opt == 1) {
      int x = read();
      int u = U[x], v = V[x];
      if (p[u].dep > p[v].dep)
        tr.update(1, 1, n, p[u].dfn, 1);
      else
        tr.update(1, 1, n, p[v].dfn, 1);
    } else if (opt == 2) {
      int x = read();
      int u = U[x], v = V[x];
      if (p[u].fa > p[v].dep)
        tr.update(1, 1, n, p[u].dfn, 0);
      else
        tr.update(1, 1, n, p[v].dfn, 0);
    } else if (opt == 3) {
      int u = read(), v = read();
      printf("%d\n", query_sum(u, v));
    }
  }
  return 0;
}
