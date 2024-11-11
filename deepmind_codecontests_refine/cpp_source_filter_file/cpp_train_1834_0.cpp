#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5;
int n, m, q;
int us[N], vs[N], ww[N];
vector<int> g[N];
long long dist[N];
int dist2[N];
vector<int> que[N * 2];
void dijkstra() {
  for (int i = 0; i < n; i++) {
    dist[i] = 1LL << 50;
  }
  priority_queue<pair<long long, int>> q;
  q.emplace(0, 0);
  dist[0] = 0;
  while (!q.empty()) {
    long long d = -q.top().first;
    int u = q.top().second;
    q.pop();
    if (dist[u] < d) continue;
    for (int id : g[u]) {
      int v = vs[id];
      if (dist[v] > dist[u] + ww[id]) {
        dist[v] = dist[u] + ww[id];
        q.emplace(-dist[v], v);
      }
    }
  }
}
int cap;
void dijkstra2() {
  if (cap == 0) return;
  que[0].push_back(0);
  for (int i = 0; i < n; i++) {
    dist2[i] = cap;
  }
  dist2[0] = 0;
  for (int d = 0; d < cap; d++) {
    while (!que[d].empty()) {
      int u = que[d].back();
      que[d].pop_back();
      if (dist2[u] < d) continue;
      for (int id : g[u]) {
        int v = vs[id];
        int w = min<long long>(cap, ww[id] + dist[u] - dist[v]);
        if (dist2[v] > dist2[u] + w && dist2[u] + w < cap) {
          dist2[v] = dist2[u] + w;
          que[dist2[v]].push_back(v);
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    dist[i] += dist2[i];
  }
  cap = 0;
}
int main() {
  cin >> n >> m >> q;
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &us[i], &vs[i], &ww[i]);
    us[i]--;
    vs[i]--;
    g[us[i]].push_back(i);
  }
  dijkstra();
  while (q--) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      dijkstra2();
      int v;
      scanf("%d", &v);
      if (dist[v - 1] == 1LL << 50) {
        puts("-1");
      } else {
        printf("%lld\n", dist[v - 1]);
      }
    } else {
      int c;
      scanf("%d", &c);
      int x = c;
      while (c--) {
        int l;
        scanf("%d", &l);
        ww[l - 1]++;
      }
      cap += x;
      dijkstra2();
    }
  }
}
