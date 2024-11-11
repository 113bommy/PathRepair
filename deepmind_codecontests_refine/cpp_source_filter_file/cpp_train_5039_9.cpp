#include <bits/stdc++.h>
int max(int a, int b) { return a > b ? a : b; }
int main() {
  int num[100005], sum, i, j, k, n, ma, mid;
  while (scanf("%d", &n) != EOF) {
    for (i = 1, sum = 0; i <= n; i++) {
      scanf("%d", &num[i]);
      sum += num[i];
    }
    for (i = 1, ma = 0, mid = -9000000; i <= n; i++) {
      if (ma < 0) {
        ma = 0;
      }
      ma += num[i];
      mid = max(mid, ma);
    }
    mid = max(mid, ma);
    printf("%d\n", 2 * mid - sum);
  }
}
