#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  long long int ans;
  ans = pow(2, n);
  if (n > 13) {
    ans = pow(2, n) - (100 * pow(2, (n - 13)));
    printf("%lld", ans);
  } else {
    printf("%d", ans);
  }
  return 0;
}
