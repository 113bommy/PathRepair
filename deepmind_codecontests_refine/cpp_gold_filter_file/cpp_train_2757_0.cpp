#include <bits/stdc++.h>
using namespace std;
struct edge {
  int from, to, cap, flow;
};
int n, m;
int s, t;
const int inf = 1e9;
int suma, sumb;
vector<int> a, b;
vector<vector<int> > gr, res;
int en;
edge E[1000000];
vector<vector<int> > g;
vector<int> dist, ptr;
void add_edge(int from, int to, int cap);
bool bfs();
int dfs(int v, int flow);
int dinic();
void read();
void fill();
int main() {
  ios_base::sync_with_stdio(false);
  read();
  fill();
  if (suma == sumb && dinic() == suma) {
    cout << "YES" << endl;
    res.assign(n, vector<int>(n, 0));
    for (int i = 0; i < en; ++i) {
      int fr = E[2 * i].from;
      int to = E[2 * i].to;
      int fl = E[2 * i].flow;
      if (fr != s && to != t && fl > 0) res[fr - 1][to - n - 1] = fl;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) cout << res[i][j] << " ";
      cout << endl;
    }
  } else
    cout << "NO" << endl;
  return 0;
}
void read() {
  int n_, m_;
  cin >> n_ >> m_;
  suma = sumb = 0;
  a.resize(n_);
  b.resize(n_);
  for (int i = 0; i < n_; ++i) {
    cin >> a[i];
    suma += a[i];
  }
  for (int i = 0; i < n_; ++i) {
    cin >> b[i];
    sumb += b[i];
  }
  gr.assign(n_, vector<int>(n_, 0));
  for (int i = 0; i < m_; ++i) {
    int p, q;
    cin >> p >> q;
    --p;
    --q;
    gr[p][q] = 1;
    gr[q][p] = 1;
  }
}
void fill() {
  m = n = a.size();
  en = 0;
  s = 0;
  t = m + n + 1;
  g.resize(m + n + 2);
  for (int i = 0; i < n; ++i) add_edge(s, i + 1, a[i]);
  for (int i = 0; i < n; ++i) add_edge(n + i + 1, t, b[i]);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (i == j || gr[i][j] == 1) add_edge(i + 1, n + j + 1, inf);
}
void add_edge(int from, int to, int cap) {
  E[2 * en].from = from;
  E[2 * en].to = to;
  E[2 * en].cap = cap;
  E[2 * en].flow = 0;
  E[2 * en + 1].from = to;
  E[2 * en + 1].to = from;
  E[2 * en + 1].cap = 0;
  E[2 * en + 1].flow = 0;
  g[from].push_back(2 * en);
  g[to].push_back(2 * en + 1);
  ++en;
}
bool bfs() {
  dist.assign(n + m + 2, -1);
  dist[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int i = 0; i < g[v].size(); ++i) {
      int e = g[v][i];
      int to = E[e].to;
      if (dist[to] == -1 && E[e].cap > E[e].flow) {
        dist[to] = dist[v] + 1;
        q.push(to);
      }
    }
  }
  return (dist[t] != -1);
}
int dfs(int v, int flow) {
  if (flow == 0 || v == t) return flow;
  for (; ptr[v] < g[v].size(); ++ptr[v]) {
    int e = g[v][ptr[v]];
    int to = E[e].to;
    if (dist[to] != dist[v] + 1) continue;
    int ff = dfs(to, min(E[e].cap - E[e].flow, flow));
    if (ff > 0) {
      E[e].flow += ff;
      E[e ^ 1].flow -= ff;
      return ff;
    }
  }
  return 0;
}
int dinic() {
  int flow = 0;
  while (bfs()) {
    ptr.assign(m + n + 2, 0);
    while (true) {
      int ff = dfs(s, inf);
      flow += ff;
      if (ff == 0) break;
    }
  }
  return flow;
}
