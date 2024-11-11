#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void Read(T &x) {
  int f = 1;
  char t = getchar();
  while (t < '0' || t > '9') {
    if (t == '-') f = -1;
    t = getchar();
  }
  x = 0;
  while (t >= '0' && t <= '9') {
    x = x * 10 + t - '0';
    t = getchar();
  }
  x *= f;
}
const int maxn = 100005;
const int inf = 0x3f3f3f3f;
struct data {
  int a, b, c, d, idx;
  bool flag;
  data() { flag = false; }
  void read() { Read(a), Read(b), Read(c), Read(d); }
  bool operator<(const data &rhs) const { return b > rhs.b; }
};
int n, all, pool[maxn];
int sz[maxn << 2], mn[maxn << 2];
int dis[maxn], pre[maxn];
data g[maxn];
vector<int> f[maxn << 2];
queue<int> line;
void input() {
  Read(n);
  for (register int i = 1; i <= n; i++) {
    g[i].read();
    g[i].idx = i, g[i].flag = (g[i].a == 0 && g[i].b == 0);
    pool[i] = g[i].a;
  }
  sort(pool + 1, pool + n + 1);
  all = unique(pool + 1, pool + n + 1) - pool - 1;
  for (register int i = 1; i <= n; i++)
    g[i].a = lower_bound(pool + 1, pool + all + 1, g[i].a) - pool;
  sort(g + 1, g + n + 1);
}
void insert(int cn, int l, int r, int x, int idx) {
  if (l == r) {
    f[l].push_back(idx);
    sz[cn]++, mn[cn] = g[idx].b;
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    insert(cn << 1, l, mid, x, idx);
  else if (x > mid)
    insert(cn << 1 | 1, mid + 1, r, x, idx);
  sz[cn] = sz[cn << 1] + sz[cn << 1 | 1];
  mn[cn] = min(mn[cn << 1], mn[cn << 1 | 1]);
}
int res[maxn], now;
void query(int cn, int l, int r, int l0, int r0, int lim) {
  if (!sz[cn] || lim < mn[cn]) return;
  if (l == r) {
    for (register int i = sz[cn] - 1; i >= 0; i--) {
      if (g[f[l][i]].b > lim) break;
      res[++now] = f[l][i], sz[cn]--;
    }
    mn[cn] = sz[cn] > 0 ? g[f[l][sz[cn] - 1]].b : inf;
    return;
  }
  int mid = (l + r) >> 1;
  if (r0 <= mid)
    query(cn << 1, l, mid, l0, r0, lim);
  else if (l0 > mid)
    query(cn << 1 | 1, mid + 1, r, l0, r0, lim);
  else
    query(cn << 1, l, mid, l0, mid, lim),
        query(cn << 1 | 1, mid + 1, r, mid + 1, r0, lim);
  sz[cn] = sz[cn << 1] + sz[cn << 1 | 1];
  mn[cn] = min(mn[cn << 1], mn[cn << 1 | 1]);
}
void solve() {
  int cn, loc;
  for (register int i = 1; i <= n; i++) {
    if (g[i].flag) {
      dis[i] = 1, line.push(i);
    } else {
      insert(1, 1, all, g[i].a, i);
    }
  }
  while (!line.empty()) {
    cn = line.front(), line.pop();
    loc = upper_bound(pool + 1, pool + all + 1, g[cn].c) - pool - 1;
    if (loc > 0) {
      now = 0, query(1, 1, all, 1, loc, g[cn].d);
      for (register int i = 1; i <= now; i++) {
        line.push(res[i]);
        dis[res[i]] = dis[cn] + 1;
        pre[res[i]] = cn;
      }
    }
  }
  for (register int i = 1; i <= n; i++) {
    if (g[i].idx == n) {
      if (dis[i] > 0) {
        int cn = i;
        now = 0;
        printf("%d\n", dis[i]);
        while (cn > 0) {
          res[++now] = g[cn].idx;
          cn = pre[cn];
        }
        while (now > 0) printf("%d ", res[now--]);
        return;
      } else
        printf("-1\n");
    }
  }
}
int main() {
  input();
  solve();
  return 0;
}
