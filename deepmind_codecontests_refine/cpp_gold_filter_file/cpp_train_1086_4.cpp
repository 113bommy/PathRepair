#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int MAXM = 100005;
struct Edge {
  int u, v, w;
  Edge() {}
  Edge(int u, int v, int w) : u(u), v(v), w(w) {}
  bool operator<(const Edge& e) const { return w > e.w; }
};
Edge edge[MAXM];
int animal[MAXN];
int pa[MAXN], sz[MAXN];
void MakeSet(int n) {
  for (int i = 0; i <= n; ++i) {
    pa[i] = i;
    sz[i] = 1;
  }
}
int FindSet(int x) {
  if (x != pa[x]) pa[x] = FindSet(pa[x]);
  return pa[x];
}
void MST(int n, int m) {
  sort(edge, edge + m);
  double ret = 0;
  for (int i = 0; i < m; ++i) {
    int px = FindSet(edge[i].u);
    int py = FindSet(edge[i].v);
    if (px != py) {
      ret += (double)edge[i].w * sz[px] * sz[py];
      pa[py] = px;
      sz[px] += sz[py];
    }
  }
  double all = (double)n * (n - 1) / 2;
  printf("%.6f\n", ret / all);
}
int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) != EOF) {
    MakeSet(n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &animal[i]);
    }
    for (int i = 0; i < m; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      edge[i] = Edge(u, v, min(animal[u], animal[v]));
    }
    MST(n, m);
  }
  return 0;
}
