#include <bits/stdc++.h>
using namespace std;
struct mfg {
  struct edge {
    int id, wg, anti;
    edge() {}
    edge(int id, int wg) : id(id), wg(wg) {}
  };
  int n, source, sink;
  vector<edge> e[610];
  void init(int _n) {
    n = _n;
    source = n - 1;
    sink = n;
    for (int i = (1); i <= (n); i++) e[i].clear();
  }
  void ins(int x, int y, int z) {
    e[x].push_back(edge(y, z));
    (--e[x].end())->anti = e[y].size();
    e[y].push_back(edge(x, 0));
    (--e[y].end())->anti = e[x].size() - 1;
  }
  int flow, found, augc;
  int cur[610], h[610], vh[610];
  void sap(int m) {
    if (m == sink) {
      found = 1;
      flow += augc;
      return;
    }
    int augc2 = augc;
    for (int it = (cur[m]); it <= ((int((e[m]).size())) - 1); it++) {
      edge z = e[m][it];
      if (z.wg > 0 && h[m] == h[z.id] + 1) {
        augc = min(augc, z.wg);
        cur[m] = it;
        sap(z.id);
        if (found) {
          e[m][it].wg -= augc;
          e[z.id][z.anti].wg += augc;
          return;
        }
        if (h[source] >= sink) return;
        augc = augc2;
      }
    }
    int minh = sink - 1, minhi = 0;
    for (int it = (0); it <= ((int((e[m]).size())) - 1); it++)
      if (e[m][it].wg > 0 && h[e[m][it].id] < minh) {
        minh = h[e[m][it].id];
        minhi = it;
      }
    vh[h[m]]--;
    if (!vh[h[m]]) h[source] = sink;
    h[m] = minh + 1;
    vh[h[m]]++;
    cur[m] = minhi;
  }
  int maxflow() {
    flow = 0;
    memset(h, 0, sizeof h);
    memset(vh, 0, sizeof vh);
    vh[0] = sink;
    for (int i = (1); i <= (sink); i++) cur[i] = 0;
    while (h[source] < sink) {
      augc = 0x7fffffff;
      found = 0;
      sap(source);
    }
    return flow;
  }
  void getmatching(int *d, int n) {
    for (int i = (1); i <= (n); i++)
      for (typeof((e[i]).begin()) it = (e[i]).begin(); it != (e[i]).end(); it++)
        if (!it->wg && n + 1 <= it->id && it->id <= n * 2) d[i] = it->id - n;
  }
} g;
int d[610], w[610], belong[610];
vector<int> v[610];
void lemon() {
  int n;
  scanf("%d", &n);
  for (int i = (1); i <= (n); i++) {
    int y;
    scanf("%d", &y);
    for (int k = (1); k <= (y); k++) {
      int z;
      scanf("%d", &z);
      v[i].push_back(z);
    }
  }
  g.init(n * 2 + 2);
  int source = n * 2 + 1, sink = n * 2 + 2;
  for (int i = (1); i <= (n); i++) g.ins(source, i, 1);
  for (int i = (n + 1); i <= (n * 2); i++) g.ins(i, sink, 1);
  for (int i = (1); i <= (n); i++)
    for (typeof((v[i]).begin()) it = (v[i]).begin(); it != (v[i]).end(); it++)
      g.ins(i, (*it) + n, 1);
  g.maxflow();
  g.getmatching(d, n);
  for (int i = (1); i <= (n); i++) belong[d[i]] = i;
  g.init(n + 2);
  source = n + 1, sink = n + 2;
  for (int i = (1); i <= (n); i++) scanf("%d", &w[i]), w[i] = -w[i];
  int fall = 0;
  for (int i = (1); i <= (n); i++)
    if (w[i] > 0)
      g.ins(i, sink, w[i]), fall += w[i];
    else
      g.ins(source, i, -w[i]);
  for (int i = (1); i <= (n); i++)
    for (typeof((v[i]).begin()) it = (v[i]).begin(); it != (v[i]).end(); it++)
      if (*it != d[i]) g.ins(belong[*it], i, 1000000000);
  printf("%d\n", g.maxflow() - fall);
}
int main() {
  ios::sync_with_stdio(true);
  lemon();
  return 0;
}
