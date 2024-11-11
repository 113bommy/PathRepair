#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
struct jz {
  int x, id;
  bool operator<(const jz &b) const { return x < b.x; }
} b[maxn];
int n, m, a[maxn][maxn], mi[maxn][maxn], mx[maxn][maxn], w[maxn][maxn];
bool flg;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) b[j].x = a[i][j], b[j].id = j;
    sort(b + 1, b + 1 + m);
    int k = 1, t, tot = 0;
    while (k <= m) {
      t = k;
      while (t <= m && b[t].x == b[k].x) w[i][b[t].id] = tot, t++;
      k = t;
      ++tot;
    }
    for (int j = 1; j <= m; j++)
      mi[i][j] = max(mi[i][j], w[i][j]),
      mx[i][j] = max(mx[i][j], tot - w[i][j] - 1);
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) b[j].x = a[j][i], b[j].id = j;
    sort(b + 1, b + 1 + n);
    int k = 1, t, tot = 0;
    while (k <= n) {
      t = k;
      while (t <= n && b[t].x == b[k].x) w[b[t].id][i] = tot, t++;
      k = t;
      ++tot;
    }
    for (int j = 1; j <= n; j++)
      mi[j][i] = max(mi[j][i], w[j][i]),
      mx[j][i] = max(mx[j][i], tot - w[j][i] - 1);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) printf("%d ", mi[i][j] + mx[i][j] + 1);
    printf("\n");
  }
  return 0;
}
