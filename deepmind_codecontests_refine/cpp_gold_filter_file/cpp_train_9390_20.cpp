#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int id, u, v;
  double w, w2;
  bool operator<(const Edge &e) const { return w2 < e.w2; }
};
int cnt;
int n, m, k;
Edge e[100010];
Edge e1[100010];
int f[5010];
int ans[100010];
double mid;
int top;
int find(int x) {
  if (x != f[x]) f[x] = find(f[x]);
  return f[x];
}
int kruskal() {
  top = cnt = 0;
  for (int i = 0; i < m; i++) {
    e[i].w2 = e[i].w + (e[i].u == 1 ? mid : 0);
  }
  for (int i = 1; i <= n; i++) f[i] = i;
  sort(e, e + m);
  for (int i = 0; i < m; i++) {
    int u = find(e[i].u);
    int v = find(e[i].v);
    if (u != v) {
      ans[top++] = e[i].id;
      cnt += e[i].u == 1;
      f[u] = v;
    }
  }
  return cnt;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%lf", &e[i].u, &e[i].v, &e[i].w);
    if (e[i].u > e[i].v) swap(e[i].u, e[i].v);
    e[i].id = i + 1;
    e[i].w += i * 1e-7;
  }
  double l = -1e4, r = 1e4;
  while (l < r) {
    mid = (l + r) / 2;
    cnt = kruskal();
    if (cnt == k) break;
    if (cnt < k)
      r = mid;
    else
      l = mid;
  }
  if (cnt == k) {
    printf("%d\n", n - 1);
    for (int i = 0; i < top; i++) printf("%d ", ans[i]);
  } else {
    printf("-1\n");
  }
  return 0;
}
