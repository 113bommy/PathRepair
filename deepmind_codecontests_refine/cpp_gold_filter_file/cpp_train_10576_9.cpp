#include <bits/stdc++.h>
using namespace std;
struct Edge {
  long long from, to, capacity, cost;
};
vector<vector<long long>> adj, cost, capacity;
const long long INF = 1e18;
void shortestPaths(long long n, long long v0, vector<long long>& d,
                   vector<long long>& p) {
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
long long minCostFlow(long long n, vector<Edge> edges, long long k, long long s,
                      long long t) {
  adj.assign(n, vector<long long>());
  cost.assign(n, vector<long long>(n, 0));
  capacity.assign(n, vector<long long>(n, 0));
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
  while (flow < k) {
    shortestPaths(n, s, d, p);
    if (d[t] == INF) break;
    long long f = k - flow;
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
  if (flow < k)
    return -1;
  else
    return cost;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, k, x;
  cin >> n >> k;
  vector<Edge> edges;
  for (long long i = 1; i <= n; ++i) {
    cin >> x;
    edges.push_back({0, i, 1, x});
  }
  for (long long i = 1; i <= n; ++i) {
    cin >> x;
    edges.push_back({i, n + 1, 1, x});
  }
  for (long long i = 1; i < n; ++i) edges.push_back({i, i + 1, k, 0});
  cout << minCostFlow(n + 2, edges, k, 0, n + 1) << '\n';
}
