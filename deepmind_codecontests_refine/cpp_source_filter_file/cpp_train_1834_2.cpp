#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e15;
struct Edge {
  int t, nx, w;
} e[100010 << 1];
queue<int> g[100010];
long long d[100010], f[100010], y;
int i, j, k, n, m, q, x, h[100010];
struct Node {
  int x;
  Node(int x = 0) : x(x) {}
  bool operator<(Node a) const { return d[x] > d[a.x]; }
};
priority_queue<Node> Q;
inline void Dij() {
  for (i = 2; i <= n; i++) d[i] = INF;
  Q.push(Node(1));
  while (!Q.empty()) {
    x = Q.top().x;
    Q.pop();
    for (int j = h[x]; j; j = e[j].nx)
      if (d[e[j].t] > d[x] + e[j].w) {
        d[e[j].t] = d[x] + e[j].w;
        Q.push(e[j].t);
      }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> q;
  for (i = 1; i <= m; i++) {
    cin >> x >> e[i].t >> e[i].w;
    e[i].nx = h[x], h[x] = i;
  }
  Dij();
  while (q--) {
    cin >> x >> k;
    if (x == 1)
      cout << (d[k] >= INF ? -1 : d[k]);
    else {
      for (i = 1; i <= k; i++) {
        cin >> x;
        e[x].w++;
      }
      for (i = 2; i <= n; i++) f[i] = INF;
      g[(m = 0)].push(1);
      k = min(k, n - 1);
      for (i = 0; i <= m; i++) {
        while (!g[i].empty()) {
          x = g[i].front();
          g[i].pop();
          if (i > f[x]) continue;
          for (j = h[x]; j; j = e[j].nx) {
            y = f[x] + d[x] + e[j].w - d[e[j].t];
            if (f[e[j].t] > y) {
              f[e[j].t] = y;
              if (y <= k) {
                g[y].push(e[j].t);
                if (y > m) m = y;
              }
            }
          }
        }
      }
      for (i = 2; i <= n; i++) {
        d[i] = min(INF, d[i] + f[i]);
      }
    }
  }
  return 0;
}
