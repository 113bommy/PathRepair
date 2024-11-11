#include <bits/stdc++.h>
using namespace std;
int vis[305];
int main() {
  int n, k, m;
  while (~scanf("%d%d%d", &n, &m, &k)) {
    int i, t, j;
    memset(vis, 0, sizeof(vis));
    for (i = 0; i < k; i++) {
      scanf("%d", &t);
      vis[t] = 1;
    }
    int Max = n - k + (n - 1) * (n - 2) / 2;
    if (k == n || m > Max)
      puts("-1");
    else {
      int f = 1, last;
      while (!vis[f]) f++;
      for (i = 1; i <= n && m; i++) {
        if (vis[i]) continue;
        printf("%d %d\n", f, i);
        last = i;
        m--;
        break;
      }
      for (i = 1; i <= n && m; i++) {
        if (i == f) continue;
        for (j = i + 1; j <= n && m; j++) {
          if (j == f) continue;
          printf("%d %d\n", i, j);
          m--;
        }
      }
      for (i = last + 1; i <= n && m; i++) {
        if (vis[i]) continue;
        printf("%d %d\n", f, i);
        m--;
      }
    }
  }
}
