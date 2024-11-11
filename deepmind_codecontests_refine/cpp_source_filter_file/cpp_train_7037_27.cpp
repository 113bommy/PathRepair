#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
const double eps = 1e-12;
struct Edge {
  int u, v;
  Edge(int pu = 0, int pv = 0) {
    u = pu;
    v = pv;
  }
  int nb(int a) { return u + v - a; }
};
Edge e[maxn];
double t[maxn];
bool vis[maxn];
vector<int> v[maxn];
int n;
void dfs(int u, int pe) {
  int sz = v[u].size();
  double space = 2 * 1. / sz;
  double base = t[pe];
  for (int i = 0; i < sz; i++) {
    int &ei = v[u][i];
    if (vis[ei]) continue;
    vis[ei] = 1;
    printf("%d %d ", 1, ei);
    t[ei] = base + space;
    while (t[ei] >= 2 - eps) t[ei] -= 2;
    if (t[ei] <= 1 + eps)
      printf("%d %d %.10lf\n", u, e[ei].nb(u), t[ei]);
    else
      printf("%d %d %.10lf\n", e[ei].nb(u), u, t[ei] - 1);
    dfs(e[ei].nb(u), ei);
    base += space;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &e[i].u, &e[i].v);
    v[e[i].u].push_back(i);
    v[e[i].v].push_back(i);
  }
  memset(t, 0, sizeof t);
  memset(vis, 0, sizeof vis);
  printf("%d\n", n - 1);
  dfs(1, 0);
}
