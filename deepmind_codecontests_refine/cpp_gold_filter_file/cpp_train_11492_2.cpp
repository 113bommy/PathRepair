#include <bits/stdc++.h>
using namespace std;
int g[110][110], n, m, d[110], num[110];
vector<int> lang[110];
bool vis[110];
void dfs(int u) {
  vis[u] = true;
  for (int i = 1; i <= n; i++)
    if (g[u][i] > 0 && !vis[i]) dfs(i);
}
int main() {
  scanf("%d %d", &n, &m);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    int nu;
    scanf("%d", &nu);
    num[i] = nu;
    if (nu == 0) cnt++;
    while (nu--) {
      int lan;
      scanf("%d", &lan);
      lang[lan].push_back(i);
    }
  }
  for (int i = 1; i <= m; i++)
    for (int j = 0; j < lang[i].size(); j++)
      for (int k = 0; k < lang[i].size(); k++) g[lang[i][j]][lang[i][k]] = 1;
  int cnt2 = 0;
  for (int i = 1; i <= n; i++)
    if (!vis[i] && num[i] > 0) dfs(i), cnt2++;
  cnt2 = max(0, cnt2 - 1);
  printf("%d\n", cnt + cnt2);
}
