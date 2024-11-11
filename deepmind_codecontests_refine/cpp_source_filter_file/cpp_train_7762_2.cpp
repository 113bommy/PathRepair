#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 1;
vector<int> edges[N];
int used[N];
int c[N];
int pv[N];
int cv[N];
int sup[N];
int edge[N][N];
int counter, vertex;
void precalc() {
  sup[2] = 1;
  for (int i = 3; i < N; i++) sup[i] = sup[i - 1] + i - 1;
}
int dfs(int v, int st = 0) {
  vertex++;
  used[v] = 1;
  if (c[v]) st = v;
  for (auto u : edges[v]) {
    if (!edge[v][u]) {
      counter++;
      edge[v][u] = 1;
      edge[u][v] = 1;
    }
    if (!used[u]) dfs(u);
  }
  return st;
}
void solve() {
  int n, m, k, v, u;
  cin >> n >> m >> k;
  long long ans = 0;
  for (int i = 0; i < k; i++) {
    cin >> v;
    c[v] = 1;
    pv[v] = 1;
  }
  for (int i = 0; i < m; i++) {
    cin >> v >> u;
    edges[v].push_back(u);
    edges[u].push_back(v);
  }
  int st, mx = -1, spp = 0;
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      counter = 0;
      vertex = 0;
      st = dfs(i);
      if (st) {
        c[st] = vertex;
        if (vertex > mx) {
          spp = st;
          mx = vertex;
        }
      } else
        c[i] = vertex;
      ans = ans + sup[vertex] - counter;
    }
  }
  int jk = 0;
  if (mx == -1) {
    cout << ans;
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (pv[i]) continue;
    jk += mx * c[i];
    mx += c[i];
  }
  cout << ans + jk;
}
int main() {
  ios_base::sync_with_stdio(0);
  precalc();
  solve();
}
