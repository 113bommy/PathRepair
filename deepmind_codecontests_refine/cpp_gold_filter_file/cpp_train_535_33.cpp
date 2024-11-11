#include <bits/stdc++.h>
using namespace std;
struct edge {
  int to, cap, cost, rev;
  edge(int _to, int _cap, int _cost, int _rev)
      : to(_to), cap(_cap), cost(_cost), rev(_rev) {}
};
struct cost {
  vector<edge> graph[10000];
  int pre[10000], pre_e[10000], inq[10000], F, C;
  int dist[10000];
  cost() {
    F = 0;
    C = 0;
    fill(graph, graph + 10000, vector<edge>());
  }
  void add(int from, int to, int cap, int cost) {
    graph[from].push_back(edge(to, cap, cost, graph[to].size()));
    graph[to].push_back(edge(from, 0, -cost, graph[from].size() - 1));
  }
  bool bfs(int ini, int fim) {
    fill(dist, dist + 10000, 1000000007);
    fill(inq, inq + 10000, 0);
    dist[ini] = 0;
    queue<int> q;
    q.push(ini);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      inq[u] = 0;
      for (int i = 0; i < (int)graph[u].size(); i++) {
        int v = graph[u][i].to;
        int w = graph[u][i].cost;
        if (graph[u][i].cap > 0 && dist[v] > dist[u] + w) {
          pre[v] = u;
          pre_e[v] = i;
          dist[v] = dist[u] + w;
          if (!inq[v]) {
            inq[v] = true;
            q.push(v);
          }
        }
      }
    }
    return dist[fim] != 1000000007;
  }
  pair<int, int> flow(int ini, int fim) {
    while (bfs(ini, fim)) {
      int tf = 1000000007;
      for (int v = fim, u, l; v != ini; v = u) {
        u = pre[v];
        l = pre_e[v];
        tf = min(tf, graph[u][l].cap);
      }
      for (int v = fim, u, l; v != ini; v = u) {
        u = pre[v];
        l = pre_e[v];
        graph[u][l].cap -= tf;
        graph[v][graph[u][l].rev].cap += tf;
      }
      C += tf * dist[fim];
      F += tf;
    }
    return make_pair(F, C);
  }
};
int T = 10000 - 2, P = 10000 - 1;
vector<int> g[10000];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cost fluxo = cost();
  int n, m, k, c, d;
  cin >> n >> m >> k >> c >> d;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    fluxo.add(T, x - 1, 1, 0);
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 0; i < 102; i++) {
    for (int j = 0; j < n; j++) {
      for (int u = 0; u < (int)g[j].size(); u++) {
        int to = g[j][u];
        int aux = 1;
        for (int v = 1; v <= k; v++) {
          fluxo.add(50 * i + j, 50 * (i + 1) + to, 1, c + d * aux);
          aux += 2;
        }
      }
      fluxo.add(50 * i + j, 50 * (i + 1) + j, k, c);
    }
  }
  for (int i = 0; i <= 102; i++) fluxo.add(50 * i, P, k, 0);
  cout << fluxo.flow(T, P).second << endl;
  return 0;
}
