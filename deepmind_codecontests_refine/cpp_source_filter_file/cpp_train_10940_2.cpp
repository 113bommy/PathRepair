#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, x, y, ans, v[1000001], g[1000001];
vector<int> zh[1000001];
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    zh[x].push_back(y);
  }
  for (i = 1; i <= n; i++)
    if (!v[i]) {
      v[i] = i;
      for (j = 0; j < zh[i].size(); j++)
        if (!v[zh[i][j]]) v[zh[i][j]] = i;
      g[i] = 1;
    }
  for (i = 1; i <= n; i++)
    if (g[i])
      for (j = 0; j < zh[i].size(); j++) g[zh[i][j]] = 0;
  for (i = 1; i <= n; i++)
    if (g[i]) ans++;
  printf("%d\n", ans);
  for (i = 1; i <= n; i++)
    if (g[i]) printf("%d ", i);
}
