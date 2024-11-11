#include <bits/stdc++.h>
using namespace std;
struct Dinic {
  struct Edge {
    long long flow;
    int to, next;
  };
  vector<Edge> edges;
  vector<int> adia, at, dist;
  int S, D;
  void add_Edge(int from, int to, long long cap) {
    edges.push_back({cap, to, adia[from]});
    adia[from] = edges.size() - 1;
    edges.push_back({0, from, adia[to]});
    adia[to] = edges.size() - 1;
  }
  bool bfs() {
    queue<int> q;
    fill(dist.begin(), dist.end(), 1e9);
    dist[S] = 0;
    q.push(S);
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (int i = adia[x]; i != -1; i = edges[i].next) {
        if (dist[edges[i].to] > dist[x] + 1 && edges[i].flow) {
          dist[edges[i].to] = 1 + dist[x];
          q.push(edges[i].to);
        }
      }
    }
    return dist[D] < 1e9;
  }
  long long dfs(int nod, long long fmax) {
    if (nod == D) return fmax;
    while (at[nod] != -1) {
      Edge &e = edges[at[nod]];
      long long f;
      if (dist[e.to] == dist[nod] + 1 && e.flow &&
          (f = dfs(e.to, min(fmax, e.flow)))) {
        e.flow -= f;
        edges[at[nod] ^ 1].flow += f;
        return f;
      }
      at[nod] = edges[at[nod]].next;
    }
    return 0;
  }
  long long GetFlow() {
    long long f = 0;
    while (bfs()) {
      at = adia;
      while (long long x = dfs(S, 1e18)) f += x;
    }
    return f;
  }
  Dinic(int n = 0, int s = 0, int d = 0) {
    S = s, D = d;
    at = dist = adia = vector<int>(n + 1, -1);
  }
};
const int NMAX = 110;
int dmin[NMAX][NMAX];
struct Object {
  int cost, nod, power, id, fuel, atac;
};
vector<Object> ships, bases;
vector<pair<int, int>> dependencies;
int n;
int best_cost[NMAX];
void get_cost_nave() {
  fill(best_cost, best_cost + n + 1, -1);
  vector<int> nv(ships.size());
  iota(nv.begin(), nv.end(), 0);
  sort(nv.begin(), nv.end(),
       [](int a, int b) { return ships[a].power < ships[b].power; });
  sort(bases.begin(), bases.end(),
       [](Object a, Object b) { return a.power < b.power; });
  int it = 0;
  for (auto i : nv) {
    while (it != bases.size() && ships[i].power >= bases[it].power) {
      best_cost[bases[it].nod] = max(best_cost[bases[it].nod], bases[it].cost);
      it++;
    }
    int best = -1;
    for (int nod = 1; nod <= n; nod++)
      if (dmin[nod][ships[i].nod] <= ships[i].fuel)
        best = max(best, best_cost[nod]);
    ships[i].atac = best;
  }
}
void read() {
  int m, a, b;
  scanf("%d%d", &n, &m);
  fill(dmin[0], dmin[n + 1], 1e9);
  for (int i = 1; i <= n; i++) dmin[i][i] = 0;
  while (m--) {
    scanf("%d%d", &a, &b);
    dmin[a][b] = dmin[b][a] = 1;
  }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        dmin[i][j] = min(dmin[i][j], dmin[i][k] + dmin[k][j]);
  int s, k;
  scanf("%d%d%d", &s, &b, &k);
  ships.resize(s);
  bases.resize(b);
  dependencies.resize(k);
  for (auto &i : ships) {
    scanf("%d%d%d%d", &i.nod, &i.power, &i.fuel, &i.cost);
    i.fuel = min(i.fuel, 1000000);
  }
  for (auto &i : bases) scanf("%d%d%d", &i.nod, &i.power, &i.cost);
  for (auto &i : dependencies) scanf("%d%d", &i.first, &i.second);
}
int main() {
  read();
  get_cost_nave();
  long long ans = 0;
  int cnt = 2, S = 1, D = 2;
  const long long inf = 1e18;
  for (auto &i : dependencies) {
    i.first--, i.second--;
    if (!ships[i.first].id) ships[i.first].id = ++cnt;
    if (!ships[i.second].id) ships[i.second].id = ++cnt;
  }
  Dinic flow(cnt + 1, S, D);
  for (auto i : ships) {
    if (i.id) {
      if (i.atac == -1)
        flow.add_Edge(i.id, D, inf);
      else {
        int castig = i.atac - i.cost;
        if (castig > 0) {
          ans += castig;
          flow.add_Edge(S, i.id, castig);
        } else
          flow.add_Edge(i.id, D, -castig);
      }
    } else
      ans += min(0, i.atac - i.cost);
  }
  for (auto i : dependencies)
    flow.add_Edge(ships[i.first].id, ships[i.second].id, inf);
  ans -= flow.GetFlow();
  cout << ans << '\n';
  return 0;
}
