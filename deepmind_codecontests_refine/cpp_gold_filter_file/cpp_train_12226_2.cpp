#include <bits/stdc++.h>
int c[1007];
bool vis[1007][1007];
int main() {
  int n, k;
  while (scanf("%d%d", &n, &k) != EOF) {
    memset(vis, false, sizeof(vis));
    int a1 = 0, a2 = n * k;
    for (int i = n - 1; i >= 1; i--) a1 += i;
    if (a1 < a2) {
      printf("-1\n");
      continue;
    }
    printf("%d\n", a2);
    for (int i = 1; i <= n; i++) {
      int countt = 0;
      for (int j = 1; j <= n; j++) {
        if (i == j || vis[i][j]) continue;
        countt++;
        vis[i][j] = vis[j][i] = true;
        printf("%d %d\n", i, j);
        if (countt == k) break;
      }
    }
  }
  return 0;
}
