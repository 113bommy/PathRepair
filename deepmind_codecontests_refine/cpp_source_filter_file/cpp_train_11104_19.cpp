#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
vector<int> s[N + 5];
int fa[N + 5], pa[N + 5][20], dis[N + 5], odd[N + 5], sum[N + 5];
int Find(int k) {
  if (fa[k] == k) return k;
  return fa[k] = Find(fa[k]);
}
void dfs1(int u, int add) {
  dis[u] = add;
  for (int i = 0; i < s[u].size(); i++) {
    int v = s[u][i];
    if (dis[v] == -1) {
      pa[v][0] = u;
      dfs1(v, add + 1);
      if (Find(u) == Find(v)) {
        odd[u] |= odd[v];
      }
    } else if (dis[v] + 1 < dis[u]) {
      if ((dis[u] - dis[v]) % 2 == 0) {
        odd[u] = 1;
      }
      int x = Find(u);
      while (dis[x] + 1 > dis[u]) {
        fa[x] = pa[x][0];
        x = Find(x);
      }
    }
  }
}
int cnt[N + 5];
void dfs2(int u) {
  cnt[u] += odd[u];
  for (int i = 0; i < s[u].size(); i++) {
    int v = s[u][i];
    if (dis[v] == dis[u] + 1) {
      if (Find(u) == Find(v)) odd[v] |= odd[u];
      cnt[v] = cnt[u];
      dfs2(v);
    }
  }
}
int lca(int a, int b) {
  if (dis[a] > dis[b]) swap(a, b);
  int d = dis[b] - dis[a];
  for (int i = 18; i >= 0; i--) {
    if (d & (1 << i)) {
      b = pa[b][i];
    }
  }
  for (int i = 18; i >= 0; i--) {
    if (pa[a][i] != pa[b][i]) {
      a = pa[a][i];
      b = pa[b][i];
    }
  }
  if (a != b) a = pa[a][0];
  return a;
}
int check(int x, int y) {
  int pt = lca(x, y);
  if (pt == 0) return 0;
  if ((dis[x] - dis[y]) % 2) return 1;
  if (cnt[x] + cnt[y] - 2 * cnt[pt] > 0) return 1;
  return 0;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    s[x].push_back(y);
    s[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
  }
  memset(dis, -1, sizeof(dis));
  for (int i = 0; i < n; i++) {
    if (dis[i] == -1) {
      dfs1(i, 0);
      dfs2(i);
    }
  }
  for (int i = 1; i <= 17; i++) {
    for (int j = 1; j <= n; j++) {
      pa[j][i] = pa[pa[j][i - 1]][i - 1];
    }
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (check(x, y))
      puts("Yes");
    else
      puts("No");
  }
}
