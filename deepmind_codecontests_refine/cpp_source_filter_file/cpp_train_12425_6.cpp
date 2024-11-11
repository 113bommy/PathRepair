#include <bits/stdc++.h>
using namespace std;
int n, x, y, k1, k2, kol;
vector<int> g[5001];
int m[5001][5001];
bool w[5001], r[5000];
void dfs(int v) {
  w[v] = 1;
  kol++;
  for (int i = 0; i < g[v].size(); i++) {
    int to = g[v][i];
    if (!w[to]) dfs(to);
  }
}
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  bool ok = 0;
  for (int i = 1; i <= n; i++) {
    if (g[i].size() == 1)
      continue;
    else {
      fill(w, w + n + 1, false);
      k1 = k2 = 0;
      w[i] = 1;
      int a[5000], l = 0;
      for (int j = 0; j < g[i].size(); j++) {
        kol = 0;
        dfs(g[i][j]);
        a[++l] = kol;
      }
      bool dp[5000];
      fill(dp, dp + n, false);
      dp[0] = 1;
      for (int j = 1; j <= l; j++)
        for (int s = n; s >= a[j]; s--)
          if (dp[s - a[j]]) dp[s] = 1;
      for (int j = 1; j < n; j++)
        if (dp[j]) r[j] = 1;
    }
  }
  int res = 0;
  for (int i = 1; i < n; i++)
    if (r[i]) res++;
  cout << res << endl;
  for (int i = 1; i < n - 1; i++)
    if (r[i]) cout << i << " " << n - 1 - i << endl;
  return 0;
}
