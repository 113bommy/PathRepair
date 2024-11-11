#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 5;
const long long inf = (2e9) + 10;
const long double eps = 1e-12;
struct FlowEdge {
  int v, u;
  long long cap, flow = 0;
  FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};
struct Dinic {
  const long long flow_inf = 1e18;
  vector<FlowEdge> edges;
  vector<vector<int>> adj;
  int n, m = 0;
  int s, t;
  vector<int> level, ptr;
  queue<int> q;
  Dinic(int n, int s, int t) : n(n), s(s), t(t) {
    adj.resize(n);
    level.resize(n);
    ptr.resize(n);
  }
  void add_edge(int v, int u, long long cap) {
    edges.emplace_back(v, u, cap);
    edges.emplace_back(u, v, 0);
    adj[v].push_back(m);
    adj[u].push_back(m + 1);
    m += 2;
  }
  bool bfs() {
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int id : adj[v]) {
        if (edges[id].cap - edges[id].flow < 1) continue;
        if (level[edges[id].u] != -1) continue;
        level[edges[id].u] = level[v] + 1;
        q.push(edges[id].u);
      }
    }
    return level[t] != -1;
  }
  long long dfs(int v, long long pushed) {
    if (pushed == 0) return 0;
    if (v == t) return pushed;
    for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
      int id = adj[v][cid];
      int u = edges[id].u;
      if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
        continue;
      long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
      if (tr == 0) continue;
      edges[id].flow += tr;
      edges[id ^ 1].flow -= tr;
      return tr;
    }
    return 0;
  }
  long long flow() {
    long long f = 0;
    while (true) {
      fill(level.begin(), level.end(), -1);
      level[s] = 0;
      q.push(s);
      if (!bfs()) break;
      fill(ptr.begin(), ptr.end(), 0);
      while (long long pushed = dfs(s, flow_inf)) {
        f += pushed;
      }
    }
    return f;
  }
};
int n, m;
vector<int> v;
vector<int> edges[maxn];
bool visited[maxn];
vector<int> res;
void dfs(int u) {
  visited[u] = true;
  res.push_back(u);
  for (int v : edges[u]) {
    if (!visited[v]) dfs(v);
  }
}
bool isprime(int n) {
  if (n == 1) return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  v.push_back(0);
  int s = 0;
  int t = n + 1;
  Dinic dinic(t + 1, s, t);
  int odd = 0;
  int even = 0;
  for (int i = (int)1; i <= (int)n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
    if (x % 2) {
      dinic.add_edge(s, i, 2);
      odd++;
    } else {
      dinic.add_edge(i, t, 2);
      even++;
    }
  }
  if (odd != even) return cout << "impossible" << endl, 0;
  for (int i = (int)1; i <= (int)n; i++) {
    for (int j = (int)i + 1; j <= (int)n; j++) {
      if (isprime(v[i] + v[j])) {
        int u = i, vv = j;
        if (v[j] % 2) swap(u, vv);
        dinic.add_edge(u, vv, 1);
      }
    }
  }
  long long f = dinic.flow();
  if (f != 2ll * even) return cout << "impossible" << endl, 0;
  for (auto it : dinic.edges) {
    if (it.flow > 0) {
      if (it.u == s || it.v == t) continue;
      if (it.u == t || it.v == s) continue;
      edges[it.u].push_back(it.v);
      edges[it.v].push_back(it.u);
    }
  }
  vector<vector<int>> ans;
  for (int i = (int)1; i <= (int)n; i++) {
    if (!visited[i]) {
      dfs(i);
      ans.push_back(res);
      res.clear();
    }
  }
  cout << ans.size() << endl;
  for (auto it : ans) {
    cout << it.size();
    for (auto it1 : it) {
      cout << " " << it1;
    }
    cout << endl;
  }
  return 0;
}
