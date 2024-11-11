#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int y, k, n, ans, p, i, total, c = 0, q;
  scanf("%I64d %I64d %I64d", &y, &k, &n);
  for (i = (y / k) + 1; i <= n / k; i++) {
    p = k * i;
    if (p > y && p <= n) {
      c = 1;
      printf("%I64d ", p - y);
    }
  }
  if (c == 0) {
    printf("-1");
  }
  return 0;
}
