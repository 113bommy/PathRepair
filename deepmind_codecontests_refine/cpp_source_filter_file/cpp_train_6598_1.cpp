#include <bits/stdc++.h>
int a[1000000];
int main() {
  int n, i, j, k, t;
  long long s = 0;
  for (scanf("%d", &n), i = n; i >= 0;) {
    j = i;
    for (t = 0; j; j >>= 1, t++)
      ;
    k = (1 << t) - 1;
    j = k - i;
    while (i >= j) {
      s += k;
      a[i] = k - i;
      i--;
    }
  }
  printf("%d\n", s);
  for (i = 0; i <= n; i++) printf("%d ", a[i]);
  puts("");
  return 0;
}
