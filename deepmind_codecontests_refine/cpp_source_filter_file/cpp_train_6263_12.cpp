#include <bits/stdc++.h>
using namespace std;
template <class t>
inline t read(t &x) {
  char c = getchar();
  bool f = 0;
  x = 0;
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  if (f) x = -x;
  return x;
}
template <class t>
inline void write(t x) {
  if (x < 0)
    putchar('-'), write(-x);
  else {
    if (x > 9) write(x / 10);
    putchar('0' + x % 10);
  }
}
const int N = 2205, M = 4e5 + 5;
int h[N * 6], en = 1, n, ans = -1, dis[N * 6], mc, mf, a[N], b[N], id[N];
bool v[N * 6];
struct edge {
  int n, v, f, w;
} e[M << 1];
void add(int x, int y, int f, int w) {
  e[++en] = (edge){h[x], y, f, w};
  h[x] = en;
}
void exadd(int x, int y, int f, int w) {
  add(x, y, f, w);
  add(y, x, 0, -w);
}
bool spfa(int s, int aim) {
  queue<int> q;
  q.push(s);
  memset(v, 0, sizeof v);
  memset(dis, 0x3f, sizeof dis);
  dis[s] = 0;
  v[s] = 1;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    v[x] = 0;
    for (int i = h[x]; i; i = e[i].n) {
      int y = e[i].v;
      if (dis[x] + e[i].w < dis[y] && e[i].f) {
        dis[y] = dis[x] + e[i].w;
        if (!v[y]) {
          q.push(y);
          v[y] = 1;
        }
      }
    }
  }
  return dis[aim] ^ 0x3f3f3f3f;
}
int dfs(int x, int flow, int aim) {
  if (x == aim) return flow;
  int rest = flow;
  v[x] = 1;
  for (int i = h[x]; i && rest; i = e[i].n) {
    int y = e[i].v;
    if (!v[y] && dis[y] == dis[x] + e[i].w && e[i].f) {
      int tp = dfs(y, min(rest, e[i].f), aim);
      if (!tp) dis[y] = 0x3f3f3f3f;
      rest -= tp;
      mc += tp * e[i].w;
      e[i].f -= tp;
      e[i ^ 1].f += tp;
    }
  }
  v[x] = 0;
  return flow - rest;
}
void mcmf(int s, int t) {
  mc = mf = 0;
  while (spfa(s, t)) mf += dfs(s, INT_MAX, t);
}
bool check(int mid) {
  for (int i = 1; i <= n << 1; i++) id[i] = i;
  sort(id + 1, id + 1 + n * 2, [&](int x, int y) {
    return b[x] < b[y] || b[x] == b[y] && a[x] > a[y];
  });
  long long mx = 0;
  vector<long long> have, need;
  for (int i = 1; i <= n << 1; i++) {
    long long v = 1ll * a[id[i]] * mid + b[id[i]];
    mx = max(mx, v);
    if (id[i] <= n)
      have.push_back(mx);
    else
      need.push_back(v);
  }
  sort(need.begin(), need.end());
  for (int i = 0; i < n; i++)
    if (have[i] < need[i]) return 0;
  return 1;
}
signed main() {
  read(n);
  for (int i = 1; i <= n << 1; i++) read(a[i]), read(b[i]);
  int l = 0, r = 1e9;
  while (l <= r) {
    int mid = l + r >> 1;
    if (check(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  if (ans == -1) return write(-1), 0;
  write(ans), putchar(' ');
  for (int i = 1; i <= n << 1; i++) id[i] = i;
  sort(id + 1, id + 1 + n, [&](int x, int y) {
    return b[x] < b[y] || b[x] == b[y] && a[x] > a[y];
  });
  sort(id + n + 1, id + 1 + n * 2, [&](int x, int y) {
    long long vx = 1ll * a[x] * ans + b[x];
    long long vy = 1ll * a[y] * ans + b[y];
    return vx < vy || vx == vy && x > y;
  });
  for (int i = 1; i <= n; i++) {
    exadd(0, i, 1, 0);
    exadd(i, n * 2 + i, n, 1);
    exadd(i, n * 4 + i, n, 0);
    exadd(n + i, n * 6 + 1, 1, 0);
    exadd(n * 2 + n + i, n + i, n, 1);
    exadd(n * 4 + n + i, n + i, n, 0);
  }
  for (int i = 2; i <= n; i++) {
    exadd(n * 2 + id[i], n * 2 + id[i - 1], n, 0);
    exadd(n * 2 + id[n + i], n * 2 + id[n + i - 1], n, 0);
  }
  for (int i = 1; i <= n << 1; i++) {
    int p1 = lower_bound(id + 1, id + 1 + n, i,
                         [&](int x, int y) { return b[x] < b[y]; }) -
             id;
    int p2 =
        upper_bound(id + 1 + n, id + n * 2 + 1, i,
                    [&](int x, int y) {
                      return 1ll * a[x] * ans + b[x] < 1ll * a[y] * ans + b[y];
                    }) -
        id - 1;
    if (p1 <= n) exadd(n * 2 + id[p1], n * 4 + i, n, 0);
    if (p2 > n) exadd(n * 4 + i, n * 2 + id[p2], n, 0);
  }
  mcmf(0, n * 6 + 1);
  write(mc);
}
