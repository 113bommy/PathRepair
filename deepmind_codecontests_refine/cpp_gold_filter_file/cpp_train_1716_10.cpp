#include <bits/stdc++.h>
int main() {
  long long c, h1, h2, w1, w2, i, j, k, ans;
  scanf("%I64d %I64d %I64d %I64d %I64d", &c, &h1, &h2, &w1, &w2);
  if (h1 * w2 > h2 * w1) {
    h1 += h2;
    w1 += w2;
    h2 = h1 - h2;
    w2 = w1 - w2;
    h1 -= h2;
    w1 -= w2;
  }
  ans = 0;
  if (w2 * w2 >= c) {
    for (i = 0; w2 * i <= c; i++) {
      j = i * h2 + ((c - i * w2) / w1) * h1;
      if (j > ans) {
        ans = j;
      }
    }
  } else {
    for (i = 0; i < w2 && i * w1 <= c; i++) {
      j = i * h1 + ((c - i * w1) / w2) * h2;
      if (j > ans) {
        ans = j;
      }
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
