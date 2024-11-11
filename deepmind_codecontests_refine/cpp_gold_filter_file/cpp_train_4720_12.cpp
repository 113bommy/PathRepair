#include <bits/stdc++.h>
int ld[10000001], s[1000000], sz = 0;
int main() {
  int a, n, x, q, l, v;
  long long res = 0;
  scanf("%d%d", &a, &n);
  x = a + n - 1;
  for (int i = int(2); i < int(x + 1); ++i) {
    if (ld[i] == 0) {
      ld[i] = i;
      s[sz++] = i;
    }
    for (int j = 0; j < sz && s[j] <= ld[i] && i * s[j] <= x + 1; ++j)
      ld[i * s[j]] = s[j];
  }
  for (int i = int(a); i < int(a + n); ++i) {
    v = 1;
    q = i;
    l = 0;
    while (q != 1) {
      if (ld[q] == l) {
        v *= l * l;
        l = 0;
      } else
        l = ld[q];
      q /= ld[q];
    }
    res += i / v;
  }
  printf("%I64d", res);
  return 0;
}
