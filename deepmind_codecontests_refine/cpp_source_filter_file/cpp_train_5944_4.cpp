#include <bits/stdc++.h>
int main() {
  int i, n;
  scanf("%d", &n);
  int a[n];
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (a[i] % 2 == 0) a[i] = a[i] - 1;
  }
  for (i = 0; i < n; i++) {
    printf("%d", a[i]);
  }
  return 0;
}
