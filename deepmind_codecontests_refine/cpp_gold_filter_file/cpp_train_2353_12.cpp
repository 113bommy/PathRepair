#include <bits/stdc++.h>
int main() {
  int n, k, q, l, r, a[200005] = {};
  scanf("%d%d%d", &n, &k, &q);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &l, &r);
    a[l]++;
    a[r + 1]--;
  }
  for (int i = 1; i <= 200000; i++) a[i] += a[i - 1];
  for (int i = 1; i <= 200000; i++) a[i] = a[i - 1] + (a[i] >= k);
  for (int i = 0; i < q; i++) {
    scanf("%d%d", &l, &r);
    printf("%d\n", a[r] - a[l - 1]);
  }
  return 0;
}
