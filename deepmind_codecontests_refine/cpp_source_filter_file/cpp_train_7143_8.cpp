#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const long long MOD = 1e6 + 3;
const auto INF = 0x3f3f3f3f;
int dcmp(double x) {
  if (fabs(x) < eps) return 0;
  return x < 0 ? -1 : 1;
}
const int MAXN = 3e3 + 5;
const int MAXM = 4e5 + 5;
struct Node {
  int s, k, id;
};
bool vis[MAXN];
int p[MAXN][20], ans[MAXM];
vector<int> G[MAXN], H[MAXN];
vector<Node> Q[MAXN];
void dfs(int u) {
  vis[u] = 1;
  for (int v : H[u])
    if (!vis[v]) {
      dfs(v);
    }
}
int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    H[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    sort(G[i].begin(), G[i].end());
  }
  for (int i = 0; i < q; i++) {
    int s, t, k;
    scanf("%d%d%d", &s, &t, &k);
    Q[t].push_back({s, k - 1, i});
  }
  for (int t = 1; t <= n; t++) {
    memset(vis, 0, (n + 1) * sizeof(vis[0]));
    dfs(t);
    p[n + 1][0] = p[t][0] = n + 1;
    for (int i = 1; i <= n; i++) {
      if (i == t) continue;
      p[i][0] = 0;
      if (vis[i]) {
        for (int v : G[i])
          if (vis[v]) {
            p[i][0] = v;
            break;
          }
      }
    }
    for (int j = 1; j <= 12; j++) {
      for (int i = 0; i <= n + 1; i++) {
        p[i][j] = p[p[i][j - 1]][j - 1];
      }
    }
    for (Node x : Q[t]) {
      int s = x.s, k = x.k, id = x.id;
      ans[id] = -1;
      if (p[s][10] == n + 1 || p[s][10] == t) {
        for (int i = 0; i <= 12; i++) {
          if ((k >> i) & 1) s = p[s][i];
        }
        if (s != n + 1) ans[id] = s;
      }
    }
  }
  for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
  return 0;
}
