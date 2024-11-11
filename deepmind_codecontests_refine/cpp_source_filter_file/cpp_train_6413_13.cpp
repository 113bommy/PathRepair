#include <bits/stdc++.h>
const int N = 2e5 + 5;
const int inf = 2e9;
struct Edge {
  int u, v, cost, isin;
  int ind;
  bool operator<(const Edge& x) const { return cost < x.cost; }
};
std::vector<Edge> e;
std::vector<std::pair<int, int> > l[N];
int tata[N], sz[N], ans[N];
int findDaddy(int node) {
  if (node == tata[node]) return node;
  return tata[node] = findDaddy(tata[node]);
}
bool areConnected(int u, int v) { return (findDaddy(u) == findDaddy(v)); }
void connect(int u, int v) {
  if (sz[findDaddy(u)] > sz[findDaddy(v)]) {
    sz[findDaddy(u)] += sz[findDaddy(v)];
    tata[findDaddy(v)] = findDaddy(u);
  } else {
    sz[findDaddy(v)] += sz[findDaddy(u)];
    tata[findDaddy(u)] = findDaddy(v);
  }
}
int rmq[20][N], mx[20][N], h[N], mn[N];
void dfs(int node, int from = 0, int c = 0) {
  rmq[0][node] = from, mx[0][node] = c, h[node] = h[from] + 1;
  for (std::pair<int, int> to : l[node])
    if (to.first != from) dfs(to.first, node, to.second);
}
std::pair<int, int> maxlca(int from, int to) {
  int sol = 0;
  if (h[from] < h[to]) std::swap(from, to);
  for (int i = 20; i >= 0; i--)
    if (h[from] - (1 << i) >= h[to]) {
      sol = (((sol) > (mx[i][from])) ? (sol) : (mx[i][from]));
      from = rmq[i][from];
    }
  if (from == to) return {from, sol};
  for (int i = 20; i >= 0; i--)
    if (rmq[i][from] != rmq[i][to]) {
      sol = (((sol) >
              ((((mx[i][from]) > (mx[i][to])) ? (mx[i][from]) : (mx[i][to]))))
                 ? (sol)
                 : ((((mx[i][from]) > (mx[i][to])) ? (mx[i][from])
                                                   : (mx[i][to]))));
      from = rmq[i][from], to = rmq[i][to];
    }
  sol =
      (((sol) > ((((mx[0][from]) > (mx[0][to])) ? (mx[0][from]) : (mx[0][to]))))
           ? (sol)
           : ((((mx[0][from]) > (mx[0][to])) ? (mx[0][from]) : (mx[0][to]))));
  return {rmq[0][from], sol};
}
void update(int from, int to, int cost) {
  to = findDaddy(to), from = findDaddy(from);
  while (from != to) {
    if (h[from] < h[to]) std::swap(from, to);
    mn[from] = cost - 1;
    tata[from] = rmq[0][from];
    from = findDaddy(from);
  }
}
int main() {
  int n, m, from, to, cost;
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    std::cin >> from >> to >> cost;
    e.push_back({from, to, cost, 0, i});
  }
  for (int i = 1; i <= n; i++) tata[i] = i, sz[i] = 1;
  std::sort(e.begin(), e.end());
  for (Edge& curr : e) {
    if (!areConnected(curr.u, curr.v)) {
      l[curr.u].push_back({curr.v, curr.cost});
      l[curr.v].push_back({curr.u, curr.cost});
      connect(curr.u, curr.v);
      curr.isin = 1;
    }
  }
  dfs(1);
  for (int i = 1; i < 20; i++)
    for (int j = 1; j <= n; j++) {
      rmq[i][j] = rmq[i - 1][rmq[i - 1][j]];
      mx[i][j] = (((mx[i - 1][j]) > (mx[i - 1][rmq[i - 1][j]]))
                      ? (mx[i - 1][j])
                      : (mx[i - 1][rmq[i - 1][j]]));
    }
  for (Edge& curr : e)
    if (!curr.isin) {
      std::pair<int, int> x = maxlca(curr.u, curr.v);
      ans[curr.ind] = x.second - 1;
    }
  for (int i = 1; i <= n; i++) tata[i] = i, mn[i] = inf;
  for (Edge& curr : e)
    if (!curr.isin) update(curr.u, curr.v, curr.cost);
  for (Edge& curr : e) {
    if (!curr.isin) continue;
    if (h[curr.u] < h[curr.v]) std::swap(curr.u, curr.v);
    ans[curr.ind] = -1;
    if (rmq[0][curr.u] == curr.v and mn[curr.u] != inf)
      ans[curr.ind] = mn[curr.u];
  }
  for (int i = 1; i <= m; i++) std::cout << ans[i] << " ";
}
