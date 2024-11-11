#include <bits/stdc++.h>
int main() {
  int m, n, a, b;
  while (~scanf("%d%d%d%d", &n, &m, &a, &b)) {
    if (n + 8 * a >= m)
      printf("0\n");
    else if (n + 8 * n < m && b >= a)
      printf("-1\n");
    else {
      n = n + 8 * a;
      int ans = 0;
      while (1) {
        ans++;
        n += 12 * a;
        n -= 12 * b;
        if (n > m) {
          printf("%d\n", ans);
          break;
        }
      }
    }
  }
  return 0;
}
