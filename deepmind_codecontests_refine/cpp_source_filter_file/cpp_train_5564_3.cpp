#include <bits/stdc++.h>
using namespace std;
char s[1005][11][11];
int d[1005][1005], vis[1005], fa[1005], t[1005][2];
int n, m, c;
vector<int> V[1005];
struct Edge {
  int a, b, w;
} p[500005];
int cmp(Edge x, Edge y) { return x.w < y.w; }
int cal(int a, int b) {
  int ans = 0, i, j;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      if (s[a][i][j] != s[b][i][j]) ans++;
  return ans;
}
int find(int x) {
  if (x != fa[x]) return fa[x] = find(fa[x]);
  return x;
}
void dfs(int u, int pu) {
  int x, i;
  vis[u] = 1;
  t[c][0] = u, t[c++][1] = pu;
  for (i = 0; i < V[u].size(); i++) {
    x = V[u][i];
    if (vis[x]) continue;
    dfs(x, u);
  }
}
int main() {
  int k, w, i, j;
  scanf("%d%d%d%d", &n, &m, &k, &w);
  for (i = 1; i <= k; i++) {
    for (j = 0; j < n; j++) scanf("%s", s[i][j]);
  }
  c = 0;
  for (i = 1; i <= k; i++)
    for (j = i + 1; j <= k; j++) {
      int dis = cal(i, j);
      if (dis * w <= n * m) {
        p[c].a = i;
        p[c].b = j;
        p[c++].w = dis * w;
      }
    }
  sort(p, p + c, cmp);
  for (i = 1; i <= k; i++) fa[i] = i;
  int ans = 0;
  for (i = 0; i < c; i++) {
    int fx = find(p[i].a);
    int fy = find(p[i].b);
    if (fx == fy) continue;
    fa[fx] = fy;
    ans += p[i].w;
    V[p[i].a].push_back(p[i].b);
    V[p[i].b].push_back(p[i].a);
  }
  c = 0;
  for (i = 1; i <= k; i++)
    if (!vis[k]) {
      ans += n * m;
      dfs(k, 0);
    }
  printf("%d\n", ans);
  for (i = 0; i < c; i++) printf("%d %d\n", t[i][0], t[i][1]);
}
