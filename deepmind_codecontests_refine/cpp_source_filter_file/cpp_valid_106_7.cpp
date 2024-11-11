#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios {
  fast_ios() {
    cin.tie(nullptr), ios::sync_with_stdio(false),
        cout << fixed << setprecision(20);
  };
} fast_ios_;
template <typename T, typename V>
void ndarray(vector<T> &vec, const V &val, int len) {
  vec.assign(len, val);
}
template <typename T, typename V, typename... Args>
void ndarray(vector<T> &vec, const V &val, int len, Args... args) {
  vec.resize(len),
      for_each(begin(vec), end(vec), [&](T &v) { ndarray(v, val, args...); });
}
template <typename T>
bool chmax(T &m, const T q) {
  return m < q ? (m = q, true) : false;
}
template <typename T>
bool chmin(T &m, const T q) {
  return m > q ? (m = q, true) : false;
}
int floor_lg(long long x) { return x <= 0 ? -1 : 63 - __builtin_clzll(x); }
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) {
  return make_pair(l.first + r.first, l.second + r.second);
}
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) {
  return make_pair(l.first - r.first, l.second - r.second);
}
template <typename T>
vector<T> sort_unique(vector<T> vec) {
  sort(vec.begin(), vec.end()),
      vec.erase(unique(vec.begin(), vec.end()), vec.end());
  return vec;
}
template <typename T>
int arglb(const std::vector<T> &v, const T &x) {
  return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x));
}
template <typename T>
int argub(const std::vector<T> &v, const T &x) {
  return std::distance(v.begin(), std::upper_bound(v.begin(), v.end(), x));
}
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (auto &v : vec) is >> v;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << '[';
  for (auto v : vec) os << v << ',';
  os << ']';
  return os;
}
template <typename T, size_t sz>
ostream &operator<<(ostream &os, const array<T, sz> &arr) {
  os << '[';
  for (auto v : arr) os << v << ',';
  os << ']';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const deque<T> &vec) {
  os << "deq[";
  for (auto v : vec) os << v << ',';
  os << ']';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &vec) {
  os << '{';
  for (auto v : vec) os << v << ',';
  os << '}';
  return os;
}
template <typename T, typename TH>
ostream &operator<<(ostream &os, const unordered_set<T, TH> &vec) {
  os << '{';
  for (auto v : vec) os << v << ',';
  os << '}';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &vec) {
  os << '{';
  for (auto v : vec) os << v << ',';
  os << '}';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) {
  os << '{';
  for (auto v : vec) os << v << ',';
  os << '}';
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &pa) {
  os << '(' << pa.first << ',' << pa.second << ')';
  return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const map<TK, TV> &mp) {
  os << '{';
  for (auto v : mp) os << v.first << "=>" << v.second << ',';
  os << '}';
  return os;
}
template <typename TK, typename TV, typename TH>
ostream &operator<<(ostream &os, const unordered_map<TK, TV, TH> &mp) {
  os << '{';
  for (auto v : mp) os << v.first << "=>" << v.second << ',';
  os << '}';
  return os;
}
template <class Cap = long long, class Cost = long long,
          Cost INF_COST = std::numeric_limits<Cost>::max() / 2>
