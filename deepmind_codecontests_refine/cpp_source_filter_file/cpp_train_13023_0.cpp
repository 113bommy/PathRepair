#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > g[4];
int vis[4], d[4];
int dfs(int c) {
  vis[c] = 1;
  int ans = 0;
  for (int i = 0; i < g[c].size(); i++) {
    ans += g[c][i].second;
    if (!vis[g[c][i].first]) ans += dfs(g[c][i].first);
  }
  return ans;
}
int main() {
  int maxi = 0, com = 0, n, mini = 1000000000, odd = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int u, v, val;
    scanf("%d", &u), scanf("%d", &val), scanf("%d", &v);
    u--, v--;
    g[u].push_back(make_pair(v, val));
    g[v].push_back(make_pair(u, val));
    if (u != v) {
      d[u]++;
      d[v]++;
    }
  }
  for (int i = 0; i < 4; i++) {
    if (!vis[i]) maxi = max(maxi, dfs(i) / 2), com++;
    if (d[i] % 2) odd++;
  }
  if (com == 1) {
    if (odd == 4) {
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < g[i].size(); j++) {
          if (d[i] == 1 || d[g[i][j].first] == 1) continue;
          if (g[i][j].second != i) mini = min(mini, g[i][j].second);
        }
      }
      printf("%d\n", maxi - mini);
    } else
      printf("%d\n", maxi);
  } else
    printf("%d\n", maxi);
  return 0;
}
