#include <bits/stdc++.h>
using namespace std;
struct edge {
  int v, w;
  edge() {}
  edge(int V, int W) { v = V, w = W; }
};
struct node {
  long long x, y, z;
  node() {}
  node(long long X, long long Y, long long Z) { x = X, y = Y, z = Z; }
} p[100005];
vector<edge> G[100005];
int n;
long long f1[100005], f2[100005], Size[100005];
bool cmp(node u, node v) { return u.x * v.y < v.x * v.y; }
void dfs(int u, int fa) {
  Size[u]++;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i].v;
    if (v == fa) continue;
    dfs(v, u);
    Size[u] += Size[v], f1[u] += f1[v];
  }
  int len = 0;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i].v, w = G[u][i].w;
    if (v == fa) continue;
    p[++len] = node(Size[v], f2[v] + (w << 1), w);
  }
  sort(p + 1, p + len + 1, cmp);
  for (int i = 1; i <= len; i++)
    f1[u] += (p[i].z + f2[u]) * p[i].x, f2[u] += p[i].y;
}
int main() {
  scanf("%d", &n);
  for (int i = 1, u, v, w; i < n; i++) {
    scanf("%d %d %d", &u, &v, &w);
    G[u].push_back(edge(v, w));
    G[v].push_back(edge(u, w));
  }
  dfs(1, 0);
  printf("%.8f", f1[1] * 1.0 / (n - 1));
  return 0;
}
