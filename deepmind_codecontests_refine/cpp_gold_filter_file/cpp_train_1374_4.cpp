#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int n, m, t;
vector<int> g[maxn], h[maxn];
int vis[maxn];
int cnt;
void dfs1(int u) {
  vis[u] = 1;
  cnt++;
  for (auto it : g[u]) {
    if (vis[it]) continue;
    dfs1(it);
  }
}
void dfs2(int u) {
  vis[u] = 1;
  cnt++;
  for (auto it : h[u]) {
    if (vis[it]) continue;
    dfs2(it);
  }
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) g[i].clear(), h[i].clear(), vis[i] = 0;
    cnt = 0;
    for (int i = 1; i <= m; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      g[u].push_back(v);
      h[v].push_back(u);
    }
    dfs1(1);
    if (cnt == n) {
      cnt = 0;
      for (int i = 1; i <= n; i++) vis[i] = 0;
      dfs2(1);
      if (cnt == n) {
        puts("No");
        continue;
      }
      cnt = n - cnt;
      for (int i = 1; i <= n; i++) vis[i] = vis[i] == 0 ? 1 : 0;
    }
    puts("Yes");
    printf("%d %d\n", cnt, n - cnt);
    int a1 = cnt, a2 = n - cnt;
    for (int i = 1; i <= n; i++) {
      if (vis[i]) {
        a1--;
        printf("%d%s", i, a1 == 0 ? "\n" : " ");
      }
    }
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) {
        a2--;
        printf("%d%s", i, a2 == 0 ? "\n" : " ");
      }
    }
  }
  return 0;
}
