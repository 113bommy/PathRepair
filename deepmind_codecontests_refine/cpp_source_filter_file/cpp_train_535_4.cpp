#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int mod = (1e9) + 7, mod2 = 998244353;
const long double eps = 1e-20;
const int siz = 1e5 + 5, siz2 = 3e5 + 5, lg = 31, block = 317, block2 = 1000,
          mxv = 5e5;
int n, m, k, c, d, crlvco[55], src = 0, snk, dis[30100], phi[30100],
                               pred[30100];
vector<int> oadj[55], mfadj[30100];
struct edge {
  int v, cap, t;
};
vector<edge> es;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;
int add(int a, int b) {
  if (max(a, b) == INT_MAX) {
    return INT_MAX;
  }
  return a + b;
}
void addedge(int u, int v, int cap, int t) {
  int sz = es.size();
  es.push_back({v, cap, t});
  mfadj[u].push_back(sz);
  es.push_back({u, 0, t});
  mfadj[v].push_back(sz + 1);
}
void build() {
  for (int i = 1; i <= n; i++) {
    if (crlvco[i]) {
      addedge(0, i, crlvco[i], 0);
    }
  }
  for (int i = 0; i <= 200; i++) {
    addedge(i * n + 1, snk, k, 0);
    for (int j = 2; j <= n; j++) {
      for (int a : oadj[j]) {
        addedge(i * n + j, (i + 1) * n + a, k, 2);
      }
      addedge(i * n + j, (i + 1) * n + j, k, 1);
    }
  }
  addedge(201 * n + 1, snk, k, 0);
}
int getcost(int ind) {
  int t = es[ind].t, sign = ind % 2 ? -1 : 1;
  if (t == 0) {
    return 0;
  }
  if (t == 1) {
    return c * sign;
  }
  int tot = es[ind].cap + es[ind ^ 1].cap;
  int diff = tot - es[ind].cap;
  if (sign == 1) {
    return c + d * (1 + diff * 2);
  }
  return sign * (c + d * (1 + (tot - 1) * 2 - diff * 2));
}
void resetdis() {
  for (int i = 1; i <= snk; i++) {
    dis[i] = INT_MAX;
  }
}
void dijkstra() {
  resetdis();
  pq.push({0, 0});
  while (!pq.empty()) {
    pair<int, int> bst = pq.top();
    pq.pop();
    int node = bst.first, tdis = bst.second;
    if (tdis > dis[node]) {
      continue;
    }
    for (int a : mfadj[node]) {
      edge &e = es[a];
      if (e.cap == 0) {
        continue;
      }
      int w = add(getcost(a), phi[node] - phi[e.v]);
      int ndis = add(tdis, w);
      if (ndis < dis[e.v]) {
        dis[e.v] = ndis;
        pred[e.v] = a;
        pq.push({e.v, ndis});
      }
    }
  }
}
void bellmanford() {
  resetdis();
  for (int i = 0; i < n - 1; i++) {
    int c = 0;
    for (auto &e : es) {
      if (e.cap == 0) {
        c++;
        continue;
      }
      int ndis = add(getcost(c), dis[es[c ^ 1].v]);
      if (ndis < dis[e.v]) {
        dis[e.v] = ndis;
        pred[e.v] = c;
      }
      c++;
    }
  }
}
int solve() {
  int tot = 0;
  while (true) {
    dijkstra();
    if (dis[snk] == INT_MAX) {
      return tot;
    }
    int cur = snk;
    while (cur != src) {
      int p = pred[cur];
      tot += getcost(p);
      es[p].cap--;
      es[p ^ 1].cap++;
      cur = es[p ^ 1].v;
    }
    for (int i = 1; i <= snk; i++) {
      phi[i] = add(phi[i], dis[i]);
    }
  }
}
int main() {
  scanf("%d%d%d%d%d", &n, &m, &k, &c, &d);
  snk = 201 * n + 2;
  for (int i = 0; i < k; i++) {
    int ai;
    scanf("%d", &ai);
    crlvco[ai]++;
  }
  for (int i = 0; i < m; i++) {
    int xi, yi;
    scanf("%d%d", &xi, &yi);
    oadj[xi].push_back(yi);
    oadj[yi].push_back(xi);
  }
  build();
  printf("%d\n", solve());
  return 0;
}
