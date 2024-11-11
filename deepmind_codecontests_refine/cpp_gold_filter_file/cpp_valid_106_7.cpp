#include <bits/stdc++.h>
using namespace std;
template <typename num_t>
inline void add_mod(num_t& a, const long long& b, const int& m) {
  a = (a + b) % m;
  if (a < 0) a += m;
}
template <typename num_t>
inline bool update_max(num_t& a, const num_t& b) {
  return a < b ? a = b, true : false;
}
template <typename num_t>
inline bool update_min(num_t& a, const num_t& b) {
  return a > b ? a = b, true : false;
}
template <typename num_t>
num_t gcd(num_t lhs, num_t rhs) {
  return !lhs ? rhs : gcd(rhs % lhs, lhs);
}
template <typename num_t>
num_t pw(num_t n, num_t k, num_t mod) {
  num_t res = 1;
  for (; k > 0; k >>= 1) {
    if (k & 1) res = 1ll * res * n % mod;
    n = 1ll * n * n % mod;
  }
  return res;
}
const int inf = 1e9 + 7;
const int mod = 1e9 + 7;
const long long ll_inf = 9ll * inf * inf;
const int max_n = 1e5 + 7;
template <typename num_t, typename num_q>
class MinCostMaxFlow {
 public:
  static const int MAX_EDGES = 80007;
  static const int MAX_VERTEXES = 20007;
  static const num_t inf = ::inf;
  int adj[MAX_EDGES], link[MAX_EDGES], head[MAX_VERTEXES];
  num_t cap[MAX_EDGES], flow[MAX_EDGES];
  num_q cost[MAX_EDGES], pot[MAX_VERTEXES], dist[MAX_VERTEXES];
  int n, source, sink, edge_count;
  int which[MAX_VERTEXES];
  num_t max_flow;
  num_q min_cost;
  bool spfa() {
    static int queue[MAX_EDGES];
    static bool can[MAX_VERTEXES];
    fill_n(dist, n, inf);
    fill_n(can, n, false);
    int top = 0;
    queue[top++] = source;
    can[source] = true;
    dist[source] = 0;
    for (int i = 0; i < top; ++i) {
      int u = queue[i];
      for (int e = head[u]; e != -1; e = link[e]) {
        int v = adj[e];
        if (flow[e] < cap[e] && dist[v] > dist[u] + cost[e]) {
          dist[v] = dist[u] + cost[e];
          which[v] = e;
          if (!can[v]) {
            can[v] = true;
            queue[top++] = v;
          }
        }
      }
      can[u] = false;
    }
    return dist[sink] < inf;
  }
  void init(int _n, int _s, int _t) {
    n = _n;
    source = _s;
    sink = _t;
    edge_count = 0;
    fill_n(head, n, -1);
    max_flow = min_cost = 0;
  }
  inline void add_(int u, int v, num_t cap_, num_q cost_) {
    adj[edge_count] = v;
    flow[edge_count] = 0;
    cap[edge_count] = cap_;
    cost[edge_count] = cost_;
    link[edge_count] = head[u];
    head[u] = edge_count++;
  }
  void add_edge(int u, int v, num_t cap_, num_q cost_) {
    add_(u, v, cap_, cost_);
    add_(v, u, 0, -cost_);
  }
  num_t process(num_t desired_flow = inf, bool reset = false) {
    if (reset) {
      max_flow = min_cost = 0;
      fill_n(flow, edge_count, 0);
    }
    while (max_flow < desired_flow) {
      if (!spfa()) return 0;
      num_t delta = desired_flow - max_flow;
      for (int v = sink, e = which[v]; v != source;
           v = adj[e ^ 1], e = which[v]) {
        delta = min(delta, cap[e] - flow[e]);
      }
      for (int v = sink, e = which[v]; v != source;
           v = adj[e ^ 1], e = which[v]) {
        flow[e] += delta;
        flow[e ^ 1] -= delta;
      }
      max_flow += delta;
      min_cost += delta * dist[sink];
    }
    return max_flow;
  }
};
MinCostMaxFlow<int, int> mcmf;
void solve() {
  int n, k;
  cin >> n >> k;
  k = min(k, 1 << (n - 1));
  vector<int> a(1 << n);
  for (auto& x : a) {
    cin >> x;
  }
  const int max_heap_sz = k * n * 2 + 1;
  priority_queue<pair<int, pair<int, int>>> heap;
  for (int i = (0), _b = (1 << n); i < _b; ++i) {
    for (int t = (0), _b = (n); t < _b; ++t) {
      int j = i ^ (1 << t);
      if (i < j) {
        heap.push({-(a[i] + a[j]), {i, j}});
        if (heap.size() > max_heap_sz) heap.pop();
      }
    }
  }
  cerr << "sz(heap)"
       << ": " << ((int)(heap).size()) << '\n';
  ;
  map<int, int> lhs, rhs;
  vector<pair<int, int>> edges;
  int node_cnt = 0;
  while (!heap.empty()) {
    auto p = heap.top();
    heap.pop();
    int u = p.second.first;
    int v = p.second.second;
    if (__builtin_popcount(u) & 1) {
      swap(u, v);
    }
    if (lhs.find(u) == lhs.end()) lhs[u] = node_cnt++;
    if (rhs.find(v) == rhs.end()) rhs[v] = node_cnt++;
    edges.push_back({u, v});
  }
  cerr << "sz(lhs)"
       << ": " << ((int)(lhs).size()) << '\n';
  ;
  cerr << "sz(rhs)"
       << ": " << ((int)(rhs).size()) << '\n';
  ;
  mcmf.init(node_cnt + 2, node_cnt, node_cnt + 1);
  for (auto p : lhs) {
    mcmf.add_edge(mcmf.source, p.second, 1, 0);
  }
  for (auto p : rhs) {
    mcmf.add_edge(p.second, mcmf.sink, 1, 0);
  }
  for (auto e : edges) {
    mcmf.add_edge(lhs[e.first], rhs[e.second], 1, -(a[e.first] + a[e.second]));
  }
  cerr << "mcmf.edge_count"
       << ": " << (mcmf.edge_count) << '\n';
  ;
  mcmf.process(k);
  cerr << "mcmf.max_flow"
       << ": " << (mcmf.max_flow) << '\n';
  ;
  cout << -mcmf.min_cost << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  const bool multiple_test = false;
  int test = 1;
  if (multiple_test) cin >> test;
  for (int i = 0; i < test; ++i) {
    solve();
  }
}
