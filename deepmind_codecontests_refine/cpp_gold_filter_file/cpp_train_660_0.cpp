#include <bits/stdc++.h>
using namespace std;
int n, m, k, ans[500010], l, r;
vector<int> e[500010];
map<int, bool> g[500010];
int visit[500010];
bool dfs(int u, int cnt) {
  int i, v, j;
  for (i = 0; i < k; i++) {
    v = e[u][i];
    if (!visit[v]) {
      visit[v] = cnt + 1;
      ans[cnt] = v;
      if (dfs(v, cnt + 1))
        return 1;
      else
        return 0;
    } else if (cnt - visit[v] >= k) {
      l = v;
      r = cnt;
      return 1;
    }
  }
  return 0;
}
int main() {
  int i, u, v;
  while (scanf("%d%d%d", &n, &m, &k) != EOF) {
    memset(ans, 0, sizeof(ans));
    memset(visit, 0, sizeof(visit));
    for (i = 1; i <= n; i++) e[i].clear(), g[i].clear();
    while (m--) {
      scanf("%d%d", &u, &v);
      e[u].push_back(v), e[v].push_back(u);
      g[u][v] = g[v][u] = 1;
    }
    for (i = 1; i <= n; i++) {
      if (!visit[i]) {
        ans[0] = i;
        visit[i] = 1;
        if (dfs(i, 1)) break;
      }
    }
    for (i = 0; i < n; i++)
      if (ans[i] == l) {
        l = i;
        break;
      }
    printf("%d\n", r - l);
    printf("%d", ans[l]);
    for (i = l + 1; i < r; i++) printf(" %d", ans[i]);
    puts("");
  }
}
