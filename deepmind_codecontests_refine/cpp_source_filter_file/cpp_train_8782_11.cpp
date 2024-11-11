#include <bits/stdc++.h>
int compare(const void *a, const void *b) {
  int ia = *(int *)a;
  int ib = *(int *)b;
  return ia - ib;
}
int main() {
  static int aa[100000];
  int m, n, x, i, ans;
  scanf("%d", &m);
  x = 100001;
  while (m--) {
    int q;
    scanf("%d", &q);
    if (x > q) x = q;
  }
  scanf("%d", &n);
  ans = 0;
  for (i = 0; i < n; i++) {
    scanf("%d", &aa[i]);
    ans += aa[i];
  }
  qsort(aa, n, sizeof *aa, compare);
  for (i = n - x - 1; i >= 0; i = i - x - 3) {
    ans -= aa[i];
    if (i > 0) ans -= aa[i - 1];
  }
  printf("%d\n", ans);
  return 0;
}
