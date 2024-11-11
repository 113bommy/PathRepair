#include <bits/stdc++.h>
int main() {
  int n, i, j, temp, ans, col[128], row[128];
  while (scanf("%d", &n) != EOF) {
    ans = 0;
    for (i = 0; i < n; i++) {
      row[i] = 0;
      for (j = 0; j < n; j++) {
        if (i == 0) col[j] = 0;
        scanf("%d", &temp);
        col[j] += temp;
        row[i] += temp;
      }
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (col[i] > row[j]) ans++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
