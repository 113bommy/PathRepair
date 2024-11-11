#include <bits/stdc++.h>
using namespace std;
struct Edge {
  long long from, to, capacity, cost;
};
vector<vector<long long>> adj, cost, capacity;
const long long INF = 1e9;
void shortest_paths(long long n, long long v0, vector<long long>& d,
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
  if (flow < K) {
    cout << "flow: " << flow << " K : " << K << " and cost: " << cost << endl;
    return -1;
  } else {
    return cost;
  }
}
int main() {
  long long n;
  cin >> n;
  long long k;
  cin >> k;
  vector<Edge> edges;
  vector<long long> a(n), b(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long i = 0; i < n; i++) cin >> b[i];
  for (long long i = 1; i <= n; i++) {
    Edge prepare;
    prepare.from = 0;
    prepare.to = i;
    prepare.capacity = 1;
    prepare.cost = a[i - 1];
    edges.push_back(prepare);
    if (i < n) {
      Edge front;
      front.from = i;
      front.to = i + 1;
      front.capacity = k;
      front.cost = 0;
      edges.push_back(front);
    }
    Edge print;
    print.from = i;
    print.to = n + 1;
    print.capacity = 1;
    print.cost = b[i - 1];
    edges.push_back(print);
  }
  cout << min_cost_flow(n + 2, edges, k, 0, n + 1) << endl;
}
