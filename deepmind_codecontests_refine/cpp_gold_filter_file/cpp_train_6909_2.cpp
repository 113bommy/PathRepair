#include <bits/stdc++.h>
int a[200000];
int main() {
  int n, x;
  scanf("%d%d", &n, &x);
  --x;
  int m = 1e9, mi;
  for (int i = 0; i != n; ++i) {
    scanf("%d", a + i);
    if (m > a[i]) {
      m = a[i];
      mi = i;
    } else if (m == a[i]) {
      if (i <= x || mi > x) {
        mi = i;
      }
    }
  }
  long long t = 1LL * m * n;
  if (mi <= x) {
    t += x - mi;
  } else {
    t += x + n - mi;
  }
  for (int i = 0; i != n; ++i) {
    if (i == mi)
      printf("%I64d ", t);
    else {
      if (mi <= x) {
        if (i > mi && i <= x) --a[i];
      } else if (i > mi || i <= x)
        --a[i];
      printf("%d ", a[i] - m);
    }
  }
  putchar('\n');
  return 0;
}
