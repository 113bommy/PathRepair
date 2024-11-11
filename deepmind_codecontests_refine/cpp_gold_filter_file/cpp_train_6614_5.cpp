#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int inf = 0x3f3f3f3f;
int n, m, q;
int val[maxn][maxn];
pair<int, int> a[maxn][maxn];
void shift_row(int x) {
  pair<int, int> f = a[x][1];
  for (int i = 1; i < m; i++) a[x][i] = a[x][i + 1];
  a[x][m] = f;
}
void shift_col(int x) {
  pair<int, int> f = a[1][x];
  for (int i = 1; i < n; i++) a[i][x] = a[i + 1][x];
  a[n][x] = f;
}
int main(void) {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) a[i][j] = pair<int, int>(i, j);
  memset(val, inf, sizeof val);
  for (int i = 0; i < q; i++) {
    int t;
    scanf("%d", &t);
    if (t == 3) {
      int r, c, x;
      scanf("%d%d%d", &r, &c, &x);
      val[a[r][c].first][a[r][c].second] = x;
      continue;
    }
    int x;
    scanf("%d", &x);
    if (t == 1)
      shift_row(x);
    else
      shift_col(x);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      if (val[i][j] == inf)
        printf("0 ");
      else
        printf("%d ", val[i][j]);
    printf("\n");
  }
  return 0;
}
