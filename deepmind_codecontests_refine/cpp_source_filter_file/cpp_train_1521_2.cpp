#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int N = 1004;
int x[N], y[N], r[N], n, par[N];
vector<int> adj[N];
double dist(int x0, int y0, int x1, int y1) {
  int dx = x0 - x1, dy = y0 - y1;
  return sqrt(1.0 * dx * dx + dy * dy);
}
double area(int r) { return 1.0 * r * r * PI; }
void build() {
  for (int i = 0; i < n; ++i) {
    par[i] = -1;
    for (int j = 0; j < n; ++j) {
      if (i == j || r[j] < r[i]) continue;
      if (dist(x[i], y[i], x[j], y[j]) < r[j]) {
        if (par[i] == -1) par[i] = j;
        if (r[par[i]] > r[j]) par[i] = j;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (~par[i]) adj[par[i]].push_back(i);
  }
}
bool vis[N];
double dfs(int u, int d) {
  vis[u] = true;
  double ret = 0.0;
  if (d == 0 || d & 1)
    ret += area(r[u]);
  else
    ret -= area(r[u]);
  for (int c : adj[u]) {
    ret += dfs(c, d + 1);
  }
  return ret;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i] >> r[i];
  }
  build();
  double res = 0;
  for (int i = 0; i < n; ++i) {
    if (par[i] == -1) {
      res += dfs(i, 0);
    }
  }
  cout << fixed << setprecision(10) << res << "\n";
}
