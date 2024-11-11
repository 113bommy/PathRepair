#include <bits/stdc++.h>
int h1, a1, d1;
int h2, a2, d2;
int h, a, d;
int solve(int da, int dd) {
  int ret = a * da + d * dd;
  int h1 = ::h1, a1 = ::a1 + da, d1 = ::d1 + dd;
  int h2 = ::h2, a2 = ::a2, d2 = ::d2;
  if (a1 <= d2) return 0x3f3f3f3f;
  if (a2 <= d1) return ret;
  while (h2 > 0) {
    h2 -= a1 - d2;
    h1 -= a2 - d1;
  }
  if (h1 <= 0) {
    ret += (1 - h1) * h;
  }
  return ret;
}
int main() {
  scanf("%d%d%d", &h1, &a1, &d1);
  scanf("%d%d%d", &h2, &a2, &d2);
  scanf("%d%d%d", &h, &a, &d);
  int ans = 0x3f3f3f3f;
  for (int da = 0; da <= 201; da++) {
    for (int dd = 0; dd <= 201; dd++) {
      ans = std::min(ans, solve(da, dd));
    }
  }
  printf("%d\n", ans);
}
