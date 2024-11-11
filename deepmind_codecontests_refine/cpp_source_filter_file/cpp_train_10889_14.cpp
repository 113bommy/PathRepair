#include <bits/stdc++.h>
int main() {
  int n, m, i, j, s = 0, k = 0, minimal;
  scanf("%d%d", &n, &m);
  int desk[n][m], rowTurns[n], colTurns[m];
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) scanf("%d", &desk[i][j]), s += desk[i][j];
  if (m >= n) {
    for (i = 0; i < n; i++) {
      minimal = desk[i][0];
      for (j = 1; j < m; j++)
        if (desk[i][j] < minimal) minimal = desk[i][j];
      rowTurns[i] = minimal;
      for (j = 0; j < m; j++) desk[i][j] -= minimal;
      s -= minimal * m;
      k += minimal;
    }
    for (j = 0; j < m; j++) {
      minimal = desk[0][j];
      for (i = 1; i < n; i++)
        if (desk[i][j] < minimal) minimal = desk[i][j];
      colTurns[j] = minimal;
      for (i = 0; i < n; i++) desk[i][j] -= minimal;
      s -= minimal * n;
      k += minimal;
    }
  } else {
    for (j = 0; j < m; j++) {
      minimal = desk[0][j];
      for (i = 1; i < n; i++)
        if (desk[i][j] < minimal) minimal = desk[i][j];
      colTurns[j] = minimal;
      for (i = 0; i < n; i++) desk[i][j] -= minimal;
      s -= minimal * n;
      k += minimal;
    }
    for (i = 0; i < n; i++) {
      minimal = desk[i][0];
      for (j = 1; j < m; j++)
        if (desk[i][j] < minimal) minimal = desk[i][j];
      rowTurns[i] = minimal;
      for (j = 0; j < m; j++) desk[i][j] -= minimal;
      s -= minimal * m;
      k += minimal;
    }
  }
  if (s)
    printf("%d", -1);
  else {
    printf("%d\n", k);
    for (i = 0; i < n; i++)
      while (rowTurns[i]--) printf("row %d\n", i + 1);
    for (j = 0; j < m; j++)
      while (colTurns[j]--) printf("tow %d\n", j + 1);
  }
}
