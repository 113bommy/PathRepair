#include <bits/stdc++.h>
int ty[10005], a[10005], b[10005], c[10005];
int n, m, q, mat[105][105];
int main() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d", &ty[i]);
    if (ty[i] == 3) {
      scanf("%d %d %d", &a[i], &b[i], &c[i]);
    } else {
      scanf("%d", &a[i]);
    }
  }
  for (int i = q; i >= 1; i--) {
    if (ty[i] == 3) {
      mat[a[i]][b[i]] = c[i];
    } else if (ty[i] == 1) {
      int tmp = mat[a[i]][m];
      for (int j = n; j >= 2; j--) mat[a[i]][j] = mat[a[i]][j - 1];
      mat[a[i]][1] = tmp;
    } else {
      int tmp = mat[n][a[i]];
      for (int j = n; j >= 2; j--) mat[j][a[i]] = mat[j - 1][a[i]];
      mat[1][a[i]] = tmp;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) printf("%d ", mat[i][j]);
    puts("");
  }
}
