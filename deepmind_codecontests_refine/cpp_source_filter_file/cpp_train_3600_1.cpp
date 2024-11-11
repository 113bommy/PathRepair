#include <bits/stdc++.h>
const int N = 50005;
int a[N], mx, mi, n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  if (n % 7 == 0) {
    mx = 1;
    for (int i = 2; i <= n; i++) {
      if (i % 7 == 0) continue;
      if (a[i] < a[mx]) mx = i;
    }
    printf("%d\n", mx);
  } else {
    mi = 1000000000;
    for (int i = 1; i <= n; i++) mi = std::min(mi, (a[i] - 1) / 6);
    for (int i = 1; i <= n; i++) a[i] -= mi * 6;
    for (int i = 1, day = 1;; i++, day++) {
      if (i > n) i = 1;
      if (day == 7) {
        day = 1;
        continue;
      }
      a[i]--;
      if (!a[i]) {
        printf("%d\n", i);
        return 0;
      }
    }
  }
}
