#include <bits/stdc++.h>
int main(void) {
  int n, i, a[1005], ct = 0;
  scanf("%d", &n);
  getchar();
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  for (i = 1; i < n - 1; i++) {
    if (a[i - 1] > a[i] && a[i + 1] > a[i]) ct++;
    if (a[i - 1] < a[i] && a[i + 1] < a[i]) ct++;
  }
  printf("%d\n", ct);
}
