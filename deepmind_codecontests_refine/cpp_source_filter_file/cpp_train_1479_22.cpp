#include <bits/stdc++.h>
using namespace std;
vector<long long> graph[100000];
long long orders[6][3] = {{0, 1},    {0, 2, 1}, {1, 0, 2},
                          {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
long long dfs(long long v, long long p, long long d, long long i,
              vector<long long> c[], vector<long long> &painting) {
  painting[v] = orders[i][d] + 1;
  long long res = c[orders[i][d]][v];
  for (long long u : graph[v])
    if (u != p) res += dfs(u, v, (d + 1) % 3, i, c, painting);
  return res;
}
int main() {
  long long n;
  cin >> n;
  vector<long long> c[3];
  c[0].resize(n);
  for (long long i = 0; i < n; i++) cin >> c[0][i];
  c[1].resize(n);
  for (long long i = 0; i < n; i++) cin >> c[1][i];
  c[2].resize(n);
  for (long long i = 0; i < n; i++) cin >> c[2][i];
  for (long long i = 0; i < n - 1; i++) {
    long long u, v;
    cin >> u >> v;
    u--;
    v--;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  long long start = -1;
  for (long long i = 0; i < n; i++) {
    if (graph[i].size() > 2) {
      cout << -1;
      return 0;
    } else if (graph[i].size() == 1)
      start = i;
  }
  vector<long long> painting(n, -1);
  long long res = 1e18;
  long long o = -1;
  for (long long i = 0; i < 6; i++) {
    long long h = dfs(start, -1, 0, i, c, painting);
    if (h < res) {
      res = h;
      o = i;
    }
  }
  dfs(start, -1, 0, o, c, painting);
  cout << res << '\n';
  for (long long i : painting) cout << i << ' ';
  return 0;
}
