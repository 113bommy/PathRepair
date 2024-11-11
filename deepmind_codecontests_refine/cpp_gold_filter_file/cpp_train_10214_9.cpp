#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > adj;
bool vis[110];
int fl = 0;
int dfsCnt = 0;
void dfs(int u, int p) {
  dfsCnt++;
  vis[u] = 1;
  for (int i = 0; i < (int)adj[u].size(); i++) {
    int v = adj[u][i];
    if (!vis[v]) {
      dfs(v, u);
    } else if (v != p) {
      fl++;
    }
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  adj.assign(n + 1, vector<int>(0));
  int x, y;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &x, &y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1, 0);
  if (fl == 2 && dfsCnt == n)
    printf("FHTAGN!");
  else
    printf("NO");
}
