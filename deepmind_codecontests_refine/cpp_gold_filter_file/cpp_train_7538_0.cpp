#include <bits/stdc++.h>
using namespace std;
vector<int> s[505 * 2];
int match[505 * 2], vi[505 * 2];
int n, m, ma[505][505];
int dfs(int u) {
  int i;
  for (i = 0; i < s[u].size(); i++) {
    int v = s[u][i];
    if (vi[v] == 0) {
      vi[v] = 1;
      if (match[v] < 0 || dfs(match[v])) {
        match[u] = v;
        match[v] = u;
        return 1;
      }
    }
  }
  return 0;
}
int solve(int st) {
  int ans = 0, cnt = 0, edge = 0, i, j;
  memset(match, -1, sizeof(match));
  for (i = 1; i <= n * 2; i++) s[i].clear();
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      if (i != st && j != st && ma[i][j])
        s[i].push_back(j + n), s[j + n].push_back(i), edge++;
  if (ma[st][st] == 0) ans++;
  for (i = 1; i <= n; i++) {
    if (i == st) continue;
    if (ma[st][i] == 0) ans++;
    if (ma[i][st] == 0) ans++;
  }
  for (i = 1; i <= n * 2; i++) {
    if (i == st || i == st + n) continue;
    if (match[i] == -1) {
      memset(vi, 0, sizeof(vi));
      vi[i] = 1;
      if (dfs(i)) cnt++;
    }
  }
  return ans + n - 1 - cnt + edge - cnt;
}
int main() {
  int i, j, x, y, ans = 99999999;
  scanf("%d%d", &n, &m);
  for (i = 0; i < m; i++) {
    scanf("%d%d", &x, &y);
    ma[x][y] = 1;
  }
  for (i = 1; i <= n; i++) ans = min(ans, solve(i));
  printf("%d\n", ans);
}
