#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
vector<int> G[N];
bool vis[N], mark[N];
void dfs(int u) {
  vis[u] = 1;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (vis[v]) continue;
    dfs(v);
  }
}
int main() {
  int n, m, loop = 0;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    if (u == v) {
      loop++;
      mark[u] = 1;
      continue;
    }
    G[v].push_back(u);
  }
  if (m < 2) {
    printf("0\n");
    return 0;
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      if (G[i].size() == 0) continue;
      dfs(i);
      cnt++;
    }
  if (cnt > 1) {
    puts("0");
    return 0;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int tmp = G[i].size();
    if (mark[i]) tmp--;
    ans += 1ll * tmp * (tmp - 1) / 2;
  }
  ans += 1ll * loop * (m - loop);
  ans += 1ll * loop * (loop - 1) / 2;
  printf("%lld\n", ans);
  return 0;
}
