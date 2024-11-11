#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
int source, sink, tot;
struct edge {
  int b, u, c, f, back;
};
vector<edge> g[100010];
void add_edge(int a, int b, int u, int c) {
  edge e1 = {b, u, c, 0, (int)g[b].size()};
  edge e2 = {a, 0, -c, 0, (int)g[a].size()};
  g[a].push_back(e1);
  g[b].push_back(e2);
}
pair<int, int> min_cost(int k) {
  int flow = 0, cost = 0;
  while (flow < k) {
    vector<int> id(tot, 0), d(tot, 100000000), p(tot), q(tot), p_edge(tot);
    int qh = 0, qt = 0;
    q[qt++] = source;
    d[source] = 0;
    while (qh != qt) {
      int v = q[qh++];
      id[v] = 2;
      if (qh == tot) qh = 0;
      for (int i = 0; i < (int)g[v].size(); ++i) {
        edge &r = g[v][i];
        if (r.f < r.u && d[v] + r.c < d[r.b]) {
          d[r.b] = d[v] + r.c;
          if (id[r.b] == 0) {
            q[qt++] = r.b;
            if (qt == tot) qt = 0;
          } else if (id[r.b] == 2) {
            if (--qh == -1) qh = tot - 1;
            q[qh] = r.b;
          }
          id[r.b] = 1;
          p[r.b] = v;
          p_edge[r.b] = i;
        }
      }
    }
    if (d[sink] == 100000000) break;
    int addflow = k - flow;
    for (int v = sink; v != source; v = p[v]) {
      int pv = p[v], pr = p_edge[v];
      addflow = min(addflow, g[pv][pr].u - g[pv][pr].f);
    }
    for (int v = sink; v != source; v = p[v]) {
      int pv = p[v], pr = p_edge[v], r = g[pv][pr].back;
      g[pv][pr].f += addflow;
      g[v][r].f -= addflow;
      cost += g[pv][pr].c * addflow;
    }
    flow += addflow;
  }
  return {cost, flow};
}
int a[100002], counter[100002];
int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    source = n + n, sink = n + n + 1, tot = sink + 1;
    for (int i = 0; i < tot; ++i) g[i].clear();
    for (int i = 0; i < n; ++i) {
      add_edge(source, i, 1, 0);
      add_edge(i, i + n, 1, 0);
      add_edge(i + n, sink, 1, 0);
    }
    for (int i = 0; i < n; ++i) {
      memset(counter, 0, sizeof(counter));
      for (int j = i + 1; j < n; ++j) {
        ++counter[a[j]];
        if (abs(a[i] - a[j]) == 1) {
          if (counter[a[j]] < 4) add_edge(i + n, j, 1, -1);
        }
      }
    }
    for (int i = 0; i < n; ++i) a[i] %= 7;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 7; ++j) counter[j] = 0;
      for (int j = i + 1; j < n; ++j) {
        ++counter[a[j]];
        if (a[i] == a[j]) {
          if (counter[a[j]] < 4) add_edge(i + n, j, 1, -1);
        }
      }
    }
    printf("%d\n", 2 - min_cost(2).first);
  }
  return 0;
}