struct MinCostFlow {
  struct _edge {
    int to, rev;
    Cap cap;
    Cost cost;
    template <class Ostream>
    friend Ostream &operator<<(Ostream &os, const _edge &e) {
      return os << '(' << e.to << ',' << e.rev << ',' << e.cap << ',' << e.cost
                << ')';
    }
  };
  bool _is_dual_infeasible;
  int V;
  std::vector<std::vector<_edge>> g;
  std::vector<Cost> dist;
  std::vector<int> prevv, preve;
  std::vector<Cost> dual;
  std::vector<std::pair<int, int>> pos;
  bool _initialize_dual_dag() {
    std::vector<int> deg_in(V);
    for (int i = 0; i < V; i++) {
      for (const auto &e : g[i]) deg_in[e.to] += (e.cap > 0);
    }
    std::vector<int> st;
    st.reserve(V);
    for (int i = 0; i < V; i++) {
      if (!deg_in[i]) st.push_back(i);
    }
    for (int n = 0; n < V; n++) {
      if (int(st.size()) == n) return false;
      int now = st[n];
      for (const auto &e : g[now]) {
        if (!e.cap) continue;
        deg_in[e.to]--;
        if (deg_in[e.to] == 0) st.push_back(e.to);
        if (dual[e.to] >= dual[now] + e.cost) dual[e.to] = dual[now] + e.cost;
      }
    }
    return true;
  }
  bool _initialize_dual_spfa() {
    dual.assign(V, 0);
    std::queue<int> q;
    std::vector<int> in_queue(V);
    std::vector<int> nvis(V);
    for (int i = 0; i < V; i++) q.push(i), in_queue[i] = true;
    while (q.size()) {
      int now = q.front();
      q.pop(), in_queue[now] = false;
      if (nvis[now] > V) return false;
      nvis[now]++;
      for (const auto &e : g[now]) {
        if (!e.cap) continue;
        if (dual[e.to] > dual[now] + e.cost) {
          dual[e.to] = dual[now] + e.cost;
          if (!in_queue[e.to]) in_queue[e.to] = true, q.push(e.to);
        }
      }
    }
    return true;
  }
  bool initialize_dual() {
    return !_is_dual_infeasible or _initialize_dual_dag() or
           _initialize_dual_spfa();
  }
  template <class heap>
  void _dijkstra(int s) {
    prevv.assign(V, -1);
    preve.assign(V, -1);
    dist.assign(V, INF_COST);
    dist[s] = 0;
    heap q;
    q.emplace(0, s);
    while (!q.empty()) {
      auto p = q.top();
      q.pop();
      int v = p.second;
      if (dist[v] < Cost(p.first)) continue;
      for (int i = 0; i < (int)g[v].size(); i++) {
        _edge &e = g[v][i];
        auto c = dist[v] + e.cost + dual[v] - dual[e.to];
        if (e.cap > 0 and dist[e.to] > c) {
          dist[e.to] = c, prevv[e.to] = v, preve[e.to] = i;
          q.emplace(dist[e.to], e.to);
        }
      }
    }
  }
  MinCostFlow(int V = 0) : _is_dual_infeasible(false), V(V), g(V), dual(V, 0) {
    static_assert(INF_COST > 0, "INF_COST must be positive");
  }
  int add_edge(int from, int to, Cap cap, Cost cost) {
    assert(0 <= from and from < V);
    assert(0 <= to and to < V);
    assert(cap >= 0);
    if (cost < 0) _is_dual_infeasible = true;
    pos.emplace_back(from, g[from].size());
    g[from].push_back({to, (int)g[to].size() + (from == to), cap, cost});
    g[to].push_back({from, (int)g[from].size() - 1, (Cap)0, -cost});
    return int(pos.size()) - 1;
  }
  using Pque = std::priority_queue<std::pair<Cost, int>,
                                   std::vector<std::pair<Cost, int>>,
                                   std::greater<std::pair<Cost, int>>>;
  template <class heap = Pque>
  std::pair<Cap, Cost> flow(int s, int t, const Cap &flow_limit) {
    if (!initialize_dual()) throw;
    Cost cost = 0;
    Cap flow_rem = flow_limit;
    while (flow_rem > 0) {
      _dijkstra<heap>(s);
      if (dist[t] == INF_COST) break;
      for (int v = 0; v < V; v++)
        dual[v] = std::min(dual[v] + dist[v], INF_COST);
      Cap d = flow_rem;
      for (int v = t; v != s; v = prevv[v])
        d = std::min(d, g[prevv[v]][preve[v]].cap);
      flow_rem -= d;
      cost += d * (dual[t] - dual[s]);
      for (int v = t; v != s; v = prevv[v]) {
        _edge &e = g[prevv[v]][preve[v]];
        e.cap -= d;
        g[v][e.rev].cap += d;
      }
    }
    return std::make_pair(flow_limit - flow_rem, cost);
  }
  struct edge {
    int from, to;
    Cap cap, flow;
    Cost cost;
    template <class Ostream>
    friend Ostream &operator<<(Ostream &os, const edge &e) {
      return os << '(' << e.from << "->" << e.to << ',' << e.flow << '/'
                << e.cap << ",$" << e.cost << ')';
    }
  };
  edge get_edge(int edge_id) const {
    int m = int(pos.size());
    assert(0 <= edge_id and edge_id < m);
    auto _e = g[pos[edge_id].first][pos[edge_id].second];
    auto _re = g[_e.to][_e.rev];
    return {pos[edge_id].first, _e.to, _e.cap + _re.cap, _re.cap, _e.cost};
  }
  std::vector<edge> edges() const {
    std::vector<edge> ret(pos.size());
    for (int i = 0; i < int(pos.size()); i++) ret[i] = get_edge(i);
    return ret;
  }
  template <class Ostream>
  friend Ostream &operator<<(Ostream &os, const MinCostFlow &mcf) {
    os << "[MinCostFlow]V=" << mcf.V << ":";
    for (int i = 0; i < mcf.V; i++) {
      for (auto &e : mcf.g[i])
        os << "\n" << i << "->" << e.to << ":cap" << e.cap << ",$" << e.cost;
    }
    return os;
  }
};
int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(1 << N);
  cin >> A;
  vector<tuple<int, int, int>> aijs;
  for (int i = (0), i_end_ = (A.size()); i < i_end_; i++) {
    for (int d = (0), d_end_ = (N); d < d_end_; d++) {
      int j = i ^ (1 << d);
      if (i < j) aijs.emplace_back(A[i] + A[j], i, j);
    }
  }
  sort(aijs.rbegin(), aijs.rend());
  set<int> si;
  for (auto [a, i, j] : aijs) {
    si.insert(i);
    si.insert(j);
    if (si.size() > 4100) break;
  }
  vector<int> is(si.begin(), si.end());
  const int gs = is.size(), gt = gs + 1;
  MinCostFlow<int, lint> mcf(gt + 1);
  for (int x = (0), x_end_ = (is.size()); x < x_end_; x++) {
    int i = is[x];
    int p = __builtin_parity(i);
    if (p) {
      mcf.add_edge(gs, x, 1, -A[i]);
      for (int d = (0), d_end_ = (N); d < d_end_; d++) {
        int j = i ^ (1 << d);
        int y = arglb(is, j);
        if (y < gs and is[y] == j) mcf.add_edge(x, y, 1, 0);
      }
    } else {
      mcf.add_edge(x, gt, 1, -A[i]);
    }
  }
  cout << -mcf.flow(gs, gt, K).second << '\n';
}
