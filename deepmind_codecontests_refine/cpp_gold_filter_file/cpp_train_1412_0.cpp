#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e9 + 7;
const long long INF = 1e18;
int n, m;
vector<int> g[N];
int a[N], b[N], c[N];
int blksz = 0;
int isCyc[N];
int preN[N], preE[N];
int vis[N];
int h[N];
struct Dinic {
  static const int N = 2e5 + 10;
  static const int inf = 1e9 + 7;
  struct edge {
    int from, to, cap, flow;
  };
  int n, s, t, d[N], q[N], ptr[N];
  vector<edge> E;
  vector<int> g[N];
  void add_Edge(int u, int v, int cap) {
    edge e1 = {u, v, cap, 0};
    edge e2 = {v, u, 0, 0};
    g[u].push_back((int)E.size());
    E.push_back(e1);
    g[v].push_back((int)E.size());
    E.push_back(e2);
  }
  bool bfs() {
    int qh = 0, qt = 0;
    q[qt++] = s;
    for (int i = 0; i <= n; i++) d[i] = -1;
    d[s] = 0;
    while (qh < qt && d[t] == -1) {
      int u = q[qh++];
      for (auto id : g[u]) {
        int v = E[id].to;
        if (d[v] == -1 && E[id].flow < E[id].cap) {
          q[qt++] = v;
          d[v] = d[u] + 1;
        }
      }
    }
    return d[t] != -1;
  }
  int dfs(int u, int flow) {
    if (!flow) return 0;
    if (u == t) return flow;
    for (; ptr[u] < (int)g[u].size(); ptr[u]++) {
      int id = g[u][ptr[u]];
      int v = E[id].to;
      if (d[v] != d[u] + 1) {
        continue;
      }
      int pushed = dfs(v, min(flow, E[id].cap - E[id].flow));
      if (pushed) {
        E[id].flow += pushed;
        E[id ^ 1].flow -= pushed;
        return pushed;
      }
    }
    return 0;
  }
  int dinic() {
    int flow = 0;
    while (bfs()) {
      for (int i = 0; i <= n; i++) {
        ptr[i] = 0;
      }
      while (int cur = dfs(s, inf)) {
        flow += cur;
      }
    }
    return flow;
  }
} D;
void dfs(int u, int p) {
  vis[u] = 1;
  for (auto idx : g[u]) {
    int v = a[idx] ^ b[idx] ^ u;
    if (v != p) {
      if (!vis[v]) {
        preN[v] = u;
        preE[v] = idx;
        h[v] = h[u] + 1;
        dfs(v, u);
      } else if (h[v] < h[u]) {
        vector<int> cyc;
        cyc.push_back(c[idx]);
        isCyc[idx] = 1;
        int cur = u;
        while (cur != v) {
          cyc.push_back(c[preE[cur]]);
          isCyc[preE[cur]] = 1;
          cur = preN[cur];
        }
        ++blksz;
        D.add_Edge(0, blksz, (int)cyc.size() - 1);
        for (auto c : cyc) {
          D.add_Edge(blksz, c + m, 1);
        }
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i] >> c[i];
    g[a[i]].push_back(i);
    g[b[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    vis[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i, 0);
    }
  }
  for (int i = 1; i <= m; i++)
    if (!isCyc[i]) {
      D.add_Edge(0, c[i] + m, 1);
    }
  for (int i = 1; i <= m; i++) {
    D.add_Edge(i + m, m + m + 1, 1);
  }
  D.n = m + m + 1;
  D.s = 0;
  D.t = m + m + 1;
  int ans = D.dinic();
  cout << ans << "\n";
}
