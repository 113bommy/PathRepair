#include <bits/stdc++.h>
using namespace std;
int n, m, k, it, it1, line;
bool g[307][307], mark[307], vis[307];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  if ((k == n) || (m > (n - 1) * (n - 2) + n - k)) {
    printf("-1");
    return 0;
  }
  for (int i = 1; i <= k; ++i) {
    int in;
    scanf("%d", &in);
    mark[in] = 1;
    it = in;
  }
  vis[it] = 1;
  for (int i = 1; i <= n; ++i) g[i][i] = 1;
  for (int i = 1; i <= n; ++i) {
    if (i == it || mark[i]) continue;
    printf("%d %d\n", i, it);
    ++line;
    vis[i] = 1;
    g[i][it] = g[it][i] = 1;
    it1 = i;
    if (line == m) return 0;
  }
  for (int i = 1; i <= n; ++i) {
    if (line == m) return 0;
    if (vis[i]) continue;
    printf("%d %d\n", i, it1);
    ++line;
    g[i][it1] = g[it1][i] = 1;
    vis[i] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    if (line == m) return 0;
    if (i == it) continue;
    for (int j = 1; j <= n; ++j) {
      if (j == it || g[i][j]) continue;
      if (line == m) return 0;
      printf("%d %d\n", i, j);
      g[i][j] = g[j][i] = 1;
      ++line;
    }
  }
  return 0;
}
