#include <bits/stdc++.h>
int main() {
  int n, k, i, j;
  scanf("%d%d", &n, &k);
  long long int a[n], t;
  for (i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (a[i] < a[j]) {
        t = a[i];
        a[i] = a[j];
        a[j] = t;
      }
    }
  }
  if (k <= n)
    printf("%lld 0", a[k - 1]);
  else
    printf("-1");
}
