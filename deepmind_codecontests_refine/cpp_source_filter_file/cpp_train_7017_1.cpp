#include <bits/stdc++.h>
int n, m;
struct node {
  int a, b, c;
} p[100010];
int vis[100010];
int used[10];
int main() {
  int i, j;
  while (scanf("%d%d", &n, &m) != EOF) {
    for (i = 1; i <= m; i++) {
      scanf("%d%d%d", &p[i].a, &p[i].b, &p[i].c);
    }
    memset(vis, 0, sizeof(vis));
    for (i = m; i >= 1; i--) {
      memset(used, 0, sizeof(used));
      used[vis[p[i].a]] = 1;
      used[vis[p[i].b]] = 1;
      used[vis[p[i].c]] = 1;
      if (vis[p[i].a] == 0) {
        for (j = 1; j <= 3; j++) {
          if (used[j] == 0) {
            vis[p[i].a] = j;
            used[j] = 1;
            break;
          }
        }
      }
      if (vis[p[i].b] == 0) {
        for (j = 1; j <= 3; j++) {
          if (used[j] == 0) {
            vis[p[i].b] = j;
            used[j] = 1;
            break;
          }
        }
      }
      if (vis[p[i].c] == 0) {
        for (j = 1; j <= 3; j++) {
          if (used[j] == 0) {
            vis[p[i].c] = j;
            used[j] = 1;
            break;
          }
        }
      }
    }
    for (i = 1; i <= n; i++) {
      if (i == 1)
        printf("%d", vis[i]);
      else
        printf(" %d", vis[i]);
    }
    printf("\n");
  }
  return 0;
}
