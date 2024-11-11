#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10, inf = 1e9 + 10, MOD = 1e9 + 7, Sq = 708;
const long long INF = 1e18 + 10;
int p[maxn], dp[maxn][25], h[maxn];
int par(int u, int v) {
  for (int i = 22; i >= 0; i--)
    if ((1 << i) & v) u = dp[u][i];
  return u;
}
int LCA(int u, int v) {
  if (h[u] > h[v]) swap(u, v);
  int res = h[v] - h[u];
  v = par(v, h[v] - h[u]);
  for (int i = 22; i >= 0; i--)
    if (h[u] >= (1 << i) && dp[u][i] != dp[v][i]) {
      u = dp[u][i];
      v = dp[v][i];
      res += (1 << i) * 2;
    }
  if (u != v && dp[u][0] == dp[v][0]) res += 2;
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, l, r, d;
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> p[i];
    p[i]--;
    dp[i][0] = p[i];
    h[i] = h[p[i]] + 1;
    if (i == 1)
      l = p[i], r = i, d = 1;
    else {
      for (int j = 1; j <= 22; j++)
        if (h[i] >= (1 << i))
          dp[i][j] = dp[dp[i][j - 1]][j - 1];
        else
          break;
      if (LCA(i, l) > d) d = LCA(i, l), r = i;
      if (LCA(i, r) > d) d = LCA(i, r), l = i;
    }
    cout << d << " ";
  }
  return 0;
}
