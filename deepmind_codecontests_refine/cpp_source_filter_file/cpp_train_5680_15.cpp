#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
namespace EK {
const long long INF = 1E18;
struct Edge {
  int from, to;
  long long cap, flow, cost;
  Edge(int u, int v, long long c, long long f, long long w)
      : from(u), to(v), cap(c), flow(f), cost(w) {}
};
int n, s, t;
int p[MAXN];
long long a[MAXN], d[MAXN];
bool inq[MAXN];
vector<Edge> edges;
vector<int> g[MAXN];
void init(int v, int a, int b) {
  n = v, s = a, t = b;
  edges.clear();
  for (int i = 1; i <= n; i++) g[i].clear();
}
void addEdge(int from, int to, long long cap, long long cost) {
  edges.push_back(Edge(from, to, cap, 0, cost));
  edges.push_back(Edge(to, from, 0, 0, -cost));
  g[from].push_back(edges.size() - 2);
  g[to].push_back(edges.size() - 1);
}
bool SPFA(long long& flow, long long& cost) {
  for (int i = 1; i <= n; i++) d[i] = INF;
  d[s] = 0;
  for (int i = 1; i <= n; i++) inq[s] = 0;
  inq[s] = 1;
  queue<int> q;
  q.push(s);
  a[s] = INF;
  p[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    inq[u] = 0;
    for (int i = 0; i < g[u].size(); i++) {
      Edge& e = edges[g[u][i]];
      if (e.cap > e.flow && d[u] + e.cost < d[e.to]) {
        d[e.to] = d[u] + e.cost;
        a[e.to] = min(a[u], e.cap - e.flow);
        p[e.to] = g[u][i];
        if (!inq[e.to]) q.push(e.to), inq[e.to] = 1;
      }
    }
  }
  if (d[t] == INF) return 0;
  flow += a[t], cost += a[t] * d[t];
  for (int u = t; u != s; u = edges[p[u]].from) {
    edges[p[u]].flow += a[t];
    edges[p[u] ^ 1].flow -= a[t];
  }
  return 1;
}
pair<long long, long long> MCMF() {
  long long flow = 0, cost = 0;
  while (SPFA(flow, cost))
    ;
  return make_pair(flow, cost);
}
}  // namespace EK
namespace {
int n, s, t;
long long d[MAXN];
void init(int v) {
  n = v, s = v + 1, t = v + 2;
  EK::init(n + 2, s, t);
  for (int i = 1; i <= n; i++) d[i] = 0;
}
void addEdge(int from, int to, long long mn, long long mx, long long cost) {
  EK::addEdge(from, to, mx - mn, cost);
  d[from] -= mn, d[to] += mn;
}
long long work() {
  long long sum = 0;
  for (int i = 1; i <= n; i++)
    if (d[i] > 0)
      EK::addEdge(s, i, d[i], 0), sum += d[i];
    else if (d[i] < 0)
      EK::addEdge(i, t, -d[i], 0);
  auto ret = EK::MCMF();
  return ret.first == sum ? ret.second : -1;
}
}  // namespace
const int INF = 1E9;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  long long ans = 0;
  init(n);
  addEdge(n, 1, 0, INF, 0);
  for (int i = 1; i <= m; i++) {
    int u, v, c, f;
    scanf("%d%d%d%d", &u, &v, &c, &f);
    addEdge(u, v, f, f, 0);
    if (c >= f) {
      addEdge(v, u, 0, f, 1);
      addEdge(u, v, 0, c - f, 1);
      addEdge(u, v, 0, INF, 2);
    } else {
      ans += f - c;
      addEdge(v, u, 0, c, 1);
      addEdge(u, v, 0, f - c, 0);
      addEdge(u, v, 0, INF, 2);
    }
  }
  ans += work();
  printf("%lld\n", ans);
  return 0;
}
