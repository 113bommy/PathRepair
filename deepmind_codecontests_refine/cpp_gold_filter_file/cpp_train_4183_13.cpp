#include <bits/stdc++.h>
using namespace std;
struct FlowEdge {
  long long int v, u;
  long long cap, flow = 0;
  FlowEdge(long long int v, long long int u, long long cap)
      : v(v), u(u), cap(cap) {}
};
struct Dinic {
  const long long flow_inf = 1e18;
  vector<FlowEdge> edges;
  vector<vector<int> > adj;
  long long int n, m = 0;
  long long int s, t;
  vector<int> level, ptr;
  queue<int> q;
  Dinic(long long int n, long long int s, long long int t) : n(n), s(s), t(t) {
    adj.resize(n);
    level.resize(n);
    ptr.resize(n);
  }
  void add_edge(long long int v, long long int u, long long cap) {
    edges.emplace_back(v, u, cap);
    edges.emplace_back(u, v, 0);
    adj[v].push_back(m);
    adj[u].push_back(m + 1);
    m += 2;
  }
  bool bfs() {
    while (!q.empty()) {
      long long int v = q.front();
      q.pop();
      for (long long int id : adj[v]) {
        if (edges[id].cap - edges[id].flow < 1) continue;
        if (level[edges[id].u] != -1) continue;
        level[edges[id].u] = level[v] + 1;
        q.push(edges[id].u);
      }
    }
    return level[t] != -1;
  }
  long long dfs(long long int v, long long pushed) {
    if (pushed == 0) return 0;
    if (v == t) return pushed;
    for (int &cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
      long long int id = adj[v][cid];
      long long int u = edges[id].u;
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
struct spaceship {
  long long int loc, attack, fuel;
  spaceship(long long int l, long long int a, long long int f) {
    loc = l;
    attack = a;
    fuel = f;
  }
};
struct base {
  long long int loc, defense;
  base(long long int l, long long int d) {
    loc = l;
    defense = d;
  }
};
void bfs(vector<vector<long long int> > &adj, long long int s,
         vector<long long int> &distance) {
  distance[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    long long int node = q.front();
    q.pop();
    for (long long int i = 0; i < adj[node].size(); i++) {
      long long int m = adj[node][i];
      if (distance[m] == -1) {
        distance[m] = distance[node] + 1;
        q.push(m);
      }
    }
  }
}
int main() {
  long long int n, m;
  cin >> n >> m;
  vector<vector<long long int> > adj(n + 1);
  for (long long int i = 1; i <= m; i++) {
    long long int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  long long int s, b, k, h;
  cin >> s >> b >> k >> h;
  vector<spaceship> ships;
  vector<base> bases;
  vector<vector<long long int> > match(s + 1, vector<long long int>(b + 1, 0));
  for (long long int i = 1; i <= s; i++) {
    long long int a, b, c;
    cin >> a >> b >> c;
    ships.push_back(spaceship(a, b, c));
  }
  for (long long int i = 1; i <= b; i++) {
    long long int x, y;
    cin >> x >> y;
    bases.push_back(base(x, y));
  }
  for (long long int i = 0; i < s; i++) {
    vector<long long int> distance(n + 1, -1);
    bfs(adj, ships[i].loc, distance);
    for (long long int j = 0; j < b; j++) {
      if (distance[bases[j].loc] <= ships[i].fuel &&
          ships[i].attack >= bases[j].defense)
        match[i][j] = 1;
    }
  }
  Dinic Matching(s + b + 2, 0, s + b + 1);
  for (long long int i = 0; i < s; i++)
    for (long long int j = 0; j < b; j++)
      if (match[i][j]) Matching.add_edge(i + 1, s + 1 + j, 1);
  for (long long int i = 0; i < s; i++) Matching.add_edge(0, i + 1, 1);
  for (long long int i = 0; i < b; i++)
    Matching.add_edge(s + 1 + i, s + b + 1, 1);
  long long int f = Matching.flow();
  if (h >= k) {
    cout << f * k << endl;
  } else {
    cout << min(f * k, s * h);
  }
  return 0;
}
