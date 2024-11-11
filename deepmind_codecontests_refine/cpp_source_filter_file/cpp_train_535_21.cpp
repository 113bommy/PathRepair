#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int inf = ~0U >> 1;
template <class U, class V>
struct MCMF {
  static const int N = 30000, M = 7010010;
  int h[N], ing[N], pre[N], to[M], ne[M], e, s, t, n;
  U cap[M];
  V dis[N], cost[M];
  void ini(int _n = N) {
    fill(h, h + (n = _n), -1);
    e = 0;
  }
  void liu(int u, int v, U c, V w) {
    to[e] = v;
    ne[e] = h[u];
    cap[e] = c;
    cost[e] = w;
    h[u] = e++;
  }
  void link(int u, int v, U c, V w) {
    liu(u, v, c, w);
    liu(v, u, 0, -w);
  }
  bool spfa() {
    queue<int> Q;
    fill(dis, dis + n, inf);
    Q.push(s), ing[s] = 1, dis[s] = 0;
    while (!Q.empty()) {
      int c = Q.front();
      Q.pop();
      ing[c] = 0;
      for (int k = h[c]; ~k; k = ne[k])
        if (cap[k] > 0) {
          int v = to[k];
          if (dis[c] + cost[k] < dis[v]) {
            dis[v] = dis[c] + cost[k];
            pre[v] = k;
            if (!ing[v]) Q.push(v), ing[v] = 1;
          }
        }
    }
    return dis[t] != inf;
  }
  U flow;
  V mincost;
  pair<U, V> run(int _s, int _t) {
    s = _s, t = _t;
    flow = mincost = 0;
    while (spfa()) {
      U pl = inf;
      int p, k;
      for (p = t; p != s; p = to[k ^ 1]) pl = min(pl, cap[k = pre[p]]);
      for (p = t; p != s; p = to[k ^ 1])
        cap[k = pre[p]] -= pl, cap[k ^ 1] += pl;
      mincost += pl * dis[t];
      flow += pl;
    }
    return make_pair(flow, mincost);
  }
};
MCMF<int, int> flow;
int n, m, k, c, d, a[N], id[55][2500];
int main() {
  scanf("%d%d%d%d%d", &n, &m, &k, &c, &d);
  for (int i = (1); i < (k + 1); i++) scanf("%d", &a[i]);
  flow.ini(n * n * 4 + 10);
  int s = flow.n - 2, t = flow.n - 3;
  int cnt = 0, mx = n * 2;
  for (int i = (1); i < (n + 1); i++)
    for (int j = (0); j < (mx + 1); j++) id[i][j] = ++cnt;
  int u, v;
  for (int i = (1); i < (m + 1); i++) {
    scanf("%d%d", &u, &v);
    for (int j = (0); j < (mx); j++) {
      for (int h = (1); h < (k + 1); h++) {
        int tmp = h * h * d - (h - 1) * (h - 1) * d;
        flow.link(id[u][j], id[v][j + 1], 1, c + tmp);
        flow.link(id[v][j], id[u][j + 1], 1, c + tmp);
      }
    }
  }
  for (int i = (1); i < (n + 1); i++)
    for (int j = (0); j < (mx); j++) flow.link(id[i][j], id[i][j + 1], inf, c);
  for (int i = (1); i < (k + 1); i++) flow.link(s, id[a[i]][0], 1, 0);
  for (int j = (1); j < (mx + 1); j++) flow.link(id[1][j], t, inf, 0);
  int ans = flow.run(s, t).second;
  printf("%d\n", ans);
  return 0;
}
