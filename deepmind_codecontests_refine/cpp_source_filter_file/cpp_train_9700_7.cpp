#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, k, a[101], q, x, tot, mi, ma, cnt;
  bool vst[101];
  while (scanf("%d%d", &n, &k) == 2) {
    for (i = 1; i <= n; i++) scanf("%d", a + i);
    memset(vst, 0, n + 1);
    scanf("%d", &q);
    mi = 1e9;
    ma = 0;
    x = n / k;
    while (q--) {
      for (i = tot = 0; i < x; i++) {
        scanf("%d", &j);
        vst[j] = 1;
        tot += a[j];
      }
      if (tot < mi) mi = tot;
      if (tot > ma) ma = tot;
    }
    j = cnt = 0;
    for (i = 1; i <= n; i++)
      if (!vst[i])
        a[j++] = a[i];
      else
        cnt++;
    if (n >= x + cnt) {
      sort(a, a + j);
      for (i = tot = 0; i < x; i++) tot += a[i];
      if (tot < mi) mi = tot;
      for (i = j - x, tot = 0; i < j; i++) tot += a[i];
      if (tot > ma) ma = tot;
    }
    printf("%lf %lf\n", mi * 1.0 / x, ma * 1.0 / x);
  }
  return 0;
}
