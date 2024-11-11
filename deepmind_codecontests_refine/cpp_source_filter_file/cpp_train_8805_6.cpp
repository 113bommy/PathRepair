#include <bits/stdc++.h>
using namespace std;
struct MaxFlow {
  const long long INF = 1e18;
  struct Edge {
    int u, v;
    long long c, rc;
    long long cost;
    shared_ptr<long long> flow;
    Edge(int _u, int _v, long long _c, long long _cost = 0)
        : u(_u), v(_v), c(_c), cost(_cost) {
      rc = 0;
    }
  };
  struct FlowTracker {
    shared_ptr<long long> flow;
    long long cap, rcap;
    bool dir;
    FlowTracker(long long _cap, long long _rcap, shared_ptr<long long> _flow,
                int _dir)
        : cap(_cap), rcap(_rcap), flow(_flow), dir(_dir) {}
    long long rem() const {
      if (dir == 0) {
        return cap - *flow;
      } else {
        return rcap + *flow;
      }
    }
    void add_flow(long long f) {
      if (dir == 0)
        *flow += f;
      else
        *flow -= f;
      assert(*flow <= cap);
      assert(-*flow <= rcap);
    }
    operator long long() const { return rem(); }
    void operator-=(long long x) { add_flow(x); }
    void operator+=(long long x) { add_flow(-x); }
  };
  int source, sink;
  vector<vector<int> > adj;
  vector<vector<long long> > cost;
  vector<vector<FlowTracker> > cap;
  vector<Edge> edges;
  MaxFlow(int _source, int _sink) : source(_source), sink(_sink) {
    assert(source != sink);
  }
  int add_edge(int u, int v, long long c, long long cost = 0) {
    edges.push_back(Edge(u, v, c, cost));
    return edges.size() - 1;
  }
  vector<int> now, lvl;
  vector<long long> pot;
  void prep() {
    vector<int> indices = {source, sink};
    for (auto &edge : edges) {
      indices.push_back(edge.u);
      indices.push_back(edge.v);
    }
    sort(indices.begin(), indices.end());
    indices.erase(unique(indices.begin(), indices.end()), indices.end());
    source =
        lower_bound(indices.begin(), indices.end(), source) - indices.begin();
    sink = lower_bound(indices.begin(), indices.end(), sink) - indices.begin();
    int max_id = indices.size() - 1;
    adj.resize(max_id + 1);
    cost.resize(max_id + 1);
    cap.resize(max_id + 1);
    now.resize(max_id + 1);
    lvl.resize(max_id + 1);
    pot.resize(max_id + 1);
    for (auto &edge : edges) {
      edge.u =
          lower_bound(indices.begin(), indices.end(), edge.u) - indices.begin();
      edge.v =
          lower_bound(indices.begin(), indices.end(), edge.v) - indices.begin();
      auto flow = make_shared<long long>(0);
      adj[edge.u].push_back(edge.v);
      cost[edge.u].push_back(edge.cost);
      cap[edge.u].push_back(FlowTracker(edge.c, edge.rc, flow, 0));
      if (edge.u != edge.v) {
        adj[edge.v].push_back(edge.u);
        cost[edge.v].push_back(-edge.cost);
        cap[edge.v].push_back(FlowTracker(edge.c, edge.rc, flow, 1));
      }
      assert(cap[edge.u].back() == edge.c);
      edge.flow = flow;
    }
  }
  bool dinic_bfs() {
    fill(now.begin(), now.end(), 0);
    fill(lvl.begin(), lvl.end(), 0);
    lvl[source] = 1;
    vector<int> bfs(1, source);
    for (int i = 0; i < bfs.size(); ++i) {
      int u = bfs[i];
      for (int j = 0; j < adj[u].size(); ++j) {
        int v = adj[u][j];
        if (cap[u][j] > 0 && lvl[v] == 0) {
          lvl[v] = lvl[u] + 1;
          bfs.push_back(v);
        }
      }
    }
    return lvl[sink] > 0;
  }
  long long dinic_dfs(int u, long long flow) {
    if (u == sink) return flow;
    while (now[u] < adj[u].size()) {
      int v = adj[u][now[u]];
      if (lvl[v] == lvl[u] + 1 && cap[u][now[u]] != 0) {
        long long res = dinic_dfs(v, min(flow, (long long)cap[u][now[u]]));
        if (res > 0) {
          cap[u][now[u]] -= res;
          return res;
        }
      }
      ++now[u];
    }
    return 0;
  }
  long long max_flow() {
    prep();
    long long ans = 0;
    while (dinic_bfs()) {
      long long cur = 0;
      do {
        cur = dinic_dfs(source, INF);
        ans += cur;
      } while (cur > 0);
    }
    return ans;
  }
  void bellman_ford() {
    vector<long long> dist(adj.size(), INF);
    dist[source] = 0;
    for (int times = 0; times < dist.size(); ++times)
      for (auto &edge : edges)
        dist[edge.v] = min(dist[edge.v], dist[edge.u] + edge.cost);
    pot = dist;
  }
  long long dijkstra(vector<long long> &dist, vector<int> &last_node,
                     vector<int> &last_index) {
    dist[source] = 0;
    vector<long long> flow(dist.size());
    flow[source] = INF;
    vector<bool> visited(dist.size());
    priority_queue<pair<long long, int> > pq;
    pq.push({0, source});
    while (!pq.empty()) {
      int u = pq.top().second;
      pq.pop();
      if (visited[u]) continue;
      visited[u] = true;
      for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (!visited[v] && cap[u][i])
          if (dist[u] + cost[u][i] + pot[u] - pot[v] < dist[v]) {
            dist[v] = dist[u] + cost[u][i] + pot[u] - pot[v];
            last_node[v] = u;
            last_index[v] = i;
            flow[v] = min(flow[u], (long long)cap[u][i]);
            pq.push({-dist[v], v});
          }
      }
    }
    return flow[sink];
  }
  pair<long long, long long> min_cost_flow() {
    prep();
    bool has_negative = false;
    for (auto &edge : edges)
      if (edge.cost < 0) has_negative = true;
    if (has_negative) bellman_ford();
    long long total_flow = 0;
    long long total_cost = 0;
    while (true) {
      vector<long long> dist(adj.size(), INF);
      vector<int> last_node(dist.size()), last_index(dist.size());
      long long flow = dijkstra(dist, last_node, last_index);
      if (flow == 0) break;
      for (int u = sink; u != source; u = last_node[u])
        cap[last_node[u]][last_index[u]] -= flow;
      for (int i = 0; i < adj.size(); ++i) pot[i] += dist[i];
      total_flow += flow;
      total_cost += pot[sink] * flow;
    }
    return {total_flow, total_cost};
  }
  long long flow_on_edge(int edge_index) {
    assert(edge_index < edges.size());
    return *edges[edge_index].flow;
  }
};
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1), c(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> c[i];
  int source = 0, pre_sink = n * 2 + 1, sink = n * 2 + 2;
  MaxFlow mf(source, sink);
  mf.add_edge(pre_sink, sink, k);
  mf.add_edge(source, pre_sink, k);
  long long hi = 1e3;
  for (int i = 1; i <= n; ++i) {
    mf.add_edge(i, i + n, 1, -hi);
    mf.add_edge(source, i, 1, c[a[i]]);
    mf.add_edge(i + n, pre_sink, 1, 0);
    for (int j = i + 1; j <= n; ++j) {
      mf.add_edge(i + n, j, 1, (a[i] == a[j] ? 0 : c[a[j]]));
    }
  }
  auto ans = mf.min_cost_flow();
  cout << ans.second + n * hi << '\n';
}
