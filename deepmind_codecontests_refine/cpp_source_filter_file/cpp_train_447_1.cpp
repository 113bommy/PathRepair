#include <bits/stdc++.h>
int a[31][31];
int main() {
  int n;
  int row, column;
  int cnt = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      row = 0;
      column = 0;
      for (int k = 0; k < n; k++) {
        row += a[i][k];
        column += a[k][j];
      }
      if (row > column) cnt++;
    }
  printf("%d", cnt);
  return 0;
}
