#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int a[n], i, count = 0;
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (i = 1; i < n; i++) {
    if ((a[i] < a[i - 1]) && (a[i] < a[i + 1]))
      count++;
    else if ((a[i] > a[i - 1]) && (a[i] > a[i + 1]))
      count++;
  }
  printf("%d\n", count);
  return 0;
}
