#include <bits/stdc++.h>
using namespace std;
struct Node {
  int d, u;
  bool operator<(const Node& rhs) const { return d > rhs.d; }
};
vector<Node> c[610];
int d[210][610], g[610][610];
int mat[610], s[210];
vector<int> f[610];
bool used[610];
bool vis[610];
priority_queue<Node> q;
bool crosspath(int x) {
  for (int i = 0; i < f[x].size(); i++) {
    int j = f[x][i];
    if (!used[j]) {
      used[j] = 1;
      if (mat[j] == 0 || crosspath(mat[j])) {
        mat[j] = x;
        return 1;
      }
    }
  }
  return 0;
}
int main() {
  int v, e, n, kk, i, j, a, b, t;
  scanf("%d%d%d%d", &v, &e, &n, &kk);
  for (i = 1; i <= n; i++) scanf("%d", &s[i]);
  for (i = 1; i <= v; i++)
    for (j = 1; j <= v; j++) g[i][j] = 10001;
  for (i = 1; i <= e; i++) {
    scanf("%d%d%d", &a, &b, &t);
    c[a].push_back((Node){b, t});
    c[b].push_back((Node){a, t});
  }
  for (i = 1; i <= n; i++) {
    for (int j = 1; j <= v; ++j) d[i][j] = 1e9;
    d[i][s[i]] = 0;
    memset(vis, 0, sizeof(vis));
    while (!q.empty()) q.pop();
    q.push((Node){0, s[i]});
    while (!q.empty()) {
      Node x = q.top();
      q.pop();
      int u = x.u;
      if (vis[u]) continue;
      vis[u] = 1;
      for (int k = 0; k < c[u].size(); k++) {
        int v = c[u][k].u;
        int w = d[i][u] + c[u][k].d;
        if (d[i][v] > w) {
          d[i][v] = w;
          q.push((Node){w, v});
        }
      }
    }
  }
  int l = 0, r = 1731311, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    for (i = 1; i <= n; i++) f[i].clear();
    for (i = 1; i <= n; i++) {
      for (int j = 1; j <= v; j++)
        if (d[i][j] <= mid) f[i].push_back(j);
    }
    int match = 0;
    memset(mat, 0, sizeof(mat));
    for (i = 1; i <= n; i++) {
      memset(used, 0, sizeof(used));
      match += crosspath(i);
    }
    if (match >= kk) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  printf("%d\n", ans);
}
