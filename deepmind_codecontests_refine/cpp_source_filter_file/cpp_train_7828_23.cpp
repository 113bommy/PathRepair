#include <bits/stdc++.h>
int a[110];
int main() {
  int i, j, k, l, n;
  scanf("%d", &n);
  memset(a, 0, sizeof(a));
  for (i = 1; i <= n; i++) {
    scanf("%d", &j);
    a[j]++;
  }
  int ans = 0;
  k = 0;
  for (j = 1; j <= 100; j++) {
    if (a[j] > 0) {
      if (a[j] % 4 == 0) {
        ans += a[j] / 4;
        a[j] /= 4;
      }
      if (a[j] % 4 >= 2) {
        if (k) {
          ans++;
          k = 0;
        } else
          k = 1;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
