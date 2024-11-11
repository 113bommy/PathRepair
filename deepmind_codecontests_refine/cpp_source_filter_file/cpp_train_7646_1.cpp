#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m, par[N], val[N], F[N][N], valsum[N], sack[N], mat[N][N];
int x, y;
vector<int> G[N], newG[N];
int Time, low[N], num[N], bridge[N][N], ans, res;
void Dfs(int u, int p) {
  low[u] = num[u] = ++Time;
  for (int i = 0; i < G[u].size(); ++i) {
    int v = G[u][i];
    if (v == p) continue;
    if (num[v] != 0)
      low[u] = min(low[u], num[v]);
    else {
      Dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] >= num[v]) bridge[u][v] = bridge[v][u] = 1;
    }
  }
}
int Sum(int u, int p) {
  valsum[u] = val[u];
  for (int i = 0; i < newG[u].size(); ++i) {
    int v = newG[u][i];
    if (v == p) continue;
    int dwsum = Sum(v, u);
    valsum[u] += dwsum;
    res += (val[u] * dwsum);
  }
  res += (val[u] * (val[u] - 1));
  return valsum[u];
}
int Find(int u) {
  if (u == par[u]) return u;
  return par[u] = Find(par[u]);
}
void Join(int u, int v) {
  int fu = Find(u), fv = Find(v);
  if (fu != fv) {
    par[fu] = fv;
    val[fv] += val[fu];
    val[fu] = 0;
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
    mat[x][y] = mat[y][x] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    par[i] = i;
    val[i] = 1;
  }
  Dfs(1, 0);
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j) {
      if (!bridge[i][j] && mat[i][j]) Join(i, j);
    }
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      if (bridge[i][j]) {
        int fi = Find(i), fj = Find(j);
        newG[fi].push_back(fj);
        newG[fj].push_back(fi);
      }
  for (int node = 1; node <= n; ++node) {
    if (node != Find(node)) continue;
    res = n;
    memset(valsum, 0, sizeof valsum);
    Sum(node, 0);
    int sz = newG[node].size();
    for (int i = 0; i < sz; ++i) {
      sack[i + 1] = valsum[newG[node][i]];
      memset(F[i + 1], 0, sizeof F[i + 1]);
    }
    F[0][0] = 1;
    for (int j = 0; j <= n; ++j)
      for (int i = 1; i <= sz; ++i) {
        F[i][j] |= F[i - 1][j];
        if (sack[i] <= j) {
          F[i][j] |= F[i - 1][j - sack[i]];
        }
      }
    for (int i = 0; i <= n; ++i) {
      if (F[sz][i]) {
        ans = max(ans, res + i * (n - i - val[i]));
      }
    }
  }
  cout << ans;
}
