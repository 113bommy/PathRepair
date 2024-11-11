#include <bits/stdc++.h>
typedef struct {
  long x;
  long y;
} Interval;
void dfs(int mat[][101], int *d, int n, int u) {
  int i;
  d[u] = 1;
  for (i = 1; i <= n; i++) {
    if (mat[u][i] == 1 && d[i] == -1) dfs(mat, d, n, i);
  }
}
int main() {
  int d[101];
  Interval niz[101];
  int mat[101][101];
  int n, i, ii, p, q, j, k;
  long x, y;
  j = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &k);
    if (k == 1) {
      j++;
      mat[j][j] = 1;
      scanf("%ld%ld", &x, &y);
      niz[j].x = x;
      niz[j].y = y;
      for (ii = 1; ii < j; ii++) {
        if ((niz[j].x < niz[ii].y && niz[j].x > niz[ii].x) ||
            (niz[j].y < niz[ii].y && niz[j].y > niz[ii].x)) {
          mat[j][ii] = 1;
        } else {
          mat[j][ii] = 0;
        }
        if ((niz[j].x < niz[ii].x && niz[j].y > niz[ii].x) ||
            (niz[j].x < niz[ii].y && niz[j].y > niz[ii].y)) {
          mat[ii][j] = 1;
        } else {
          mat[ii][j] = 0;
        }
      }
    } else {
      scanf("%d%d", &p, &q);
      for (ii = 0; ii <= j; ii++) d[ii] = -1;
      dfs(mat, d, j, p);
      if (d[q] == 1)
        printf("YES\n");
      else
        printf("NO\n");
    }
  }
  return 0;
}
