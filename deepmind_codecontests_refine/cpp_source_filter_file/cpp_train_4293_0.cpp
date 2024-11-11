#include <bits/stdc++.h>
int p[222], vis[111], x[111];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    memset(vis, 0, sizeof(vis));
    int n, i, e;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
      scanf("%d", &e);
      x[i] = e;
      vis[e] = 1;
    }
    int j, f = 0;
    for (i = 1; i <= n; i++) {
      p[2 * i - 1] = x[i];
      f = 0;
      for (j = x[i] + 1; j <= 2 * n; j++) {
        if (vis[j] == 0) {
          f = 1;
          p[2 * i] = j;
          vis[j] = 1;
          break;
        }
      }
      if (f == 0) {
        break;
      }
    }
    if (f == 0)
      printf("-1\n");
    else {
      for (i = 1; i <= 2 * n; i++) {
        printf("%d", p[i]);
        if (i == 2 * n)
          printf("\n");
        else
          printf(" ");
      }
    }
  }
  return 0;
}
