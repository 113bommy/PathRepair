#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > edge[107];
int dis[107][107][27];
char mmap[107][107];
int dfs(int u, int v, int p) {
  if (p != -1 && dis[u][v][p] != -1) return dis[u][v][p];
  int ans = 0;
  for (int i = 0; i < edge[u].size(); i++)
    if (p <= edge[u][i].second)
      ans = ans | !dfs(v, edge[u][i].first, edge[u][i].second);
  return dis[u][v][p] = ans;
}
int main() {
  int n, m, u, v;
  char w[4];
  memset(dis, -1, sizeof(dis));
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%s", &u, &v, w);
    edge[u].push_back(make_pair(v, w[0] - 'a'));
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (dfs(i, j, -1))
        mmap[i - 1][j - 1] = 'A';
      else
        mmap[i - 1][j - 1] = 'B';
      mmap[i - 1][n] = '\0';
    }
  for (int i = 0; i < n; i++) puts(mmap[i]);
  return 0;
}
