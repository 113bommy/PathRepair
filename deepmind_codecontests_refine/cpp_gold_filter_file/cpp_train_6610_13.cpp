#include <bits/stdc++.h>
using namespace std;
const int N = 155, INF = 1e9 + 1000;
int n, m, dis[N][N];
vector<tuple<int, int, int>> edge;
struct matrix {
  bitset<N> v[N], rv[N];
  matrix(int f = 0) {
    for (int i = 0; i < n; i++) {
      v[i].reset();
      rv[i].reset();
    }
    if (f)
      for (int i = 0; i < n; i++) rv[i][i] = v[i][i] = 1;
  }
  void set(int i, int j) { v[i][j] = rv[j][i] = 1; }
  void operator*=(matrix a) {
    matrix t;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if ((v[i] & a.rv[j]).any()) t.set(i, j);
    swap(*this, t);
  }
  friend matrix operator^(matrix a, int b) {
    matrix res(1);
    for (; b; b /= 2, a *= a)
      if (b % 2 == 1) res *= a;
    return res;
  }
} can, adj;
void relax(int u, int v) {
  adj.set(u, v);
  for (int x = 0; x < n; x++)
    for (int y = 0; y < n; y++)
      dis[x][y] = min(dis[x][y], dis[x][u] + 1 + dis[v][y]);
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    edge.push_back({w, --u, --v});
  }
  sort(edge.begin(), edge.end());
  fill(*dis, *end(dis), INF);
  for (int u = 0; u < n; u++) {
    can.set(u, u);
    dis[u][u] = 0;
  }
  int last_w = 0, ans = INF;
  for (auto [w, u, v] : edge) {
    can *= adj ^ (w - last_w);
    relax(u, v);
    for (int x = 0; x < n; x++)
      if (can.v[0][x] == 1) ans = min(ans, w + dis[x][n - 1]);
    last_w = w;
  }
  if (ans < INF)
    cout << ans << endl;
  else
    cout << "Impossible" << endl;
}
