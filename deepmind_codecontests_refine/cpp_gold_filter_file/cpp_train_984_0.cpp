#include <bits/stdc++.h>
using namespace std;
const int inf = numeric_limits<int>::max();
const long long linf = numeric_limits<long long>::max();
const int max_n = 101;
int n, m, q;
bool g[max_n][max_n][max_n], visited[max_n];
bool dfs(int st, int end, int col, int par = -1) {
  if (st == end) return true;
  if (visited[st]) return false;
  visited[st] = true;
  bool ret = false;
  for (int i = 0; i < (max_n); ++i) {
    if (g[st][i][col] && i != par) ret |= dfs(i, end, col, st);
  }
  return ret;
}
int main() {
  int u, v, c;
  cin >> n;
  cin >> m;
  for (int i = 0; i < (m); ++i) {
    cin >> u, cin >> v, cin >> c;
    g[u][v][c] = true;
    g[v][u][c] = true;
  }
  cin >> q;
  for (int i = 0; i < (q); ++i) {
    cin >> u, cin >> v;
    c = 0;
    for (int j = (1); j < (m + 1); ++j) {
      fill(visited, visited + max_n, false);
      c += dfs(u, v, j);
    }
    cout << c << endl;
  }
  return 0;
}
