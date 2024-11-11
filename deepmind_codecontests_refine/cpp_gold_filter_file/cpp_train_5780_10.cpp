#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int id, u, v, w, use;
  bool friend operator<(Edge a, Edge b) {
    if (a.use == b.use) return a.w < b.w;
    return a.use > b.use;
  }
} edge[100005];
int ans[100005][2];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &edge[i].w, &edge[i].use);
    edge[i].id = i;
  }
  sort(edge + 1, edge + m + 1);
  for (int i = 1; i < n; i++) {
    edge[i].u = i;
    edge[i].v = i + 1;
  }
  int u = 0, v = 2;
  for (int i = n; i <= m; i++) {
    if (u + 2 == v) {
      v++;
      u = 1;
    } else
      u++;
    if (edge[i].w < edge[v - 1].w) {
      puts("-1");
      return 0;
    }
    edge[i].u = u;
    edge[i].v = v;
  }
  for (int i = 1; i <= m; i++)
    ans[edge[i].id][0] = edge[i].u, ans[edge[i].id][1] = edge[i].v;
  for (int i = 1; i <= m; i++) printf("%d %d\n", ans[i][0], ans[i][1]);
}
