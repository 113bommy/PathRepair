#include <bits/stdc++.h>
int main() {
  int n, m, a[110];
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
      int t = i;
      for (int j = i + 1; j < n; j++)
        if (a[j] > a[t]) t = j;
      if (i != t) {
        int tmp = a[t];
        a[t] = a[i];
        a[i] = tmp;
      }
    }
    int i;
    for (i = 0; m > 0; i++) m -= a[i];
    printf("%d\n", i);
  }
  return 0;
}
