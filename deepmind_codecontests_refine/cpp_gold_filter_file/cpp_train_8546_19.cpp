#include <bits/stdc++.h>
using namespace std;
void io() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(15);
}
const int MAX = 702;
template <class T>
class Dinic {
 public:
  struct edge {
    int a, b;
    T cap, flow;
  };
  int n, source, sink;
  int dis[MAX];
  int ptr[MAX];
  vector<edge> e;
  vector<int> adj[MAX];
  Dinic(int a, int b, int c) {
    n = a;
    source = b;
    sink = c;
  }
  void set_dis() {
    for (int i = 0; i <= n; ++i) {
      dis[i] = -1;
    }
  }
  void set_ptr() {
    for (int i = 0; i <= n; ++i) {
      ptr[i] = 0;
    }
  }
  void reset(int a, int b, int c) {
    n = a;
    source = b;
    sink = c;
    e.clear();
    for (int i = 0; i <= n; i++) {
      dis[i] = 0;
      adj[i].clear();
      ptr[i] = 0;
    }
  }
  void add_edge(int a, int b, T cap) {
    edge e1 = {a, b, cap, 0};
    edge e2 = {b, a, 0, 0};
    adj[a].push_back((int)e.size());
    e.push_back(e1);
    adj[b].push_back((int)e.size());
    e.push_back(e2);
  }
  bool bfs() {
    queue<int> q;
    q.push(source);
    set_dis();
    dis[source] = 0;
    while (!q.empty() && dis[sink] == -1) {
      int v = q.front();
      q.pop();
      for (size_t i = 0; i < adj[v].size(); ++i) {
        int id = adj[v][i];
        int to = e[id].b;
        if (dis[to] == -1 && e[id].flow < e[id].cap) {
          dis[to] = dis[v] + 1;
          q.push(to);
        }
      }
    }
    while (!q.empty()) {
      q.pop();
    }
    return dis[sink] != -1;
  }
  T dfs(int v, T flow) {
    if (!flow) {
      return 0;
    }
    if (v == sink) {
      return flow;
    }
    for (; ptr[v] < (int)adj[v].size(); ++ptr[v]) {
      int id = adj[v][ptr[v]];
      int to = e[id].b;
      if (dis[to] != dis[v] + 1) {
        continue;
      }
      int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
      if (pushed) {
        e[id].flow += pushed;
        e[id ^ 1].flow -= pushed;
        return pushed;
      }
    }
    return 0;
  }
  T max_flow() {
    T flow = 0;
    while (bfs()) {
      set_ptr();
      T pushed;
      while (pushed = dfs(source, INT_MAX)) {
        flow += pushed;
      }
    }
    return flow;
  }
  void print_graph() {
    for (size_t i = 0; i < (int)e.size(); ++i) {
      printf("from: %d to : %d flow : %d cap : %d\n", e[i].a, e[i].b, e[i].flow,
             e[i].cap);
    }
  }
};
const long long offset = (2e6 + 5) * MAX;
const long long INF = 1e15;
int main(int argc, char* argv[]) {
  io();
  int n;
  cin >> n;
  int src = 2 * n + 1;
  int snk = 2 * n + 2;
  Dinic<long long> mincut(2 * n + 2, src, snk);
  for (int i = 1; i <= n; i++) {
    mincut.add_edge(i + n, snk, offset);
  }
  long long have = 0;
  long long val;
  for (int i = 1; i <= n; i++) {
    int m;
    cin >> m;
    int v;
    while (m--) {
      cin >> v;
      mincut.add_edge(i, v + n, INF);
    }
  }
  for (int i = 1; i <= n; i++) {
    cin >> val;
    have += val;
    mincut.add_edge(src, i, -val + offset);
  }
  long long ans = have + mincut.max_flow() - 1ll * n * offset;
  cout << ans << '\n';
  return 0;
}
