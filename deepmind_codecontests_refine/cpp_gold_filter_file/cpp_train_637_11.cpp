#include <bits/stdc++.h>
int main() {
  int n, m, i, o = 0, p = 0, j = 0, k = 0;
  scanf("%d%d", &n, &m);
  int a[n], b[m];
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (a[i] % 2 == 1) {
      j++;
    }
  }
  o = n - j;
  for (i = 0; i < m; i++) {
    scanf("%d", &b[i]);
    if (b[i] % 2 == 1) {
      k++;
    }
  }
  p = m - k;
  if (k > o) {
    k = o;
  }
  if (p < j) {
    j = p;
  }
  printf("%d", j + k);
  return 0;
}
