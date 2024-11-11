#include <bits/stdc++.h>
int main() {
  int n, j, i;
  int a[105];
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  for (i = 1; i <= n; i++)
    for (j = 0; j <= n; j++)
      if (a[j] == i) printf("%d ", (j + 1));
  return 0;
}
