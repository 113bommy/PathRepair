#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 777, N = 155, K = 30;
bitset<N> movement[K][N];
bitset<N> can_be, column_temp;
void column(bitset<N> a[N], int &c) {
  for (int i = 0; i < N; ++i) column_temp[i] = a[i][c];
}
void mult(bitset<N> a[N], bitset<N> b[N], bitset<N> res[N]) {
  bitset<N> temp;
  for (int j = 0; j < N; ++j) {
    column(b, j);
    for (int i = 0; i < N; ++i) {
      temp = a[i] & column_temp;
      res[i][j] = temp.any();
    }
  }
}
void apply(bitset<N> a[N], bitset<N> &b) {
  bitset<N> temp;
  bitset<N> res;
  res.reset();
  for (int i = 0; i < N; ++i) {
    temp = a[i] & b;
    res[i] = temp.any();
  }
  b = res;
}
void nope() {
  cout << "Impossible\n";
  exit(0);
}
int n, m;
struct edge {
  int c, r, d;
  bool operator<(const edge &t) const { return d < t.d; }
};
vector<edge> edges;
int shortest_path(bitset<N> &start) {
  vector<pair<int, int> > bfs;
  vector<bool> visited(N);
  for (int i = 1; i <= n; ++i)
    if (start[i]) {
      visited[i] = true;
      bfs.push_back({i, 0});
    }
  for (int i = 0; i < bfs.size(); ++i) {
    int u = bfs[i].first, c = bfs[i].second;
    if (u == n) return c;
    for (int v = 1; v <= n; ++v) {
      if (!visited[v] && movement[0][v][u]) {
        visited[v] = true;
        bfs.push_back({v, c + 1});
      }
    }
  }
  return INF;
}
int main() {
  cin >> n >> m;
  edges.resize(m);
  for (int i = 0; i < m; ++i) {
    cin >> edges[i].c >> edges[i].r >> edges[i].d;
  }
  sort(edges.begin(), edges.end());
  int ans = INF;
  can_be.set(1);
  if (edges[0].d != 0) nope();
  for (int i = 0; i < m; ++i) {
    for (int j = 1; j < K; ++j)
      mult(movement[j - 1], movement[j - 1], movement[j]);
    int dist = (i > 0 ? edges[i].d - edges[i - 1].d : 0);
    for (int j = K - 1; j >= 0; --j)
      if (dist >= (1 << j)) {
        dist -= 1 << j;
        apply(movement[j], can_be);
      }
    movement[0][edges[i].r][edges[i].c] = true;
    ans = min(ans, edges[i].d - dist + shortest_path(can_be));
  }
  if (ans == INF) nope();
  cout << ans << '\n';
};
