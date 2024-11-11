#include <bits/stdc++.h>
int main() {
  int n, a[105], b = 0, sum = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  int max = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] > max) max = a[i];
  }
  for (int i = 0; i < n; i++) {
    if (a[i] < max) {
      b = max - a[i];
      sum += b;
    }
  }
  printf("%d\n", sum);
  return 0;
}
