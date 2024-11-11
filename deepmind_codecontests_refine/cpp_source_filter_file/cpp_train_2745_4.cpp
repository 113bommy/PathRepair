#include <bits/stdc++.h>
using namespace std;
int a[100000], axis[100000], f[100000];
int main() {
  int k, n, maxb, t;
  scanf("%d%d%d%d", &k, &n, &maxb, &t);
  while (k > 0) {
    k--;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      axis[i] = a[i];
    }
    sort(axis, axis + n);
    int tot = unique(axis, axis + n) - axis;
    if (t >= tot) {
      printf("%d\n", tot);
      continue;
    }
    for (int i = 0; i < n; i++)
      a[i] = lower_bound(axis, axis + tot, a[i]) - axis;
    memset(f, 0, sizeof(f));
    for (int tt = 0; tt < t; tt++) {
      for (int i = 0; i < n; i++) {
        int tmp = (a[i] == 0) ? 0 : f[a[i] - 1];
        int j = i;
        while (j < tot && f[j] == tmp) {
          f[j]++;
          j++;
        }
      }
    }
    printf("%d\n", f[tot - 1]);
  }
  return 0;
}
