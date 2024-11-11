#include <bits/stdc++.h>
using namespace std;
const int maxn = 3333, oo = 1e9;
struct edge {
  int to, nxt, dis;
  double cost;
} e[maxn << 1];
int head[maxn], tot = 1, n, m;
double mincost;
void add(int x, int y, int z, double c) {
  e[++tot].to = y;
  e[tot].nxt = head[x];
  head[x] = tot;
  e[tot].dis = z;
  e[tot].cost = c;
  e[++tot].to = x;
  e[tot].nxt = head[y];
  head[y] = tot;
  e[tot].dis = 0;
  e[tot].cost = -c;
}
queue<int> q;
double d[maxn];
int vis[maxn], cnt[maxn], pre[maxn], incf[maxn];
inline bool spfa() {
  memset(d, 127, sizeof(d));
  memset(incf, 0x7f, sizeof(incf));
  memset(vis, 0, sizeof(vis));
  memset(pre, 0, sizeof(pre));
  queue<int> q;
  q.push(n);
  vis[n] = 1;
  d[n] = 0;
  while (q.size()) {
    int x = q.front();
    q.pop();
    vis[x] = 0;
    for (int i = head[x]; i; i = e[i].nxt) {
      int y = e[i].to;
      if (e[i].dis <= 0) continue;
      if (e[i].cost + d[x] < d[y]) {
        d[y] = e[i].cost + d[x];
        if (!vis[y]) q.push(y);
        vis[y] = 1;
        pre[y] = i;
        incf[y] = min(incf[x], e[i].dis);
      }
    }
  }
  if (d[1] > 1e18) return false;
  return true;
}
void update() {
  int x = 1;
  while (x != n) {
    int i = pre[x];
    e[i].dis -= incf[1];
    e[i ^ 1].dis += incf[1];
    x = e[i ^ 1].to;
  }
}
struct ee {
  int x, y, z;
} eee[maxn];
const double eps = 1e-7;
int lim;
double f[maxn];
int main() {
  cin >> n >> m;
  long long sum = 0;
  for (int i = (1); i <= (m); ++i) cin >> eee[i].x >> eee[i].y >> eee[i].z;
  for (int i = (1); i <= (m); ++i) add(eee[i].y, eee[i].x, 1, eee[i].z);
  int cnt = 0;
  for (int i = (1); i <= (n); ++i) {
    if (!spfa()) break;
    ++cnt;
    update();
    assert(incf[1] == 1);
    mincost += d[1] * incf[1];
    f[i] = mincost;
  }
  int q;
  cin >> q;
  while (q--) {
    cin >> lim;
    double ans = 1e12;
    for (int i = (1); i <= (cnt); ++i) ans = min(ans, 1.0 * (lim + f[i]) / i);
    printf("%.10lf\n", ans);
  }
}
