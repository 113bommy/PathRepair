#include <bits/stdc++.h>
int n, k, a, b, c, d;
int vis[1005];
int main() {
  scanf("%d%d", &n, &k);
  scanf("%d%d%d%d", &a, &b, &c, &d);
  vis[a] = vis[b] = vis[c] = vis[d] = 1;
  if (k < n + 1 || n == 4)
    printf("-1\n");
  else {
    printf("%d %d", a, c);
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) printf(" %d", i);
    }
    printf(" %d %d\n", d, b);
    printf("%d %d", c, a);
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) printf(" %d", i);
    }
    printf(" %d %d\n", b, d);
  }
}
