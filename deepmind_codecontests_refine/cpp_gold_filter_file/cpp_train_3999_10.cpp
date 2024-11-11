#include <bits/stdc++.h>
int s = 0, n, i, a[10000001];
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  if (n == 1)
    printf("1");
  else {
    for (i = 1; i <= n; i++)
      if (i < n && a[i] != a[i + 1]) s++;
    printf("%d", s + 1);
  }
  return 0;
}
