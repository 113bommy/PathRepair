#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 5002;
pair<short, short> edges[N];
int source, sink;
int n, m;
short cap[N][N];
vector<short> adj[N];
inline void add_edge(int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}
void build() {
  source = 0;
  for (int i = int(1); i < int(m + 1); i++) {
    cap[source][i] = 1;
    add_edge(source, i);
    int u, v;
    tie(u, v) = edges[i];
    u += m;
    v += m;
    cap[i][u] = 1;
    cap[i][v] = 1;
    add_edge(i, u);
    add_edge(i, v);
  }
  sink = n + m + 1;
  for (int i = int(1); i < int(n + 1); i++) {
    int u = m + i;
    cap[u][sink] = 1;
    add_edge(u, sink);
  }
}
short dist[N];
short parent[N];
void visit(int v, short &f, bool calc) {
  int u = parent[v];
  if (u != -1) {
    if (calc) {
      f = min(f, cap[u][v]);
    } else {
      cap[u][v] -= f;
      cap[v][u] += f;
    }
    visit(u, f, calc);
  }
}
inline int ag() {
  memset(dist, -1, sizeof dist);
  memset(parent, -1, sizeof parent);
  dist[source] = 0;
  queue<int> q;
  q.push(source);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (u == sink) {
      break;
    }
    for (int v : adj[u]) {
      if (dist[v] == -1 and cap[u][v] > 0) {
        q.push(v);
        dist[v] = dist[u] + 1;
        parent[v] = u;
      }
    }
  }
  int res = 0;
  if (dist[sink] != -1) {
    short f = 2 * m;
    visit(sink, f, true);
    visit(sink, f, false);
    res = f;
  }
  return res;
}
inline int mf() {
  int f = 0;
  while (true) {
    int ap = ag();
    if (ap == 0) {
      break;
    }
    f += ap;
  }
  return f;
}
void solve() {
  int f = 0;
  while (true) {
    f += mf();
    if (f == m) {
      break;
    }
    for (int i = int(1); i < int(n + 1); i++) {
      int u = i + m;
      cap[u][sink]++;
    }
  }
}
void print() {
  short ans = 0;
  for (int i = int(1); i < int(n + 1); i++) {
    int u = i + m;
    ans = max(ans, cap[sink][u]);
  }
  cout << ans << '\n';
  for (int i = int(1); i < int(m + 1); i++) {
    int u = m + edges[i].first;
    pair<short, short> res = edges[i];
    if (cap[i][u] == 1) {
      swap(res.first, res.second);
    }
    cout << res.first << ' ' << res.second << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = int(1); i < int(m + 1); i++) {
    int u, v;
    cin >> u >> v;
    edges[i] = pair<short, short>(u, v);
  }
  build();
  solve();
  print();
  return 0;
}
