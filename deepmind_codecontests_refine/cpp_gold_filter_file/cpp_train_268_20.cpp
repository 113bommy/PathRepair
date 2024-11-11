#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
int a[50];
int main(void) {
  int i, j, l;
  while (scanf("%lld%lld%lld", &n, &k, &m) != EOF) {
    long long ans = 0, sum = 0, x = 0, y = 0, z = 0, m1 = 0;
    for (i = 1; i <= k; i++) {
      scanf("%d", &a[i]);
      m1 += a[i];
    }
    sort(a + 1, a + k + 1);
    for (i = 0; i <= n; i++) {
      x = m1 * i;
      if (x > m) break;
      sum = x;
      y = (k + 1) * i;
      for (j = 1; j <= k; j++) {
        for (l = i + 1; l <= n; l++) {
          sum += a[j];
          y++;
          if (sum > m) {
            y--;
            j = k + 1;
            break;
          }
        }
      }
      ans = max(ans, y);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
