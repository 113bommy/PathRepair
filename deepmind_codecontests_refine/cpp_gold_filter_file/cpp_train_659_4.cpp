#include <bits/stdc++.h>
int main() {
  long long int i, y, k, n, c;
  scanf("%I64d %I64d %I64d", &y, &k, &n);
  c = 0;
  for (i = k - (y % k); i <= n - y; i = i + k) {
    if ((i + y) % k == 0) {
      c++;
      printf("%I64d ", i);
    }
  }
  if (c == 0) printf("-1");
  return 0;
}
