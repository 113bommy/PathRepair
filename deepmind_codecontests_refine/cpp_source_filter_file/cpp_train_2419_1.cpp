#include <bits/stdc++.h>
int main() {
  long long int t;
  scanf("%lld", &t);
  while (t--) {
    long long int a, b;
    long long int ans = 0;
    long long int p, q;
    scanf("%lld %lld", &a, &b);
    if (a % b == 0)
      ans = 0;
    else {
      t = a % b;
      ans = b - t;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
