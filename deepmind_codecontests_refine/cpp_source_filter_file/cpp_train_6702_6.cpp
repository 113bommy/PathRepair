#include <bits/stdc++.h>
using namespace std;
struct edge {
  long long to, flow, cap;
  long double cost;
  long long rev;
};
struct MinCostMaxFlow {
  long long nodes;
  vector<long long> curflow, prevedge, prevnode, q;
  vector<long double> pot, prio;
  vector<bool> inqueue;
  vector<vector<edge> > graph;
  MinCostMaxFlow() {}
  MinCostMaxFlow(long long n)
      : nodes(n),
        prio(n, 0),
        curflow(n, 0),
        prevedge(n, 0),
        prevnode(n, 0),
        q(n, 0),
        pot(n, 0),
        inqueue(n, 0),
        graph(n) {}
  void addEdge(long long source, long long to, long long capacity,
               long double cost) {
    edge a = {to, 0, capacity, cost, (long long)graph[to].size()};
    edge b = {source, 0, 0, -cost, (long long)graph[source].size()};
    graph[source].push_back(a);
    graph[to].push_back(b);
  }
  void bellman_ford(long long source, vector<long double> &dist) {
    fill(dist.begin(), dist.end(), 1e9);
    dist[source] = 0;
    long long qt = 0;
    q[qt++] = source;
    for (long long qh = 0; (qh - qt) % nodes != 0; qh++) {
      long long u = q[qh % nodes];
      inqueue[u] = false;
      for (auto &e : graph[u]) {
        if (e.flow >= e.cap) continue;
        long long v = e.to;
        long double newDist = dist[u] + e.cost;
        if (dist[v] > newDist) {
          dist[v] = newDist;
          if (!inqueue[v]) {
            inqueue[v] = true;
            q[qt++ % nodes] = v;
          }
        }
      }
    }
  }
  pair<long long, long double> minCostFlow(long long source, long long dest,
                                           long long maxflow) {
    bellman_ford(source, pot);
    long long flow = 0;
    long double flow_cost = 0;
    while (flow < maxflow) {
      priority_queue<pair<long double, long long>,
                     vector<pair<long double, long long> >,
                     greater<pair<long double, long long> > >
          q;
      q.push({0, source});
      fill(prio.begin(), prio.end(), INT_MAX);
      prio[source] = 0;
      curflow[source] = INT_MAX;
      while (!q.empty()) {
        long long d = q.top().first;
        long long u = q.top().second;
        q.pop();
        if (d != prio[u]) continue;
        for (long long i = 0; i < graph[u].size(); i++) {
          edge &e = graph[u][i];
          long long v = e.to;
          if (e.flow >= e.cap) continue;
          long double newPrio = prio[u] + e.cost + pot[u] - pot[v];
          if (prio[v] > newPrio) {
            prio[v] = newPrio;
            q.push({newPrio, v});
            prevnode[v] = u;
            prevedge[v] = i;
            curflow[v] = min(curflow[u], e.cap - e.flow);
          }
        }
      }
      if (prio[dest] == INT_MAX) break;
      for (long long i = 0; i < nodes; i++) pot[i] += prio[i];
      long long df = min(curflow[dest], maxflow - flow);
      flow += df;
      for (long long v = dest; v != source; v = prevnode[v]) {
        edge &e = graph[prevnode[v]][prevedge[v]];
        e.flow += df;
        graph[v][e.rev].flow -= df;
        flow_cost += df * e.cost;
      }
    }
    return {flow, flow_cost};
  }
};
const long long N = 405;
long long n;
long long x[N], y[N];
long double dist(long long i, long long j) {
  long double xdiff = x[j] - x[i];
  long double ydiff = y[j] - y[i];
  return sqrtl(xdiff * xdiff + ydiff * ydiff);
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> x[i] >> y[i];
  MinCostMaxFlow flow(2 * n + 2);
  for (long long i = 1; i <= n; i++) {
    flow.addEdge(0, i, 2, 0);
    flow.addEdge(i + n, 2 * n + 1, 1, 0);
    for (long long j = 1; j <= n; j++) {
      if (y[i] <= y[j]) continue;
      flow.addEdge(i, j + n, 1, dist(i, j));
    }
  }
  pair<long long, long double> ans = flow.minCostFlow(0, 2 * n + 1, 1e9);
  if (ans.first != n - 1)
    cout << "-1";
  else
    cout << fixed << setprecision(12) << ans.second;
  return 0;
}
