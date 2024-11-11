#include <bits/stdc++.h>
int main() {
  int n, k, i, t;
  int a[110];
  while (scanf("%d%d", &n, &k) != EOF) {
    t = 1;
    for (i = 0; i < n; i++) scanf("%d", a + i);
    for (i = 1; i < n; i++) {
      if (k % a[i] == 0) {
        t = t > a[i] ? t : a[i];
      }
    }
    t = k / t;
    printf("%d\n", t);
  }
}
