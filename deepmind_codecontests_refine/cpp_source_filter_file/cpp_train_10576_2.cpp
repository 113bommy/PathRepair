#include <bits/stdc++.h>
using namespace std;
struct Edge {
  long long from, to, capacity, cost;
};
vector<vector<long long>> adj, cost, capacity;
const long long INF = 1e9;
void shortest_paths(long long n, long long v0, vector<long long> &d,
                    vector<long long> &p) {
  d.assign(n, INF);
  d[v0] = 0;
  vector<bool> inq(n, false);
  queue<long long> q;
  q.push(v0);
  p.assign(n, -1);
  while (!q.empty()) {
    long long u = q.front();
    q.pop();
    inq[u] = false;
    for (long long v : adj[u]) {
      if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
        d[v] = d[u] + cost[u][v];
        p[v] = u;
        if (!inq[v]) {
          inq[v] = true;
          q.push(v);
        }
      }
    }
  }
}
long long min_cost_flow(long long N, vector<Edge> edges, long long K,
                        long long s, long long t) {
  adj.assign(N, vector<long long>());
  cost.assign(N, vector<long long>(N, 0));
  capacity.assign(N, vector<long long>(N, 0));
  for (Edge e : edges) {
    adj[e.from].push_back(e.to);
    adj[e.to].push_back(e.from);
    cost[e.from][e.to] = e.cost;
    cost[e.to][e.from] = -e.cost;
    capacity[e.from][e.to] = e.capacity;
  }
  long long flow = 0;
  long long cost = 0;
  vector<long long> d, p;
  while (flow < K) {
    shortest_paths(N, s, d, p);
    if (d[t] == INF) break;
    long long f = K - flow;
    long long cur = t;
    while (cur != s) {
      f = min(f, capacity[p[cur]][cur]);
      cur = p[cur];
    }
    flow += f;
    cost += f * d[t];
    cur = t;
    while (cur != s) {
      capacity[p[cur]][cur] -= f;
      capacity[cur][p[cur]] += f;
      cur = p[cur];
    }
  }
  if (flow < K)
    return -1;
  else
    return cost;
}
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n), b(n);
  for (long long &ai : a) cin >> ai;
  for (long long &bi : b) cin >> bi;
  const long long s = n, t = n + 1;
  vector<Edge> edges;
  for (long long i = 0; i < n; i++) {
    edges.push_back({s, i, 1, a[i]});
    edges.push_back({i, t, 1, b[i]});
    if (i + 1 < n) {
      edges.push_back({i, i + 1, k, 0});
    }
  }
  cout << min_cost_flow(n + 2, edges, k, s, t);
}
