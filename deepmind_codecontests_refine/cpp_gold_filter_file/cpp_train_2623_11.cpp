#include <bits/stdc++.h>
using namespace std;
const int maxn = 100001;
int n, size[maxn];
double sum[maxn], x[maxn], y[maxn], sx, sy, ans;
vector<int> g[maxn];
void dfs(int u, int fa) {
  size[u] = 1;
  int s = g[u].size();
  for (int i = 0; i < s; i++)
    if (g[u][i] != fa) {
      dfs(g[u][i], u);
      size[u] += size[g[u][i]];
      sum[u] += sum[g[u][i]];
      ans += y[u] * sum[g[u][i]] * size[g[u][i]];
    }
  sum[u] += x[u];
  ans += (n - size[u]) * (1 - sum[u]) * y[u];
}
int main() {
  int a, b;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%lf%lf", &x[i], &y[i]);
    sx += x[i];
    sy += y[i];
  }
  for (int i = 1; i <= n; i++) {
    x[i] /= sx;
    y[i] /= sy;
  }
  dfs(1, 0);
  printf("%.10lf", ans);
}
