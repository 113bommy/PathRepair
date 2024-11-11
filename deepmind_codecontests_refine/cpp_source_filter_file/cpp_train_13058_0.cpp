#include <bits/stdc++.h>
int main() {
  int n, t, c, a, p, i, ans;
  while (scanf("%d %d %d", &n, &t, &c) != EOF) {
    ans = p = 0;
    for (i = 0; i < n; i++) {
      scanf("%d", &a);
      if (a > t) {
        if (p > c) {
          ans += (p + 1 - c);
        }
        p = 0;
      } else {
        p++;
      }
    }
    if (p >= c) {
      ans += (p + 1 - c);
    }
    printf("%d\n", ans);
  }
  return 0;
}
