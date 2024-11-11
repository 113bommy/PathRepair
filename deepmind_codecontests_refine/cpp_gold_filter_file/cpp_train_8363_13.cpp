#include <bits/stdc++.h>
int n, s, c[6], k[6], v[6], t, ans(0x7FFFFFFF);
int main() {
  for (scanf("%d%d", &n, &s); n--;) scanf("%d", &t), c[t]++;
  for (k[3] = s / (c[3] + c[4] + c[5]); k[3] >= 0; k[3]--)
    for (k[4] = (s - c[3] * k[3]) / (c[4] + c[5]); k[4] >= k[3]; k[4]--) {
      if ((s - c[3] * k[3] - c[4] * k[4]) % c[5]) continue;
      k[5] = (s - c[3] * k[3] - c[4] * k[4]) / c[5];
      if (c[5] * k[5] - c[4] * k[4] >= ans) break;
      int cur = abs(c[3] * k[3] - c[4] * k[4]) + abs(c[4] * k[4] - c[5] * k[5]);
      if (cur < ans) ans = cur, v[3] = k[3], v[4] = k[4], v[5] = k[5];
    }
  if (ans == 0x7FFFFFFF)
    printf("-1");
  else
    printf("%d %d %d", v[3], v[4], v[5]);
}
