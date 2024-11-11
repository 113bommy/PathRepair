#include <bits/stdc++.h>
int n, m, b, c, i, j, kol;
long long ans;
int main() {
  scanf("%d%d", &n, &m);
  ans = 0;
  b = 1;
  for (c = 1; c <= m; c++) {
    while (b * b < c) b++;
    if (b > n) break;
    if (b * b == c)
      ans += (n - b) * 2 + 1;
    else
      ans += (n - b + 1) * 2;
  }
  for (i = 1; i <= m; i++) {
    kol = 0;
    if (i % 2 == 1) {
      c = i;
      j = 1;
    } else {
      c = i * 2;
      j = 2;
    }
    while (c <= m) {
      if (((i + j) >> 1) > n) break;
      kol++;
      c += (i << 1);
      j += 2;
    }
    if (kol > 0) ans = ans - kol + 1;
  }
  printf("%I64d", ans);
  return 0;
}
