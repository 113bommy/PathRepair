#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
const int MAX = 50;
int R[MAX][MAX], D[MAX], V, E, s, t, x;
vvi G;
int Push(int x, int flow) {
  if (x == t) return flow;
  for (int y : G[x])
    if (R[x][y] > 0 && D[y] == D[x] + 1)
      if (int f = Push(y, min(flow, R[x][y])))
        return R[x][y] -= f, R[y][x] += f, f;
  return D[x] = -1, 0;
}
bool LevelGraph() {
  queue<int> Q;
  Q.push(s);
  memset(D, -1, sizeof(D));
  D[s] = 0;
  while (!Q.empty()) {
    int k = Q.front();
    Q.pop();
    if (k == t) return true;
    for (int x : G[k])
      if (D[x] == -1 && R[k][x] > 0) D[x] = D[k] + 1, Q.push(x);
  }
  return false;
}
void process(int u, int v) {
  G[u].push_back(v);
  G[v].push_back(u);
}
int dinic() {
  int MF = 0;
  while (LevelGraph())
    while (int f = Push(s, 1e9)) MF += f;
  return MF;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> V >> E >> x;
  G.resize(V);
  vector<iii> es;
  for (int i = 0; i < E; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    es.emplace_back(a - 1, b - 1, c);
    process(a - 1, b - 1);
  }
  s = 0, t = V - 1;
  double lo = 0, hi = 1e6;
  for (int i = 0; i < 60; ++i) {
    double mid = (lo + hi) / 2;
    memset(R, 0, sizeof R);
    for (int i = 0; i < E; ++i) {
      auto [a, b, c] = es[i];
      R[a][b] = c / mid;
    }
    int mf = dinic();
    if (mf >= x)
      lo = mid;
    else
      hi = mid;
  }
  cout << setprecision(10) << fixed << (lo + hi) * x / 2;
}
