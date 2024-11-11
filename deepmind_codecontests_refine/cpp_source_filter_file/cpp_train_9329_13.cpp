#include <bits/stdc++.h>
using namespace std;
template <class FL, class CO>
struct MCMF {
  static const int N = 102;
  static const int M = 10099;
  int minf = 1e9;
  int head[N], pre[N], to[M], ne[M];
  int es, s, t, n;
  bool vis[N];
  FL cap[M], mflow;
  CO cost[M], dis[N], mcost;
  void init(int _n) {
    fill(head, head + 1 + (n = _n), -1);
    es = 0;
  }
  void add(int u, int v, FL c, CO w) {
    to[es] = v;
    cap[es] = c;
    cost[es] = w;
    ne[es] = head[u];
    head[u] = es++;
    to[es] = u;
    cap[es] = 0;
    cost[es] = -w;
    ne[es] = head[v];
    head[v] = es++;
  }
  bool spfa() {
    fill(dis, dis + 1 + n, minf);
    fill(vis, vis + 1 + n, false);
    queue<int> Q;
    Q.push(s);
    vis[s] = true;
    dis[s] = 0;
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      vis[u] = false;
      ;
      for (int i = head[u]; i != -1; i = ne[i]) {
        int v = to[i];
        if (cap[i] > 0 && dis[u] + cost[i] < dis[v]) {
          dis[v] = dis[u] + cost[i];
          pre[v] = i;
          if (!vis[v]) {
            vis[v] = true;
            Q.push(v);
          }
        }
      }
    }
    return dis[t] != minf;
  }
  pair<FL, CO> solve(int _s, int _t) {
    s = _s;
    t = _t;
    mflow = mcost = 0;
    while (spfa()) {
      FL tmp = minf;
      int v;
      for (int i = t; i != s; i = to[v ^ 1]) {
        tmp = min(tmp, cap[v = pre[i]]);
      }
      for (int i = t; i != s; i = to[v ^ 1]) {
        v = pre[i];
        cap[v] -= tmp;
        cap[v ^ 1] += tmp;
      }
      mcost += tmp * dis[t];
      mflow += tmp;
    }
    return make_pair(mflow, mcost);
  }
};
int main() {
  pair<int, int> qu[50];
  int n, q;
  scanf("%d%d", &n, &q);
  MCMF<int, long long> x;
  int s, t;
  s = 2 * n;
  t = s + 1;
  x.init(t);
  for (int i = 0; i < n; i++) {
    qu[i].first = 0;
    qu[i].second = n - 1;
    for (int j = 0; j < n; j++) {
      x.add(s, i, 1, j * 2 + 1);
    }
  }
  for (int i = 0; i < n; i++) x.add(i + n, t, 1, 0);
  int l, r, v, ty;
  while (q--) {
    scanf("%d%d%d%d", &ty, &l, &r, &v);
    if (ty == 1) {
      for (int i = l - 1; i < r; i++) {
        qu[i].first = max(qu[i].first, v - 1);
      }
    } else {
      for (int i = l - 1; i < r; i++) {
        qu[i].second = min(qu[i].second, v - 1);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = qu[i].first; j <= qu[i].second; j++) {
      x.add(j, i + n, 1, 0);
    }
  }
  pair<int, long long> tmp = x.solve(s, t);
  if (tmp.first != n)
    printf("-1\n");
  else
    printf("%I64d\n", tmp.second);
  return 0;
}
