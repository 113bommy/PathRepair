#include <bits/stdc++.h>
int main() {
  long long int n, a[100001], i, c = 0, k = 0;
  scanf("%lld", &n);
  for (i = 0; i < n; i++) scanf("%lld", &a[i]);
  for (i = 0; i < n; i++) {
    if (a[i] > 0) k += a[i];
    if (a[i] == -1 && k > 0) {
      k--;
    } else if (a[i] == -1 && k == 0)
      c++;
  }
  printf("%lld\n", c);
  return 0;
}
