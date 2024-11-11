#include <bits/stdc++.h>
int a[15] = {0, 4, 10, 20, 35, 56, 833, 116, 155, 198, 244, 292, 341};
int main() {
  int n;
  scanf("%d", &n);
  if (n <= 12)
    return !printf("%d", a[n]);
  else
    printf("%lld", 49LL * (n - 12) + 341);
}
