#include <bits/stdc++.h>
int main() {
  int q, n, i, j;
  scanf("%d", &q);
  for (i = 1; i <= q; i = i + 1) {
    scanf("%d", &n);
    int a[n];
    int sum = 0;
    for (j = 0; j < n; j = j + 1) {
      scanf("%d", &a[i]);
      sum = sum + a[i];
    }
    if (sum % n == 0) {
      printf("%d\n", sum / n);
    } else {
      printf("%d\n", (sum / n) + 1);
    }
  }
}
