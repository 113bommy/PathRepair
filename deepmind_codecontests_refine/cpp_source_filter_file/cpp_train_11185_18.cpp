#include <bits/stdc++.h>
using namespace std;
const int MAX = 1100;
bool ma[MAX][MAX];
int lft[MAX][MAX], rht[MAX][MAX], up[MAX][MAX], down[MAX][MAX];
int len[MAX];
int rows, cols, q;
void upd_row(int x) {
  for (int j = 1; j <= cols; j++) {
    if (ma[x][j])
      lft[x][j] = lft[x][j - 1] + 1;
    else
      lft[x][j] = 0;
  }
  for (int j = cols; j >= 1; j--) {
    if (ma[x][j])
      rht[x][j] = rht[x][j + 1] + 1;
    else
      rht[x][j] = 0;
  }
}
void upd_col(int y) {
  for (int i = 1; i <= rows; i++) {
    if (ma[i][y])
      up[i][y] = 1 + up[i - 1][y];
    else
      up[i][y] = 0;
  }
  for (int i = rows; i >= 1; i--) {
    if (ma[i][y])
      down[i][y] = 1 + down[i + 1][y];
    else
      down[i][y] = 0;
  }
}
int go(int tmp, int n) {
  int leftmost = tmp;
  int rightmost = tmp;
  int ret = 0;
  for (int final = len[tmp]; final >= 1; final--) {
    while (leftmost >= 1 && final <= len[leftmost]) --leftmost;
    while (rightmost <= n && final <= len[rightmost]) ++rightmost;
    ret = max(ret, final * (rightmost - leftmost - 1));
  }
  return ret;
}
int main() {
  int i, j;
  int op, x, y;
  int ans;
  while (scanf("%d %d %d", &rows, &cols, &q) != EOF) {
    for (i = 1; i <= rows; i++)
      for (j = 1; j <= cols; j++) scanf("%d", &ma[i][j]);
    for (i = 1; i <= rows; i++) upd_row(i);
    for (j = 1; j <= cols; j++) upd_col(j);
    while (q--) {
      scanf("%d %d %d", &op, &x, &y);
      if (op == 1) {
        ma[x][y] = !ma[x][y];
        upd_row(x);
        upd_col(y);
      } else {
        ans = 0;
        for (i = 1; i <= rows; i++) len[i] = lft[i][y];
        ans = max(ans, go(x, rows));
        for (i = 1; i <= rows; i++) len[i] = rht[i][y];
        ans = max(ans, go(x, rows));
        for (j = 1; j <= cols; j++) len[i] = down[x][j];
        ans = max(ans, go(y, cols));
        for (j = 1; j <= cols; j++) len[i] = up[x][j];
        ans = max(ans, go(y, cols));
        printf("%d\n", ans);
      }
    }
  }
  return 0;
}
