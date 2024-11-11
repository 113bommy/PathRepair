#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const double PI = acos(-1);
const double R = 0.57721566490153286060651209;
const int maxn = 1005;
struct Edge {
  int from, to, cap, flow, cost;
  Edge(int u, int v, int c, int f, int cc)
      : from(u), to(v), cap(c), flow(f), cost(cc) {}
};
struct MCMF {
  int n, m;
  vector<Edge> edges;
  vector<int> G[maxn];
  int inq[maxn];
  int d[maxn];
  int p[maxn];
  int a[maxn];
  void init(int n) {
    this->n = n;
    for (int i = 0; i <= n; ++i) G[i].clear();
    edges.clear();
  }
  void add(int from, int to, int cap, int cost) {
    edges.emplace_back(Edge(from, to, cap, 0, cost));
    edges.emplace_back(Edge(to, from, 0, 0, -cost));
    m = int(edges.size());
    G[from].emplace_back(m - 2);
    G[to].emplace_back(m - 1);
  }
  bool spfa(int s, int t, int &flow, int &cost) {
    for (int i = 1; i <= n; ++i) d[i] = INF;
    memset(inq, 0, sizeof(inq));
    d[s] = 0;
    inq[s] = 1;
    p[s] = 0;
    queue<int> q;
    a[s] = INF;
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      inq[u] = 0;
      for (int i = 0; i < int(G[u].size()); ++i) {
        Edge &e = edges[G[u][i]];
        if (e.cap > e.flow && d[e.to] > d[u] + e.cost) {
          d[e.to] = d[u] + e.cost;
          p[e.to] = G[u][i];
          a[e.to] = min(a[u], e.cap - e.flow);
          if (!inq[e.to]) {
            q.push(e.to);
            inq[e.to] = 1;
          }
        }
      }
    }
    if (d[t] == INF) return false;
    flow += a[t];
    cost += d[t] * a[t];
    for (int u = t; u != s; u = edges[p[u]].from) {
      edges[p[u]].flow += a[t];
      edges[p[u] ^ 1].flow -= a[t];
    }
    return true;
  }
  int MincostMaxflow(int s, int t, int &cost) {
    int flow = 0;
    cost = 0;
    while (spfa(s, t, flow, cost))
      ;
    return flow;
  }
} mcmf;
int n, m, mincost;
void solve() {
  string S;
  cin >> S;
  cin >> n;
  map<int, int> num, mp[n + 1];
  vector<int> a(n + 1);
  for (int i = 0; i < S.length(); i++) {
    num[S[i] - 'a' + 1]++;
  }
  for (int i = 1; i <= n; i++) {
    string T;
    cin >> T >> a[i];
    for (int j = 0; j < T.length(); j++) {
      mp[i][T[j] - 'a' + 1]++;
    }
  }
  int s = 0, t = n + 26 + 1;
  mcmf.init(t);
  for (int i = 1; i <= 26; i++) {
    if (!num[i]) continue;
    mcmf.add(s, i, num[i], 0);
    for (int j = 1; j <= n; j++) {
      if (!mp[j][i]) continue;
      mcmf.add(i, j + 26, mp[j][i], j);
    }
  }
  for (int i = 1; i <= 26; i++) {
    mcmf.add(i + 26, t, a[i], 0);
  }
  int maxflow = mcmf.MincostMaxflow(s, t, mincost);
  if (maxflow == S.length())
    cout << mincost << "\n";
  else
    cout << -1 << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
