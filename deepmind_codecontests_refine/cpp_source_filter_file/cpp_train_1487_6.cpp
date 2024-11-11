#include <bits/stdc++.h>
using namespace std;
int m, n, i, j, t;
int a[300010], vis[300010], ans[300010], dis[300010];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      vis[i] = 0, ans[i] = -1, dis[i] = -1;
    }
    for (i = 1; i <= n; i++) {
      dis[a[i]] = max(dis[a[i]], i - vis[a[i]]);
      vis[a[i]] = i;
    }
    for (i = 1; i <= n; i++) {
      if (dis[i] != -1) {
        dis[a[i]] = max(dis[a[i]], n + 1 - vis[a[i]]);
      }
    }
    for (i = 1; i <= n; i++) {
      if (dis[i] != -1) {
        for (j = dis[i]; j <= n; j++) {
          if (ans[j] > 0 && ans[j] < i) break;
          ans[j] = i;
        }
      }
    }
    int now = -1;
    for (i = 1; i <= n; i++) {
      printf("%d ", ans[i]);
    }
    printf("\n");
  }
  return 0;
}
