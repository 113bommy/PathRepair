#include <bits/stdc++.h>
int main() {
  int n, i, j;
  while (scanf("%d", &n) == 1) {
    int ans = 0, all[50][50], l[50], c[50];
    for (i = 0; i < n; ++i) {
      for (j = 0; j < n; ++j) {
        scanf("%d", &all[i][j]);
      }
    }
    for (i = 0; i < n; ++i) {
      for (j = 0; j < n; ++j) {
        l[i] += all[i][j];
      }
    }
    for (j = 0; j < n; ++j) {
      for (i = 0; i < n; ++i) {
        c[j] += all[i][j];
      }
    }
    for (i = 0; i < n; ++i) {
      for (j = 0; j < n; ++j) {
        if (l[i] < c[j]) ans++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
