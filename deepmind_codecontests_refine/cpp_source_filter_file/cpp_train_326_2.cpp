#include <bits/stdc++.h>
using namespace std;
long long d[110][110], INF = 1e18;
long long v[100010];
vector<pair<long long, long long>> base[110];
vector<long long> bst[110];
struct Dinic {
  int nodes, src, dst;
  vector<int> dist, q, work;
  struct edge {
    int to, rev;
    long long f, cap;
  };
  vector<vector<edge>> g;
  Dinic(int x) : nodes(x), g(x), dist(x), q(x), work(x) {}
  void add_edge(int s, int t, long long cap) {
    g[s].push_back((edge){t, int(g[t].size()), 0, cap});
    g[t].push_back((edge){s, int(g[s].size()) - 1, 0, 0});
  }
  bool dinic_bfs() {
    fill(dist.begin(), dist.end(), -1);
    dist[src] = 0;
    int qt = 0;
    q[qt++] = src;
    for (int qh = 0; qh < qt; qh++) {
      int u = q[qh];
      for (int i = 0, ThxDem = int(g[u].size()); i < ThxDem; ++i) {
        edge &e = g[u][i];
        int v = g[u][i].to;
        if (dist[v] < 0 && e.f < e.cap) dist[v] = dist[u] + 1, q[qt++] = v;
      }
    }
    return dist[dst] >= 0;
  }
  long long dinic_dfs(int u, long long f) {
    if (u == dst) return f;
    for (int &i = work[u]; i < int(g[u].size()); i++) {
      edge &e = g[u][i];
      if (e.cap <= e.f) continue;
      int v = e.to;
      if (dist[v] == dist[u] + 1) {
        long long df = dinic_dfs(v, min(f, e.cap - e.f));
        if (df > 0) {
          e.f += df;
          g[v][e.rev].f -= df;
          return df;
        }
      }
    }
    return 0;
  }
  long long max_flow(int _src, int _dst) {
    src = _src;
    dst = _dst;
    long long result = 0;
    while (dinic_bfs()) {
      fill(work.begin(), work.end(), 0);
      while (long long delta = dinic_dfs(src, INF)) result += delta;
    }
    return result;
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0, ThxDem = n; i < ThxDem; ++i)
    for (int j = 0, ThxDem = n; j < ThxDem; ++j) d[i][j] = INF * (i != j);
  for (int i = 0, ThxDem = m; i < ThxDem; ++i) {
    int x, y;
    cin >> x >> y;
    d[x - 1][y - 1] = d[y - 1][x - 1] = 1;
  }
  for (int k = 0, ThxDem = n; k < ThxDem; ++k)
    for (int i = 0, ThxDem = n; i < ThxDem; ++i)
      for (int j = 0, ThxDem = n; j < ThxDem; ++j) {
        if (d[i][k] != INF && d[k][j] != INF)
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
  long long ans = 0, s, b, k;
  cin >> s >> b >> k;
  for (int i = 0, ThxDem = s; i < ThxDem; ++i) v[i] = -INF;
  vector<pair<pair<long long, long long>, pair<long long, long long>>> a(s);
  for (int i = 0, ThxDem = s; i < ThxDem; ++i)
    cin >> a[i].first.first >> a[i].first.second >> a[i].second.first >>
        a[i].second.second,
        a[i].first.first--;
  for (int i = 0, ThxDem = b; i < ThxDem; ++i) {
    long long x, di, g;
    cin >> x >> di >> g;
    x--;
    base[x].push_back({di, g});
  }
  for (int i = 0, ThxDem = n; i < ThxDem; ++i) {
    sort(base[i].begin(), base[i].end());
    bst[i].resize(int(base[i].size()));
    for (int j = 0, ThxDem = int(base[i].size()); j < ThxDem; ++j) {
      bst[i][j] = base[i][j].second;
      if (j) bst[i][j] = max(bst[i][j], bst[i][j - 1]);
    }
  }
  Dinic nt(s + 2);
  for (int i = 0, ThxDem = int(a.size()); i < ThxDem; ++i) {
    for (int j = 0, ThxDem = n; j < ThxDem; ++j) {
      int top =
          upper_bound(base[j].begin(), base[j].end(),
                      (pair<long long, long long>){a[i].first.second, -INF}) -
          base[j].begin() - 1;
      if (d[a[i].first.first][j] <= a[i].second.first && top >= 0) {
        v[i] = max(v[i], bst[j][top] - a[i].second.second);
      }
    }
    if (v[i] < 0)
      nt.add_edge(i + 1, s + 1, -v[i]);
    else
      ans += v[i], nt.add_edge(0, i + 1, v[i]);
  }
  for (int i = 0, ThxDem = k; i < ThxDem; ++i) {
    int x, y;
    cin >> x >> y;
    nt.add_edge(x, y, INF);
  }
  cout << ans - nt.max_flow(0, s + 1) << "\n";
}
