#include <bits/stdc++.h>
int c[200005];
int main() {
  int n, a, b, i, ans, g;
  scanf("%d%d%d", &n, &a, &b);
  for (i = 1; i <= n; i++) scanf("%d", &c[i]);
  ans = g = 0;
  for (i = 1; i <= n; i++) {
    if (c[i] == 1) {
      if (a > 0)
        a--;
      else {
        if (b > 0) {
          b--;
          g++;
        } else {
          if (g > 0)
            g--;
          else
            ans++;
        }
      }
    } else {
      if (b > 0)
        b--;
      else
        ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
