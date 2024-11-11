#include <bits/stdc++.h>
using namespace std;
const int MAXM = 2e5 + 5, MAXN = 1e3 + 5;
struct Node {
  int l, r, s, t, id;
} q[MAXM];
int n, m, qq, path[MAXM][2], f[MAXN][MAXN], ans[MAXM];
bool cmp(Node a, Node b) { return a.l < b.l; }
int main() {
  scanf("%d%d%d", &n, &m, &qq);
  for (int i = 1; i <= m; i++) scanf("%d%d", &path[i][0], &path[i][1]);
  for (int i = 1; i <= qq; i++)
    scanf("%d%d%d%d", &q[i].l, &q[i].r, &q[i].s, &q[i].t), q[i].id = i;
  sort(q + 1, q + qq + 1, cmp);
  memset(f, 60, sizeof f);
  for (int p = qq; m; m--) {
    int u = path[m][0], v = path[m][1];
    f[u][v] = f[v][u] = m;
    for (int i = 1; i <= n; i++) f[u][i] = f[v][i] = min(f[u][i], f[v][i]);
    for (; p && q[p].l == m; p--) ans[q[p].id] = (f[q[p].s][q[p].t] <= q[p].r);
  }
  for (int i = 1; i <= qq; i++) printf("%s\n", ans[i] ? "YES" : "NO");
}
