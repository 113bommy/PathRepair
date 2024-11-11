#include <bits/stdc++.h>
using namespace std;
const int Mod = 1000000007;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ansx[40], ansy[40];
int n, deg[40];
bool vis[40];
vector<int> g[40];
void Dfs(int u, int nx, int ny, int len, int pre) {
  ansx[u] = nx, ansy[u] = ny;
  vis[u] = true;
  int d = 0;
  for (int i = 0; i < g[u].size(); i++) {
    if (pre != -1 && d == (pre ^ 1)) d++;
    int v = g[u][i];
    if (vis[v]) continue;
    Dfs(v, nx + dx[d] * len, ny + dy[d] * len, len >> 1, d);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
    deg[x]++, deg[y]++;
  }
  bool flag = true;
  for (int i = 1; i <= n; i++)
    if (deg[i] > 4) flag = false;
  if (!flag) {
    printf("NO\n");
    return 0;
  }
  printf("YES\n");
  Dfs(1, 0, 0, 1 << 29, -1);
  for (int i = 1; i <= n; i++) printf("%d %d\n", ansx[i], ansy[i]);
  return 0;
}
