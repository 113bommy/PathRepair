#include <bits/stdc++.h>
using namespace std;
const int N = 111;
pair<int, int> a[N][N];
int res[N][N];
int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[i][j] = make_pair(i, j);
      res[i][j] = 0;
    }
  }
  for (int i = 0; i < q; i++) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int row;
      scanf("%d", &row);
      row--;
      pair<int, int> tmp = a[row][0];
      for (int j = 0; j + 1 < n; j++) a[row][j] = a[row][j + 1];
      a[row][n - 1] = tmp;
    }
    if (type == 2) {
      int col;
      scanf("%d", &col);
      col--;
      pair<int, int> tmp = a[0][col];
      for (int j = 0; j + 1 < m; j++) a[j][col] = a[j + 1][col];
      a[m - 1][col] = tmp;
    }
    if (type == 3) {
      int row, col, val;
      scanf("%d%d%d", &row, &col, &val);
      row--, col--;
      res[a[row][col].first][a[row][col].second] = val;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d", res[i][j]);
      putchar(j == m - 1 ? '\n' : ' ');
    }
  }
  return 0;
}
