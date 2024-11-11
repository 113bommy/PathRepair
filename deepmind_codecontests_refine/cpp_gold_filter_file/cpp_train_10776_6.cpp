#include <bits/stdc++.h>
using namespace std;
const int maxn = 600;
vector<long long> g[maxn];
long long ma[maxn][maxn], col[maxn], deg[maxn];
bool flag = 1;
void dfs(long long u, long long color) {
  col[u] = color;
  for (long long i = 0; i < g[u].size(); i++) {
    long long v = g[u][i];
    if (col[v] == col[u]) {
      flag = 0;
      return;
    }
    if (!col[v]) {
      dfs(v, 4 - color);
    }
  }
}
int main(void) {
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  long long n, m;
  cin >> n >> m;
  for (long long i = 1; i <= m; i++) {
    long long x, y;
    cin >> x >> y;
    ma[x][y] = ma[y][x] = 1;
    deg[x]++;
    deg[y]++;
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      if (i == j) continue;
      if (!ma[i][j]) g[i].push_back(j), g[j].push_back(i);
    }
  }
  for (long long i = 1; i <= n; i++) {
    if (deg[i] == n - 1) col[i] = 2;
  }
  for (long long i = 1; i <= n; i++) {
    if (!col[i]) {
      dfs(i, 1);
      break;
    }
  }
  if (flag == 0)
    cout << "NO" << endl;
  else {
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= n; j++) {
        if (i == j) continue;
        if (ma[i][j] && abs(col[i] - col[j]) >= 2) {
          cout << "NO" << endl;
          return 0;
        }
      }
    }
    cout << "YES" << endl;
    for (long long i = 1; i <= n; i++) {
      if (col[i] == 1) cout << "a";
      if (col[i] == 2) cout << "b";
      if (col[i] == 3) cout << "c";
    }
    cout << endl;
  }
  return 0;
}
