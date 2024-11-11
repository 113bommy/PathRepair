#include <bits/stdc++.h>
using namespace std;
vector<int> g[300005];
int n;
int f[300005][32];
int w[300005];
int a[300005];
int m;
long long r;
void dfs(int x, int p) {
  w[x] = 1;
  for (int y : g[x])
    if (y != p) {
      dfs(y, x);
      w[x] = max(w[x], 1 + w[y]);
    }
  f[x][1] = n;
  for (int d = 2, ThxDem = 21; d < ThxDem; ++d) {
    m = 0;
    for (int y : g[x])
      if (y != p) a[m++] = f[y][d - 1];
    sort(a, a + m);
    reverse(a, a + m);
    f[x][d] = 0;
    while (f[x][d] < m && a[f[x][d]] > f[x][d]) f[x][d]++;
    f[x][d] = max(f[x][d], 1);
  }
  f[x][21] = 1;
}
void dfs2(int x, int p) {
  for (int y : g[x])
    if (y != p) {
      dfs2(y, x);
      for (int d = 1, ThxDem = 21; d < ThxDem; ++d)
        f[x][d] = max(f[x][d], f[y][d]);
    }
}
int main() {
  scanf("%d", &n);
  for (int _ = 1, ThxDem = n; _ < ThxDem; ++_) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(0, -1);
  dfs2(0, -1);
  for (int i = 0, ThxDem = n; i < ThxDem; ++i) {
    r += w[i];
    for (int d = 1, ThxDem = 21; d < ThxDem; ++d)
      r += d * (f[i][d] - f[i][d + 1]);
  }
  printf("%lld\n", r);
  return 0;
}
