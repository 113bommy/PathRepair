#include <bits/stdc++.h>
struct node {
  int u, v, f, c, p;
  node(int a = 0, int b = 0, int d = 0, int e = 0, int g = 0)
      : u(a), v(b), f(d), c(e), p(g) {}
};
using i64 = long long;
using IT = std::vector<node>::iterator;
const int N = 14007;
int n, s, t, dis[N], flow[N], inq[N];
IT id[N];
struct line {
  int k, b, id;
} a[N];
std::queue<int> q;
std::vector<node> e[N];
int read() {
  int x;
  scanf("%d", &x);
  return x;
}
int check(i64 t) {
  static i64 r[N], s[N];
  memset(r + 1, 0, n << 3);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n + n; ++j)
      if (a[i].b >= a[j].b) r[i] = std::max(r[i], t * a[j].k + a[j].b);
  for (int i = 1; i <= n; ++i) s[i] = t * a[n + i].k + a[n + i].b;
  std::sort(r + 1, r + n + 1), std::sort(s + 1, s + n + 1);
  for (int i = 1; i <= n; ++i)
    if (r[i] < s[i]) return 0;
  return 1;
}
void add(int u, int v, int f, int c) {
  e[u].emplace_back(u, v, f, c, (int)e[v].size()),
      e[v].emplace_back(v, u, 0, -c, (int)e[u].size() - 1);
}
int spfa() {
  memset(dis, 0x3f, sizeof dis), memset(flow, 0x3f, sizeof flow), q.push(s),
      inq[s] = 1, dis[s] = 0, id[t] = e[t].begin();
  for (int u, v; !q.empty();) {
    u = q.front(), q.pop(), inq[u] = 0;
    for (IT it = e[u].begin(); it != e[u].end(); ++it)
      if (it->f && dis[v = it->v] > dis[u] + it->c) {
        dis[v] = dis[u] + it->c, id[v] = it, flow[v] = std::min(flow[u], it->f);
        if (!inq[v]) q.push(v), inq[v] = 1;
      }
  }
  return id[t] != e[t].begin();
}
void build(i64 tim) {
  s = 6 * n + 1, t = 6 * n + 2;
  for (int i = 1; i <= n; ++i)
    add(s, i + n * 4, 1, 0), add(i + n * 4, i, 1, 1),
        add(i + n * 4, i + n + n, 1, 0), add(i + n * 5, t, 1, 0),
        add(i + n * 3, i + n * 5, 1, 1), add(i + n, i + n * 5, 1, 0);
  for (int i = 1; i <= n + n; ++i) add(i, i + n + n, 10000, 0);
  std::sort(a + 1, a + n + n + 1, [](line a, line b) { return a.b > b.b; });
  for (int l = 1, r; l <= n + n; l = r + 1) {
    for (r = l; a[r + 1].b == a[l].b; ++r)
      ;
    for (int i = l; i <= r; ++i)
      if (i < n + n) add(a[i].id, a[i + 1].id, 10000, 0);
    add(a[r].id, a[l].id, 10000, 0);
  }
  std::sort(a + 1, a + n + n + 1,
            [&](line a, line b) { return tim * a.k + a.b > tim * b.k + b.b; });
  for (int l = 1, r; l <= n + n; l = r + 1) {
    for (r = l; tim * a[r + 1].k + a[r + 1].b == tim * a[l].k + a[l].b; ++r)
      ;
    for (int i = l; i <= r; ++i)
      if (i < n + n) add(a[i].id + n + n, a[i + 1].id + n + n, 10000, 0);
    add(a[r].id + n + n, a[l].id + n + n, 10000, 0);
  }
}
int EK() {
  int ans = 0;
  for (int p; spfa();)
    for (p = t, ans += flow[t] * dis[t]; p ^ s; p = id[p]->u)
      id[p]->f -= flow[t], e[p][id[p]->p].f += flow[t];
  return ans;
}
int main() {
  n = read();
  int ans = 0;
  for (int i = 1; i <= n + n; ++i) a[i] = {read(), read(), i};
  if (!check(1e9)) return !printf("-1");
  for (int l = 0, r = 1e9, mid; l <= r;)
    check(mid = (l + r) >> 1) ? (ans = mid, r = mid - 1) : (l = mid + 1);
  build(ans), printf("%d %d", ans, EK());
}
