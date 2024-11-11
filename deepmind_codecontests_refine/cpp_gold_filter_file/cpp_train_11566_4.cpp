#include <bits/stdc++.h>
int main() {
  int n, i, passage = 0;
  scanf("%d", &n);
  int a[n], b[n], k = 0;
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (i = 0; i < n - 1; i++) {
    if (a[i + 1] <= a[i]) {
      ++passage;
      b[k] = a[i];
      ++k;
    }
  }
  ++passage;
  b[k] = a[n - 1];
  ++k;
  printf("%d\n", passage);
  for (i = 0; i < k; i++) {
    printf("%d ", b[i]);
  }
  return 0;
}
