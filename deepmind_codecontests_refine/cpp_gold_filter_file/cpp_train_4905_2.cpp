#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
int n, siz[maxn];
long double f[maxn][maxn], tmp[maxn];
vector<int> g[maxn];
void dfs(int x, int ff) {
  siz[x] = 1, f[x][0] = 1.0;
  for (auto y : g[x])
    if (y != ff) {
      dfs(y, x);
      for (int i = 0; i < siz[x] + siz[y]; i++) tmp[i] = 0;
      for (int i = 0; i < siz[x]; i++)
        for (int j = 0; j < siz[y]; j++)
          tmp[i + j] +=
              f[x][i] * f[y][j] * (0.5 / (long double)(siz[y] - j) - 1),
              tmp[i + j + 1] += f[x][i] * f[y][j];
      siz[x] += siz[y];
      for (int i = 0; i < siz[x]; i++) f[x][i] = tmp[i];
    }
}
int main() {
  scanf("%d", &n);
  int x, y;
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    memset(f, 0, sizeof(f));
    dfs(i, 0);
    long double ans = 1;
    for (auto y : g[i]) {
      long double val = 0;
      for (int i = 0; i < siz[y]; i++)
        val += f[y][i] * 0.5 / (long double)(siz[y] - i);
      ans *= val;
    }
    printf("%.10Lf\n", ans);
  }
  return 0;
}
