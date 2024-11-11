#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long INF = (long long)1000000007 * 1000000007;
const long double eps = 1e-8;
const long double pi = acos(-1.0);
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
template <class Cap, class Cost>
struct MinCostFlow {
 public:
  MinCostFlow() {}
  MinCostFlow(int n) : _n(n), g(n) {}
  int add_edge(int from, int to, Cap cap, Cost cost) {
    assert(0 <= from && from < _n);
    assert(0 <= to && to < _n);
    int m = int(pos.size());
    pos.push_back({from, int(g[from].size())});
    g[from].push_back(_edge{to, int(g[to].size()), cap, cost});
    g[to].push_back(_edge{from, int(g[from].size()) - 1, 0, -cost});
    return m;
  }
  struct edge {
    int from, to;
    Cap cap, flow;
    Cost cost;
  };
  edge get_edge(int i) {
    int m = int(pos.size());
    assert(0 <= i && i < m);
    auto _e = g[pos[i].first][pos[i].second];
    auto _re = g[_e.to][_e.rev];
    return edge{
        pos[i].first, _e.to, _e.cap + _re.cap, _re.cap, _e.cost,
    };
  }
  std::vector<edge> edges() {
    int m = int(pos.size());
    std::vector<edge> result(m);
    for (int i = 0; i < m; i++) {
      result[i] = get_edge(i);
    }
    return result;
  }
  std::pair<Cap, Cost> flow(int s, int t) {
    return flow(s, t, std::numeric_limits<Cap>::max());
  }
  std::pair<Cap, Cost> flow(int s, int t, Cap flow_limit) {
    return slope(s, t, flow_limit).back();
  }
  std::vector<std::pair<Cap, Cost>> slope(int s, int t) {
    return slope(s, t, std::numeric_limits<Cap>::max());
  }
  std::vector<std::pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {
    assert(0 <= s && s < _n);
    assert(0 <= t && t < _n);
    assert(s != t);
    std::vector<Cost> dual(_n, 0), dist(_n);
    std::vector<int> pv(_n), pe(_n);
    std::vector<bool> vis(_n);
    auto dual_ref = [&]() {
      std::fill(dist.begin(), dist.end(), std::numeric_limits<Cost>::max());
      std::fill(pv.begin(), pv.end(), -1);
      std::fill(pe.begin(), pe.end(), -1);
      std::fill(vis.begin(), vis.end(), false);
      struct Q {
        Cost key;
        int to;
        bool operator<(Q r) const { return key > r.key; }
      };
      std::priority_queue<Q> que;
      dist[s] = 0;
      que.push(Q{0, s});
      while (!que.empty()) {
        int v = que.top().to;
        que.pop();
        if (vis[v]) continue;
        vis[v] = true;
        if (v == t) break;
        for (int i = 0; i < int(g[v].size()); i++) {
          auto e = g[v][i];
          if (vis[e.to] || !e.cap) continue;
          Cost cost = e.cost - dual[e.to] + dual[v];
          if (dist[e.to] - dist[v] > cost) {
            dist[e.to] = dist[v] + cost;
            pv[e.to] = v;
            pe[e.to] = i;
            que.push(Q{dist[e.to], e.to});
          }
        }
      }
      if (!vis[t]) {
        return false;
      }
      for (int v = 0; v < _n; v++) {
        if (!vis[v]) continue;
        dual[v] -= dist[t] - dist[v];
      }
      return true;
    };
    Cap flow = 0;
    Cost cost = 0, prev_cost = -1;
    std::vector<std::pair<Cap, Cost>> result;
    result.push_back({flow, cost});
    while (flow < flow_limit) {
      if (!dual_ref()) break;
      Cap c = flow_limit - flow;
      for (int v = t; v != s; v = pv[v]) {
        c = std::min(c, g[pv[v]][pe[v]].cap);
      }
      for (int v = t; v != s; v = pv[v]) {
        auto &e = g[pv[v]][pe[v]];
        e.cap -= c;
        g[v][e.rev].cap += c;
      }
      Cost d = -dual[s];
      flow += c;
      cost += c * d;
      if (prev_cost == d) {
        result.pop_back();
      }
      result.push_back({flow, cost});
      prev_cost = cost;
    }
    return result;
  }

 private:
  int _n;
  struct _edge {
    int to, rev;
    Cap cap;
    Cost cost;
  };
  std::vector<std::pair<int, int>> pos;
  std::vector<std::vector<_edge>> g;
};
using edge = MinCostFlow<int, long long>::edge;
int n1, n2, m, r, b;
string s1, s2;
void solve() {
  cin >> n1 >> n2 >> m >> r >> b;
  cin >> s1 >> s2;
  MinCostFlow<int, int> mcf(n1 + n2 + 4);
  int s = n1 + n2, X = n1 + n2 + 2;
  int inf = 10000000;
  int t1 = 0, t2 = 0;
  for (int i = 0; i < n1; i++) {
    if (s1[i] == 'R') {
      mcf.add_edge(s, i, inf, 0);
      mcf.add_edge(X, i, 1, 0);
      t1++;
    } else if (s1[i] == 'B') {
      mcf.add_edge(i, s + 1, inf, 0);
      mcf.add_edge(i, X + 1, 1, 0);
      t2++;
    } else {
      mcf.add_edge(s, i, inf, 0);
      mcf.add_edge(i, s + 1, inf, 0);
    }
  }
  for (int i = 0; i < n2; i++) {
    if (s2[i] == 'B') {
      mcf.add_edge(s, n1 + i, inf, 0);
      mcf.add_edge(X, n1 + i, 1, 0);
      t1++;
    } else if (s2[i] == 'R') {
      mcf.add_edge(n1 + i, s + 1, inf, 0);
      mcf.add_edge(n1 + i, X + 1, 1, 0);
      t2++;
    } else {
      mcf.add_edge(s, n1 + i, inf, 0);
      mcf.add_edge(n1 + i, s + 1, inf, 0);
    }
  }
  mcf.add_edge(s, X + 1, t1, 0);
  mcf.add_edge(X, s + 1, t2, 0);
  mcf.add_edge(s + 1, s, inf, 0);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    mcf.add_edge(u, n1 + v, 1, r);
    mcf.add_edge(n1 + v, u, 1, b);
  }
  pair<int, int> p = mcf.flow(X, X + 1);
  if (p.first < t1) {
    cout << -1 << endl;
    return;
  }
  cout << p.second << endl;
  auto es = mcf.edges();
  int i = 0;
  bool flag = false;
  for (auto e : es) {
    if (e.from < n1 && e.to < n1 + n2) {
      if (e.flow >= 1) {
        cout << "R";
        flag = true;
      }
    } else if (e.from < n1 + n2 && e.to < n1) {
      if (e.flow >= 1) {
        cout << "B";
      } else {
        if (!flag) {
          cout << "U";
        }
      }
      flag = false;
    }
  }
  cout << "" << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(50);
  solve();
}
