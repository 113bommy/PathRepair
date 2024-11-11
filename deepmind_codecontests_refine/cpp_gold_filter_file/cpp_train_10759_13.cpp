#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = (1uLL << 63) - 1;
const long long mod = 1000000007;
const int N = 150 + 5;
const double Pi = acos(-1.0);
const int maxn = 1e6 + 5;
int E[21][21];
int d[21];
int sum = 0;
bool vis[21];
int cnt = 0;
int num[21];
int dfs(int cur) {
  if (cur == cnt) return 0;
  if (vis[cur]) {
    return dfs(cur + 1);
  }
  vis[cur] = 1;
  int res = inf;
  for (int i = 0; i < cnt; i++) {
    if (!vis[i]) {
      vis[i] = 1;
      res = min(res, E[num[cur]][num[i]] + dfs(cur + 1));
      vis[i] = 0;
    }
  }
  vis[cur] = 0;
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  memset(E, 0x3f, sizeof E);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    sum += w;
    E[u][v] = E[v][u] = min(E[u][v], w);
    d[u]++, d[v]++;
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        E[i][j] = min(E[i][j], E[i][k] + E[k][j]);
      }
    }
  }
  if (m == 0) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 2; i <= n; i++) {
    if (E[1][i] == E[0][0] && d[i]) {
      cout << -1 << endl;
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (d[i] & 1) num[cnt++] = i;
  }
  cout << sum + dfs(0) << endl;
}
