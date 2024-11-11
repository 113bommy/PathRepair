#include <bits/stdc++.h>
using namespace std;
int t, n, b[105], a[205], vis[105], ret;
int main() {
  int i;
  scanf("%d", &t);
  while (t--) {
    memset(vis, 0, sizeof(vis));
    ret = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
      scanf("%d", &b[i]);
      vis[b[i]] = 1;
      a[i * 2 - 1] = b[i];
    }
    int j;
    for (i = 1; i <= n; i++) {
      ret = 0;
      for (j = a[2 * i - 1] + 1; j <= 2 * n; j++) {
        if (!vis[j]) {
          vis[j] = 1;
          a[i * 2] = j;
          ret = 1;
          break;
        }
      }
      if (!ret) break;
    }
    if (ret) {
      for (i = 1; i < 2 * n; i++) printf("%d ", a[i]);
      printf("%d\n", a[i]);
    } else
      printf("-1\n");
  }
  return 0;
}
