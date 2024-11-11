#include <bits/stdc++.h>
using namespace std;
int n, m, tim;
int mat[505], vis[505];
int mp[505][505], in[505], out[505];
bool dfs(int e, int ban) {
  for (int i = 1; i <= n; i++) {
    if (i == ban || !mp[e][i]) continue;
    if (vis[e] == tim) continue;
    vis[e] = tim;
    if (!mat[i] || dfs(mat[i], ban)) {
      mat[i] = e;
      return 1;
    }
  }
  return 0;
}
int Solve(int rt) {
  int ret = in[rt] + out[rt] - mp[rt][rt];
  int ant = 2 * n - 1 - ret;
  int mch = 0;
  memset(mat, 0, sizeof(mat));
  for (int i = 1; i <= n; i++)
    if (i != rt) ++tim, mch += dfs(i, rt);
  ant += m - ret - mch + n - 1 - mch;
  return ant;
}
int main() {
  cin >> n >> m;
  int u, v;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    mp[u][v] = 1;
    out[u]++;
    in[v]++;
  }
  int ans = 21473846;
  for (int i = 1; i <= n; i++) ans = min(ans, Solve(i));
  printf("%d\n", ans);
  return 0;
}
