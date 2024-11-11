#include <bits/stdc++.h>
const int maxN = 5e5, maxSmall = 1e3;
int q;
long long int a[maxN], memo[maxSmall + 1][maxSmall + 1];
int main() {
  scanf("%d", &q);
  while (q--) {
    int op, x, y;
    scanf("%d %d %d", &op, &x, &y);
    if (op == 1) {
      a[x] += y;
      for (int i = 1; i <= maxSmall; i++) memo[i][x % i] += y;
    } else {
      if (x <= maxSmall)
        printf("%lld\n", memo[x][y]);
      else {
        long long int ans = 0;
        for (int i = y; i <= maxN; i += x) ans += a[i];
        printf("%lld\n", ans);
      }
    }
  }
  return 0;
}
