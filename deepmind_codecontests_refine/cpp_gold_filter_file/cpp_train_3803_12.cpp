#include <bits/stdc++.h>
using namespace std;
const int N = 200;
int n, m, k, a[N][N];
struct query {
  int type, x, y, z;
  void in() {
    scanf("%d%d", &type, &x);
    if (type == 3) scanf("%d%d", &y, &z);
  }
} q[100500];
int ans[N][N];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; ++i) {
    q[i].in();
  }
  for (int it = k; it > 0; --it) {
    if (q[it].type == 3) {
      ans[q[it].x][q[it].y] = q[it].z;
    } else if (q[it].type == 2) {
      int row = q[it].x;
      int tmp = ans[n][row];
      for (int i = n; i >= 2; --i) ans[i][row] = ans[i - 1][row];
      ans[1][row] = tmp;
    } else {
      int col = q[it].x;
      int tmp = ans[col][m];
      for (int i = m; i >= 2; --i) ans[col][i] = ans[col][i - 1];
      ans[col][1] = tmp;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) printf("%d ", ans[i][j]);
    puts("");
  }
  return 0;
}
