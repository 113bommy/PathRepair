#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const long long inf = 1e18;
int n, m, q, fa[50][N];
long long T[N], F[50][N];
struct node {
  int a, b, c, d;
  int id;
} A[N];
vector<node> v;
int cov[N << 2], tj[N << 2];
void clear_tree() {
  memset(cov, 0, sizeof(cov));
  memset(tj, 0, sizeof(tj));
}
void pushdown(int o) {
  if (cov[o]) {
    tj[(o << 1)] = tj[(o << 1 | 1)] = cov[(o << 1)] = cov[(o << 1 | 1)] =
        cov[o];
    cov[o] = 0;
  }
}
void modify(int o, int l, int r, int pl, int pr, int x) {
  if (l >= pl && r <= pr) {
    tj[o] = cov[o] = x;
    return;
  }
  if (l > pr || r < pl) return;
  pushdown(o);
  int mid = (l + r) >> 1;
  modify((o << 1), l, mid, pl, pr, x),
      modify((o << 1 | 1), mid + 1, r, pl, pr, x);
}
int query(int o, int l, int r, int p) {
  if (l == r) return tj[o];
  pushdown(o);
  int mid = (l + r) >> 1;
  return mid >= p ? query((o << 1), l, mid, p)
                  : query((o << 1 | 1), mid + 1, r, p);
}
void work() {
  sort(v.begin(), v.end(), [&](const node &p, const node &q) {
    int x = min(p.a, p.c);
    int y = min(q.a, q.c);
    return x != y ? x < y : p.id < q.id;
  });
  clear_tree();
  vector<int> pos(n + q + 1);
  int i = 0;
  for (auto &p : v) {
    if (p.b == p.d && p.a > p.c) {
      int t = query(1, 0, m, p.b);
      fa[0][p.id] = t;
      if (!t)
        F[0][p.id] = inf;
      else
        F[0][p.id] = abs(p.c - v[pos[t]].c) + abs(p.d - v[pos[t]].d);
    }
    pos[p.id] = i++;
    if (p.id <= n) modify(1, 0, m, min(p.b, p.d), max(p.b, p.d), p.id);
  }
}
void rotate() {
  for (auto &p : v) {
    int a = p.a, b = p.b, c = p.c, d = p.d;
    p.a = b;
    p.b = m - a;
    p.c = d;
    p.d = m - c;
  }
}
void build() {
  for (int i = 1; i < 50; ++i)
    for (int j = 1; j <= n + q; j++) {
      fa[i][j] = fa[i - 1][fa[i - 1][j]];
      F[i][j] = F[i - 1][j] + F[i - 1][fa[i - 1][j]];
      if (F[i][j] > inf) F[i][j] = inf;
    }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, a, b, c, d; i <= n; i++) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    v.push_back(A[i] = (node){a, b, c, d, i});
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int x, y;
    char opt[3];
    scanf("%d%d%s%lld", &x, &y, opt, T + i);
    int a, b, c, d;
    a = c = x;
    b = d = y;
    switch (*opt) {
      case 'R':
        --a;
        break;
      case 'L':
        ++a;
        break;
      case 'U':
        --b;
        break;
      case 'D':
        ++b;
        break;
    };
    v.push_back(A[i + n] = (node){a, b, c, d, i + n});
  }
  for (int t = 4; t; t--) {
    work();
    rotate();
  }
  build();
  for (int i = 1; i <= q; i++) {
    long long t = T[i];
    int u = i + n, v;
    for (int j = 49; ~j; --j)
      if (F[j][u] <= t) t -= F[j][u], u = fa[j][u];
    v = fa[0][u];
    int dx, dy;
    long long r, x = A[u].c, y = A[u].d;
    dx = A[u].c - A[u].a, dy = A[u].d - A[u].b;
    if (dx) dx /= abs(dx);
    if (dy) dy /= abs(dy);
    if (!v)
      r = inf;
    else if (dx) {
      if (A[v].a <= A[u].c && A[v].c >= A[u].c)
        r = 0;
      else if (A[v].a >= A[u].c && A[v].c <= A[u].c)
        r = 0;
      else
        r = abs(A[u].c - A[v].c);
    } else if (dy) {
      if (A[v].b <= A[u].d && A[v].d >= A[u].d)
        r = 0;
      else if (A[v].b >= A[u].d && A[v].d <= A[u].d)
        r = 0;
      else
        r = abs(A[u].d - A[v].d);
    }
    x += dx * min(t, r);
    y += dy * min(t, r);
    t -= min(t, r);
    if (v) {
      dx = A[v].c - A[v].a, dy = A[v].d - A[v].b;
      if (dx) dx /= abs(dx);
      if (dy) dy /= abs(dy);
      x += dx * t;
      y += dy * t;
    }
    x = max(0ll, min<long long>(x, m));
    y = max(0ll, min<long long>(y, m));
    printf("%lld %lld\n", x, y);
  }
  return 0;
}
