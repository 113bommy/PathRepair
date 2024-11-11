#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 7;
int pa[maxn];
int cnt[maxn], cost[maxn];
struct Edge {
  int u, v, w;
  bool operator<(const Edge& b) const { return w > b.w; }
} edge[maxn];
void init(int n) {
  for (int i = 0; i <= n; ++i) {
    pa[i] = i;
    cnt[i] = 1;
  }
}
int findSet(int x) { return pa[x] == x ? x : (pa[x] = findSet(pa[x])); }
void gao(int n, int m) {
  sort(edge, edge + m);
  double res = 0.0;
  for (int i = 0; i < m; ++i) {
    int px = findSet(edge[i].u);
    int py = findSet(edge[i].v);
    if (px != py) {
      res += (double)edge[i].w * cnt[px] * cnt[py];
      pa[px] = py;
      cnt[py] += cnt[px];
    }
  }
  printf("%.4f\n", res * 2.0 / n / (n - 1));
}
int main() {
  int n, m, u, v;
  scanf("%d%d", &n, &m);
  init(n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", cost + i);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &u, &v);
    edge[i] = (Edge){u, v, min(cost[u], cost[v])};
  }
  gao(n, m);
  return 0;
}
