#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int BASE = 1e9 + 7;
const int maxK = 21;
int dp[maxn][maxK][maxK];
int foo[maxK][maxK];
vector<int> adj[maxn];
int n, k;
inline int Add(int a, int b) {
  a += b;
  if (a >= BASE) a -= BASE;
  return a;
}
inline int Mul(int a, int b) { return (long long)a * b % BASE; }
void Join(int u, int v) {
  memset(foo, 0, sizeof foo);
  for (int x = 0; x <= k + 1; ++x)
    for (int y = 0; y <= k + 1; ++y)
      for (int a = 0; a <= k + 1; ++a)
        for (int b = 0; b <= k + 1; ++b) {
          int nxtMax = 0;
          if (x - 1 + b - 1 + 1 > k) nxtMax = max(nxtMax, b + 1);
          if (a - 1 + y - 1 + 1 > k) nxtMax = max(nxtMax, y);
          int nxtMin = min(x, a + 1);
          foo[nxtMin][nxtMax] =
              Add(foo[nxtMin][nxtMax], Mul(dp[u][x][y], dp[v][a][b]));
        }
  for (int x = 0; x <= k + 1; ++x)
    for (int y = 0; y <= k + 1; ++y) dp[u][x][y] = foo[x][y];
}
void DFS(int u, int par = -1) {
  for (int i = 0; i < adj[u].size(); ++i) {
    int v = adj[u][i];
    if (v == par) continue;
    DFS(v, u);
  }
  dp[u][k + 1][1] = dp[u][1][0] = 1;
  for (int i = 0; i < adj[u].size(); ++i) {
    int v = adj[u][i];
    if (v == par) continue;
    Join(u, v);
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  DFS(1);
  int ans = 0;
  for (int i = 0; i <= k + 1; ++i) ans = Add(ans, dp[1][i][0]);
  printf("%d", ans);
  return 0;
}
