#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e2;
pair<int, int> a[MAXN][MAXN];
int ans[MAXN][MAXN];
int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) ans[i][j] = 0, a[i][j] = {i, j};
  for (int t = 0; t < q; t++) {
    int type;
    scanf("%d", &type);
    if (type == 3) {
      int r, c, x;
      scanf("%d%d%d", &r, &c, &x);
      r--, c--;
      ans[a[r][c].first][a[r][c].second] = x;
    } else {
      int r;
      scanf("%d", &r);
      r--;
      if (type == 1) {
        auto e = a[r][0];
        for (int j = 0; j < m - 1; j++) a[r][j] = a[r][j + 1];
        a[r][m - 1] = e;
      } else if (type == 2) {
        auto e = a[0][r];
        for (int j = 0; j < n - 1; j++) a[j][r] = a[j + 1][r];
        a[n - 1][r] = e;
      } else
        assert(false);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) printf("%d ", ans[i][j]);
    printf("\n");
  }
  return 0;
}
