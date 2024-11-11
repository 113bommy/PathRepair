#include <bits/stdc++.h>
using namespace std;
int dis, t, hull[422], k, sz, ch, ch2, n, m, mini = -1, w, i, j, x[422], y[422],
                                             r[422];
long long R;
struct MaxFlowDinic {
  struct Edge {
    int next;
    size_t inv;
    int res;
  };
  int n;
  vector<vector<Edge> > graph;
  vector<int> q, l, start;
  void init(int _n) {
    n = _n;
    graph.resize(n);
    for (int i = 0; i < n; i++) graph[i].clear();
  }
  void add_edge(int s, int e, int cap, int caprev = 0) {
    Edge forward{e, graph[e].size(), cap};
    Edge reverse{s, graph[s].size(), caprev};
    graph[s].push_back(forward);
    graph[e].push_back(reverse);
  }
  bool assign_level(int source, int sink) {
    int t = 0;
    memset(&l[0], 0, sizeof(l[0]) * l.size());
    l[source] = 1;
    q[t++] = source;
    for (int h = 0; h < t && !l[sink]; h++) {
      int cur = q[h];
      for (const auto& e : graph[cur]) {
        if (l[e.next] || e.res == 0) continue;
        l[e.next] = l[cur] + 1;
        q[t++] = e.next;
      }
    }
    return l[sink] != 0;
  }
  int block_flow(int cur, int sink, int current) {
    if (cur == sink) return current;
    for (int& i = start[cur]; i < graph[cur].size(); i++) {
      auto& e = graph[cur][i];
      if (e.res == 0 || l[e.next] != l[cur] + 1) continue;
      if (int res = block_flow(e.next, sink, min(e.res, current))) {
        e.res -= res;
        graph[e.next][e.inv].res += res;
        return res;
      }
    }
    return 0;
  }
  int solve(int source, int sink) {
    q.resize(n);
    l.resize(n);
    start.resize(n);
    int ans = 0;
    while (assign_level(source, sink)) {
      memset(&start[0], 0, sizeof(start[0]) * n);
      while (int flow = block_flow(source, sink, numeric_limits<int>::max()))
        ans += flow;
    }
    return ans;
  }
};
long long sq(long long T) { return T * T; }
struct A {
  long long x, y;
} d[40004];
int ccw(A a, A b, A c) {
  long long ch =
      a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
  if (ch < 0) return -1;
  if (ch > 0) return 1;
  return 0;
}
bool cmp(A aa, A bb) {
  if (ccw(d[0], aa, bb))
    return ccw(d[0], aa, bb) > 0;
  else
    return aa.x - d[0].x < bb.x - d[0].x;
}
int main() {
  scanf("%d%d", &n, &w);
  for (i = 0; i < n; i++) {
    scanf("%d%d", &x[i], &y[i]);
  }
  dis = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      dis = max(dis, x[i] - x[j]);
    }
  }
  scanf("%d", &m);
  for (i = 0; i < m; i++) {
    scanf("%d%d%d", &x[n + i], &y[n + i], &r[n + i]);
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      d[sz++] = {x[i] - x[j], y[i] - y[j]};
      if (mini == -1 || (d[sz - 1].x < d[mini].x) ||
          (d[sz - 1].x == d[mini].x && d[sz - 1].y < d[mini].y))
        mini = sz - 1;
    }
  }
  swap(d[0], d[mini]);
  sort(d + 1, d + sz, cmp);
  hull[t++] = 0;
  hull[t++] = 1;
  for (i = 2; i < sz; i++) {
    while (t > 1 && ccw(d[hull[t - 2]], d[hull[t - 1]], d[i]) <= 0) t--;
    hull[t++] = i;
  }
  hull[t] = hull[0];
  MaxFlowDinic G;
  G.init(2 * m + 2);
  for (i = 0; i < m; i++) {
    if (x[n + i] - r[n + i] < dis) {
      G.add_edge(2 * m, 2 * i, 1e9);
    }
    if (x[n + i] + r[n + i] + dis > w) {
      G.add_edge(2 * i + 1, 2 * m + 1, 1e9);
    }
    G.add_edge(2 * i, 2 * i + 1, 1);
  }
  A p, q, o;
  for (i = 0; i < m; i++) {
    for (j = i + 1; j < m; j++) {
      o.x = x[n + j] - x[n + i];
      o.y = y[n + j] - y[n + i];
      R = r[n + j] + r[n + i];
      ch = 0;
      ch2 = 0;
      for (k = 0; k < t; k++) {
        p = d[hull[k]], q = d[hull[k + 1]];
        if (ccw(p, q, o) >= 0)
          ch++;
        else {
          if ((sq(p.x - q.x) + sq(p.y - q.y)) +
                  (sq(o.x - q.x) + sq(o.y - q.y)) <=
              (sq(p.x - o.x) + sq(p.y - o.y))) {
            if ((sq(o.x - q.x) + sq(o.y - q.y)) < sq(R)) ch2 = 1;
          } else if ((sq(p.x - q.x) + sq(p.y - q.y)) +
                         (sq(p.x - o.x) + sq(p.y - o.y)) <=
                     (sq(o.x - q.x) + sq(o.y - q.y))) {
            if ((sq(p.x - o.x) + sq(p.y - o.y)) < sq(R)) ch2 = 1;
          } else {
            if (sq(p.x * q.y + q.x * o.y + o.x * p.y - p.y * q.x - q.y * o.x -
                   o.y * p.x) < (sq(p.x - q.x) + sq(p.y - q.y)) * sq(R))
              ch2 = 1;
          }
        }
      }
      if (ch == t || ch2 == 1) {
        G.add_edge(2 * i + 1, 2 * j, 1e9);
        G.add_edge(2 * j + 1, 2 * i, 1e9);
      }
    }
  }
  printf("%d", G.solve(2 * m, 2 * m + 1));
}
