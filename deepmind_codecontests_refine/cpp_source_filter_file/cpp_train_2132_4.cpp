#include <bits/stdc++.h>
bool debug = 0;
const double PI = acos(-1.0);
const double eps = 1e-9;
using namespace std;
const int MAXN = 500;
const int INF = 1000000000;
struct edge {
  int a, b, cap, flow;
};
int sz, s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];
void add_edge(int a, int b, int cap) {
  edge e1 = {a, b, cap, 0};
  edge e2 = {b, a, 0, 0};
  g[a].push_back((int)e.size());
  e.push_back(e1);
  g[b].push_back((int)e.size());
  e.push_back(e2);
}
bool bfs() {
  int qh = 0, qt = 0;
  q[qt++] = s;
  memset(d, -1, sz * sizeof d[0]);
  d[s] = 0;
  while (qh < qt && d[t] == -1) {
    int v = q[qh++];
    for (size_t i = 0; i < g[v].size(); ++i) {
      int id = g[v][i], to = e[id].b;
      if (d[to] == -1 && e[id].flow < e[id].cap) {
        q[qt++] = to;
        d[to] = d[v] + 1;
      }
    }
  }
  return d[t] != -1;
}
int dfs(int v, int flow) {
  if (!flow) return 0;
  if (v == t) return flow;
  for (; ptr[v] < (int)g[v].size(); ++ptr[v]) {
    int id = g[v][ptr[v]], to = e[id].b;
    if (d[to] != d[v] + 1) continue;
    int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
    if (pushed) {
      e[id].flow += pushed;
      e[id ^ 1].flow -= pushed;
      return pushed;
    }
  }
  return 0;
}
int dinic() {
  int flow = 0;
  for (;;) {
    if (!bfs()) break;
    memset(ptr, 0, sz * sizeof ptr[0]);
    while (int pushed = dfs(s, INF)) flow += pushed;
  }
  return flow;
}
set<int> prime;
bool aux[30000];
void sieve() {
  for (int i = 2; i * i < 30000; i++) {
    if (aux[i] == 0) {
      prime.insert(i);
      for (int j = i; j < 30000; j += i) {
        aux[j] = 1;
      }
    }
  }
}
vector<int> res[500];
vector<pair<int, int> > odd, even;
bool vis[500];
int cnt;
vector<int> adj[500];
vector<int> gr[500];
void dfs(int x) {
  vis[x] = 1;
  if (debug)
    cout << "x"
         << " = " << (x) << endl;
  res[cnt].push_back(x);
  for (int p : gr[x]) {
    if (vis[p] == 0) {
      dfs(p);
    }
  }
}
int main() {
  int n;
  sieve();
  cin >> n;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x % 2 == 0) {
      even.push_back({x, i + 1});
    } else
      odd.push_back({x, i + 1});
  }
  if (even.size() != odd.size()) {
    cout << "Impossible" << endl;
    return 0;
  }
  s = 0;
  t = n + 1;
  sz = n + 20;
  for (pair<int, int> j : odd) {
    add_edge(s, j.second, 2);
  }
  for (pair<int, int> j : even) {
    add_edge(j.second, t, 2);
  }
  for (pair<int, int> i : odd) {
    for (pair<int, int> j : even) {
      if (prime.find(i.first + j.first) != prime.end()) {
        adj[i.second].push_back(e.size());
        add_edge(i.second, j.second, 1);
      }
    }
  }
  int aux = dinic();
  if (aux != 2 * even.size()) {
    cout << "Impossible" << endl;
    if (n == 200) printf("%d\n", aux);
    return 0;
  }
  for (pair<int, int> i : odd) {
    for (int p : adj[i.second]) {
      if (e[p].flow == 1) {
        gr[i.second].push_back(e[p].b);
        gr[e[p].b].push_back(i.second);
      }
    }
  }
  for (pair<int, int> i : odd) {
    if (vis[i.second] == 0) {
      cnt++;
      dfs(i.second);
      if (debug) cout << endl;
    }
  }
  cout << cnt << endl;
  for (int i = 1; i <= cnt; i++) {
    printf("%d ", (int)res[i].size());
    for (int j : res[i]) {
      printf("%d ", j);
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
