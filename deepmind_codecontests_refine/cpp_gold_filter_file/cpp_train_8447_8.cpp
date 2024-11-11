#include <bits/stdc++.h>
int n, m, a[200][200];
bool inv_row[200], inv_col[200];
void invertCol(int c) {
  inv_col[c] = !inv_col[c];
  for (int i = 0; i < n; i++) a[i][c] = 1 - a[i][c];
}
void sortFirstRow(int c) {
  for (int j = 0; j < m; j++)
    if (a[0][j] == (j < c)) invertCol(j);
}
int countFlip(int r) {
  int cnt = 0;
  for (int j = 1; j < m; j++)
    if (a[r][j - 1] != a[r][j]) cnt += 1;
  return cnt;
}
void printAnswer() {
  printf("YES\n");
  for (int i = 0; i < n; i++) printf("%d", inv_row[i]);
  printf("\n");
  for (int j = 0; j < m; j++) printf("%d", inv_col[j]);
  printf("\n");
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
  for (int c = 0; c < m; c++) {
    sortFirstRow(c);
    int r;
    for (r = 1; r < n; r++) {
      if (countFlip(r))
        break;
      else
        inv_row[r] = a[r][0] == 0;
    }
    if (r == n) {
      printAnswer();
      return 0;
    }
  }
  sortFirstRow(m);
  int cnt = 0;
  for (int r = 1; r < n; r++) {
    inv_row[r] = a[r][0] != cnt;
    cnt += countFlip(r);
    if (cnt > 1) break;
  }
  if (cnt > 1)
    printf("NO\n");
  else
    printAnswer();
  return 0;
}
