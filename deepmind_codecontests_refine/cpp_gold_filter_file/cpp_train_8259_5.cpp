#include <bits/stdc++.h>
using namespace std;
const int N = 200008;
struct edge {
  int e, c;
  edge() {}
  edge(int x, int y) : e(x), c(y) {}
};
int n, m;
vector<edge> g[N];
int dis[N], path[N], p[N];
void dfs(int x, int fa) {
  int i;
  for (i = 0; i < g[x].size(); i++) {
    int e = g[x][i].e;
    int c = g[x][i].c;
    if (e == fa) continue;
    dis[e] = dis[x] + 1;
    path[e] = path[x] + c;
    p[x] += c;
    dfs(e, x);
  }
}
int main() {
  int i, j, k, x, y, sum = 0, ans;
  scanf("%d", &n);
  for (i = 0; i < n - 1; i++) {
    scanf("%d%d", &x, &y);
    x--;
    y--;
    g[x].push_back(edge(y, 0));
    g[y].push_back(edge(x, 1));
  }
  dis[0] = p[0] = path[0] = 0;
  dfs(0, -1);
  for (i = 0; i < n; i++) sum += p[i];
  ans = sum;
  for (i = 1; i < n; i++)
    ans = ((ans) < (sum - path[i] + dis[i] - path[i])
               ? (ans)
               : (sum - path[i] + dis[i] - path[i]));
  printf("%d\n", ans);
  for (i = 0; i < n; i++)
    if (ans == sum - path[i] + dis[i] - path[i]) printf("%d ", i + 1);
  return 0;
}
