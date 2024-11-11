#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1000000000;
const ll LINF = 1001002003004005006ll;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}
struct IOSetup {
  IOSetup() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
  }
} iosetup;
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  os << p.first << " " << p.second;
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (int i = 0; i < (int)v.size(); i++)
    os << v[i] << (i + 1 == v.size() ? "" : " ");
  return os;
}
template <typename flow_t, typename cost_t>
struct PrimalDual {
  const cost_t TINF;
  struct edge {
    int to;
    flow_t cap;
    cost_t cost;
    int rev;
    bool isrev;
  };
  vector<vector<edge>> graph;
  vector<cost_t> potential, min_cost;
  vector<int> prevv, preve;
  PrimalDual(int V) : graph(V), TINF(numeric_limits<cost_t>::max()) {}
  void add_edge(int from, int to, flow_t cap, cost_t cost) {
    graph[from].push_back((edge){to, cap, cost, (int)graph[to].size(), false});
    graph[to].push_back(
        (edge){from, 0, -cost, (int)graph[from].size() - 1, true});
  }
  cost_t min_cost_flow(int s, int t, flow_t f) {
    int V = (int)graph.size();
    cost_t ret = 0;
    using Pi = pair<cost_t, int>;
    priority_queue<Pi, vector<Pi>, greater<Pi>> que;
    potential.assign(V, 0);
    preve.assign(V, -1);
    prevv.assign(V, -1);
    while (f > 0) {
      min_cost.assign(V, TINF);
      que.emplace(0, s);
      min_cost[s] = 0;
      while (!que.empty()) {
        Pi p = que.top();
        que.pop();
        if (min_cost[p.second] < p.first) continue;
        for (int i = 0; i < graph[p.second].size(); i++) {
          edge &e = graph[p.second][i];
          cost_t nextCost = min_cost[p.second] + e.cost + potential[p.second] -
                            potential[e.to];
          if (e.cap > 0 and min_cost[e.to] > nextCost) {
            min_cost[e.to] = nextCost;
            prevv[e.to] = p.second, preve[e.to] = i;
            que.emplace(min_cost[e.to], e.to);
          }
        }
      }
      if (min_cost[t] == TINF) return -1;
      for (int v = 0; v < V; v++) potential[v] += min_cost[v];
      flow_t addflow = f;
      for (int v = t; v != s; v = prevv[v]) {
        addflow = min(addflow, graph[prevv[v]][preve[v]].cap);
      }
      f -= addflow;
      ret += addflow * potential[t];
      for (int v = t; v != s; v = prevv[v]) {
        edge &e = graph[prevv[v]][preve[v]];
        e.cap -= addflow;
        graph[v][e.rev].cap += addflow;
      }
    }
    return ret;
  }
  void output() {
    for (int i = 0; i < graph.size(); i++) {
      for (auto &e : graph[i]) {
        if (e.isrev) continue;
        auto &rev_e = graph[e.to][e.rev];
        cout << i << "->" << e.to << " (flow: " << rev_e.cap << " / "
             << rev_e.cap + e.cap << ")" << endl;
      }
    }
  }
};
signed main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < (n); i++) cin >> a[i];
  PrimalDual<int, int> flow(2 * n + 2);
  int src = 2 * n, sink = 2 * n + 1;
  for (int i = 0; i < (n); i++) {
    flow.add_edge(src, i, 2, 0);
    flow.add_edge(i + n, sink, 1, 0);
  }
  for (int i = 0; i < (n); i++) flow.add_edge(i, i + n, 1, -1);
  for (int i = 0; i < (n); i++) {
    int c7 = 0, cn = 0, cp = 0;
    for (int j = i - 1; j >= 0; j--) {
      if (a[i] % 7 == a[j] % 7 and c7 < 2) {
        flow.add_edge(n + i, j, 1, 0);
        c7++;
      }
      if (a[i] - a[j] == -1 and cn < 2) {
        flow.add_edge(n + i, j, 1, 0);
        cn++;
      }
      if (a[i] - a[j] == 1 and cp < 2) {
        flow.add_edge(n + i, j, 1, 0);
        cp++;
      }
    }
  }
  int r = flow.min_cost_flow(src, sink, 2);
  cout << -r << endl;
  return 0;
}
