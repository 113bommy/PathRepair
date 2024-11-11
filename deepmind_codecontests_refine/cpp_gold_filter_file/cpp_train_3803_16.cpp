#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1000 * 1000 * 1000 + 1;
int n, m, q;
int a[101][101];
int indx[101][101];
int indy[101][101];
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      a[i][j] = INF;
      indx[i][j] = i;
      indy[i][j] = j;
    }
  }
  for (int i = 0; i < q; i++) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int r;
      scanf("%d", &r);
      int tmpx = indx[r][1];
      int tmpy = indy[r][1];
      for (int c = 1; c < m; c++) {
        indx[r][c] = indx[r][c + 1];
        indy[r][c] = indy[r][c + 1];
      }
      indx[r][m] = tmpx;
      indy[r][m] = tmpy;
    }
    if (type == 2) {
      int c;
      scanf("%d", &c);
      int tmpx = indx[1][c];
      int tmpy = indy[1][c];
      for (int r = 1; r < n; r++) {
        indx[r][c] = indx[r + 1][c];
        indy[r][c] = indy[r + 1][c];
      }
      indx[n][c] = tmpx;
      indy[n][c] = tmpy;
    }
    if (type == 3) {
      int r, c, x;
      scanf("%d%d%d", &r, &c, &x);
      a[indx[r][c]][indy[r][c]] = x;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == INF) {
        printf("%d ", 1);
      } else {
        printf("%d ", a[i][j]);
      }
    }
    printf("\n");
  }
  return 0;
}
