#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  bool f = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar()) f = (ch == '-');
  for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ 48);
  return f ? -x : x;
}
const int N = 2e5 + 7;
int n, m, nd;
int u[N], v[N], a[N], b[N];
int Head[N], head[N], to[N << 2], nx[N << 2], id[N << 2], ec = 1;
inline void add(int *h, int a, int b, int c) {
  nx[++ec] = h[a];
  h[a] = ec;
  to[ec] = b;
  id[ec] = c;
}
inline void link(int *h, int a, int b, int c) {
  add(h, a, b, c);
  add(h, b, a, c);
}
void dfs(int fa, int x) {
  for (int lst = 0, i = head[x]; i; i = nx[i]) {
    int t = to[i];
    if (t == fa) continue;
    if (!lst)
      link(Head, x, t, id[i]), lst = x;
    else
      link(Head, lst, ++nd, 0), link(Head, nd, t, id[i]), lst = nd;
  }
  for (int i = head[x]; i; i = nx[i]) {
    int t = to[i];
    if (t != fa) dfs(x, t);
  }
}
bool vis[N << 2];
int sz[N], msz[N << 2], sum, g;
void gs(int fa, int x) {
  sz[x] = 1;
  for (int i = Head[x]; i; i = nx[i]) {
    int t = to[i];
    if (t == fa || vis[i >> 1]) continue;
    gs(x, t);
    sz[x] += sz[t];
  }
}
void gr(int fa, int x) {
  sz[x] = 1;
  for (int i = Head[x]; i; i = nx[i]) {
    int t = to[i];
    if (t == fa || vis[i >> 1]) continue;
    gr(x, t);
    sz[x] += sz[t];
    msz[i >> 1] = max(sz[t], sum - sz[t]);
    if (msz[i >> 1] < msz[g]) g = i >> 1;
  }
}
struct node {
  long long x, y;
  node(long long a, long long b) {
    x = a;
    y = b;
  }
  inline bool friend operator<(node a, node b) {
    return a.x == b.x ? a.y > b.y : a.x < b.x;
  }
  inline node friend operator+(node a, node b) {
    return node(a.x + b.x, a.y + b.y);
  }
  inline node friend operator-(node a, node b) {
    return node(a.x - b.x, a.y - b.y);
  }
  inline long double s() { return 1.0L * y / x; }
  inline long long val(int a) { return a * x + y; }
};
vector<node> tot;
inline long double slp(node a, node b) {
  return 1.0L * (b.y - a.y) / (b.x - a.x);
}
inline void convex(vector<node> &a) {
  sort(a.begin(), a.end());
  vector<node> b;
  for (node x : a) {
    if (!b.size()) {
      b.push_back(x);
      continue;
    }
    if (b.back().x == x.x) continue;
    int tmp = b.size();
    while (tmp > 1 && slp(b[tmp - 2], b[tmp - 1]) < slp(b.back(), x))
      --tmp, b.pop_back();
    b.push_back(x);
  }
  a = b;
}
inline void mincowski(vector<node> &l, vector<node> &r, vector<node> &ret) {
  for (int i = l.size() - 1; i; --i) l[i] = l[i] - l[i - 1];
  for (int i = r.size() - 1; i; --i) r[i] = r[i] - r[i - 1];
  ret.push_back(l[0] + r[0]);
  for (int x = 1, y = 1; x < l.size() || y < r.size();) {
    if (y == r.size() || (x < l.size() && l[x].s() > r[y].s()))
      ret.push_back(ret.back() + l[x++]);
    else
      ret.push_back(ret.back() + r[y++]);
  }
}
void stat(int x, int fa, long long A, long long B, vector<node> &vec) {
  bool flag = 0;
  for (int i = Head[x]; i; i = nx[i]) {
    int t = to[i];
    if (t == fa || vis[i >> 1]) continue;
    stat(t, x, A + a[id[i]], B + b[id[i]], vec);
    flag = 1;
  }
  if (!flag) vec.push_back(node(A, B));
}
void sol(int e) {
  vis[e] = 1;
  int ls = to[e << 1], rs = to[e << 1 | 1];
  vector<node> l, r, ret;
  stat(ls, rs, a[id[e << 1]], b[id[e << 1]], l);
  stat(rs, ls, 0, 0, r);
  convex(l);
  convex(r);
  mincowski(l, r, ret);
  for (node i : ret) tot.push_back(i);
  gs(ls, rs);
  sum = sz[rs];
  g = 0;
  gr(ls, rs);
  if (g) sol(g);
  gs(rs, ls);
  sum = sz[ls];
  g = 0;
  gr(rs, ls);
  if (g) sol(g);
}
int main() {
  nd = n = read();
  m = read();
  for (int i = 1; i < n; ++i) {
    u[i] = read();
    v[i] = read();
    a[i] = read();
    b[i] = read();
    link(head, u[i], v[i], i);
  }
  dfs(0, 1);
  msz[0] = nd;
  sum = nd;
  gr(0, 1);
  sol(g);
  sort(tot.begin(), tot.end());
  convex(tot);
  for (int i = 0, j = 0; i < m; ++i) {
    while (j + 1 < tot.size() && tot[j].val(i) <= tot[j + 1].val(i)) ++j;
    printf("%lld ", tot[j].val(i));
  }
  puts("");
  return 0;
}
