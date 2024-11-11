#include <bits/stdc++.h>
int ghost[333];
int mark[333];
int main() {
  int m, t, r;
  while (~scanf("%d %d %d", &m, &t, &r)) {
    for (int i = 0; i < m; i++) scanf("%d", &ghost[i]);
    if (t < r) {
      printf("-1\n");
      continue;
    }
    memset(mark, 0, sizeof(mark));
    int ans = 0;
    for (int i = 0; i < m; i++) {
      for (int j = ghost[i] - 1; mark[ghost[i]] < r; j--) {
        for (int k = j + 1; k <= j + t; k++) {
          if (k >= 0) {
            mark[k]++;
          }
        }
        ans++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
