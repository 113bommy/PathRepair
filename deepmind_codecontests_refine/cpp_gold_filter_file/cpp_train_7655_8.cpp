#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int n;
int d[200005][20];
int dep[200005];
int lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = 18; i >= 0; i--)
    if (dep[d[x][i]] >= dep[y]) x = d[x][i];
  if (x == y) return x;
  for (int i = 18; i >= 0; i--)
    if (d[x][i] != d[y][i]) x = d[x][i], y = d[y][i];
  return d[x][0];
}
int main() {
  int x, ans = 0;
  scanf("%d", &n);
  int idx = 1, Max = 1;
  dep[1] = 1;
  for (int i = 2; i <= n; i++) {
    scanf("%d", &x);
    d[i][0] = x;
    for (int j = 1; j <= 18; j++) d[i][j] = d[d[i][j - 1]][j - 1];
    dep[i] = dep[x] + 1;
    if (dep[i] > Max)
      Max = dep[i], idx = i, ++ans;
    else
      ans = max(ans, dep[idx] + dep[i] - 2 * dep[lca(idx, i)]);
    printf("%d ", ans);
  }
  return 0;
}
