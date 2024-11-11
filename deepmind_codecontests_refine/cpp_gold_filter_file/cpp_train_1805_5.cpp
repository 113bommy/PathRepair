#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
int add(int a, int b) {
  if ((a += b) >= P) a -= P;
  return a;
}
int sub(int a, int b) {
  if ((a -= b) < 0) a += P;
  return a;
}
int mul(int a, int b) { return 1ll * a * b % P; }
int kpow(int a, int b) {
  int r = 1;
  for (; b; b >>= 1, a = mul(a, a)) {
    if (b & 1) r = mul(r, a);
  }
  return r;
}
const int inf = 1e9 + 7;
template <class U, class V>
struct ZKW {
  static const int N = 2010, M = 40040;
  int h[N], ing[N], v[N], to[M], ne[M], e, s, t, n;
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
  void spfa() {
    queue<int> Q;
    fill(dis, dis + n, inf);
    ing[t] = 1, dis[t] = 0;
    Q.push(t);
    while (!Q.empty()) {
      int c = Q.front();
      Q.pop();
      ing[c] = 0;
      for (int k = h[c]; ~k; k = ne[k]) {
        int v = to[k];
        if (cap[k ^ 1] <= 0) continue;
        if (dis[c] + cost[k ^ 1] < dis[v]) {
          dis[v] = dis[c] + cost[k ^ 1];
          if (!ing[v]) Q.push(v), ing[v] = 1;
        }
      }
    }
  }
  U flow;
  V mincost;
  bool modlable() {
    V Min = inf;
    for (int c = (0); c < (n); c++)
      if (v[c])
        for (int k = h[c]; ~k; k = ne[k]) {
          int t = to[k];
          if (!v[t] && cap[k] > 0) Min = min(Min, dis[t] + cost[k] - dis[c]);
        }
    if (Min == inf) return 0;
    for (int i = (0); i < (n); i++)
      if (v[i]) dis[i] += Min;
    return 1;
  }
  U dfs(int c, U mx) {
    if (c == t) return flow += mx, mincost += mx * dis[s], mx;
    v[c] = 1;
    U ret = 0;
    for (int k = h[c]; ~k; k = ne[k]) {
      int t = to[k];
      if (!v[t] && cap[k] > 0 && dis[c] - cost[k] == dis[t]) {
        U tmp = dfs(t, min(cap[k], mx - ret));
        cap[k] -= tmp, cap[k ^ 1] += tmp;
        ret += tmp;
        if (ret == mx) return ret;
      }
    }
    return ret;
  }
  pair<U, V> run(int _s, int _t) {
    s = _s, t = _t;
    spfa();
    flow = mincost = 0;
    do do
        memset(v, 0, sizeof(v[0]) * n);
      while (dfs(s, inf));
    while (modlable());
    return make_pair(flow, mincost);
  }
};
ZKW<int, int> G;
const int N = 100005;
int l[N], r[N], da[N];
vector<int> V;
int T, n, m, k;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  T = 1;
  while (T--) {
    cin >> m >> k;
    V.clear();
    for (int i = (0); i < (m); i++)
      cin >> l[i] >> r[i] >> da[i], V.push_back(l[i]), r[i] += l[i] - 1;
    V.push_back(0), V.push_back(inf * 2);
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());
    n = (int)V.size();
    G.ini(n);
    for (int i = (1); i < (n); i++) G.link(i - 1, i, k, 0);
    int st = G.e;
    for (int i = (0); i < (m); i++) {
      l[i] = lower_bound(V.begin(), V.end(), l[i]) - V.begin();
      r[i] = upper_bound(V.begin(), V.end(), r[i]) - V.begin();
      G.link(l[i], r[i], 1, -da[i]);
    }
    G.run(0, n - 1);
    for (int i = (0); i < (m); i++) {
      if (G.cap[i * 2 + st] == 0)
        cout << 1;
      else
        cout << 0;
      cout << " ";
    }
  }
  return 0;
}
