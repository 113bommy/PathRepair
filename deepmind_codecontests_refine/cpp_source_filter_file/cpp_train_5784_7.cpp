#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1E3 + 2;
const int MAXM = 3E4 + 2;
const int MAX = 2E9 + 100;
struct DisjointSet {
  vector<int> p;
  void init(int n) {
    p.resize(n + 1);
    iota(p.begin() + 1, p.begin() + n + 1, 1);
  }
  int root(int i) { return p[i] == i ? i : p[i] = root(p[i]); }
  bool unify(int i, int j) {
    int x = root(i), y = root(j);
    if (x == y) return false;
    p[x] = y;
    return true;
  }
};
struct edge {
  int u, v;
  int id;
};
int n, m;
int S, T;
int ans;
vector<int> edgeDel;
vector<pair<int, int> > g[MAXN];
vector<edge> Edges(MAXM);
vector<int> Weight(MAXM);
vector<bool> check(MAXM, 0);
int dupEdge[MAXN][MAXN];
DisjointSet dsu;
void constructGraph() {
  for (int j = 0; j < 3; ++j) {
    dsu.init(n);
    for (int i = 1; i <= m; ++i) {
      if (!check[i]) {
        check[i] = dsu.unify(Edges[i].u, Edges[i].v);
      }
    }
    if (j == 0 && dsu.root(S) != dsu.root(T)) {
      cout << 0;
      exit(0);
    }
  }
  for (int i = 1; i <= m; ++i) {
    if (check[i]) {
      g[Edges[i].u].push_back({Edges[i].v, Edges[i].id});
      g[Edges[i].v].push_back({Edges[i].u, Edges[i].id});
      ++dupEdge[Edges[i].u][Edges[i].v];
    }
  }
}
vector<int> low(MAXN, 0), num(MAXN, 0), par(MAXN, 0);
int C = 0;
int idw = -1;
void reset() {
  for (int i = 1; i <= n; ++i) low[i] = num[i] = par[i] = 0;
  C = 0;
  idw = -1;
}
bool dfs(int u, int delId) {
  low[u] = num[u] = ++C;
  bool isFinished = false;
  for (pair<int, int> coup : g[u]) {
    int v = coup.first;
    int index = coup.second;
    if (index == delId) continue;
    if (!num[v]) {
      par[v] = u;
      bool reachable = dfs(v, delId);
      if (low[v] > num[u] && reachable) {
        if (dupEdge[min(u, v)][max(u, v)] == 1) {
          if (idw == -1)
            idw = index;
          else
            idw = (Weight[idw] > Weight[index] ? index : idw);
        }
      }
      isFinished |= reachable;
      low[u] = min(low[u], low[v]);
    } else if (v != par[u]) {
      low[u] = min(low[u], num[v]);
    }
  }
  isFinished |= (u == T);
  return isFinished;
}
signed main() {
  cin >> n >> m;
  cin >> S >> T;
  for (int i = 1; i <= m; ++i) {
    cin >> Edges[i].u >> Edges[i].v >> Weight[i];
    if (Edges[i].u > Edges[i].v) swap(Edges[i].u, Edges[i].v);
    Edges[i].id = i;
  }
  sort(Edges.begin() + 1, Edges.begin() + m + 1,
       [&](edge x, edge y) { return Weight[x.id] < Weight[y.id]; });
  ans = -1;
  constructGraph();
  for (int i = 1; i <= m; ++i) {
    if (!check[i]) continue;
    --dupEdge[Edges[i].u][Edges[i].v];
    reset();
    bool reach = dfs(S, Edges[i].id);
    ++dupEdge[Edges[i].u][Edges[i].v];
    if (!reach) {
      if (ans == -1 || ans > Weight[Edges[i].id]) {
        ans = Weight[Edges[i].id];
        edgeDel.clear();
        edgeDel.push_back(Edges[i].id);
      }
    } else {
      if (idw == -1) continue;
      if (ans == -1 || ans > Weight[Edges[i].id] + Weight[idw]) {
        ans = Weight[Edges[i].id] + Weight[idw];
        edgeDel.clear();
        edgeDel.push_back(Edges[i].id);
        edgeDel.push_back(idw);
      }
    }
  }
  if (ans <= 0) {
    cout << ans;
    return 0;
  }
  cout << ans << "\n";
  cout << edgeDel.size() << "\n";
  for (int i : edgeDel) cout << i << " ";
}
