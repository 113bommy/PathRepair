#include <bits/stdc++.h>
int main() {
  long long int tc;
  scanf("%lld", &tc);
  while (tc--) {
    long long int r, n;
    scanf("%lld %lld", &n, &r);
    long long int ans;
    if (r >= n) {
      ans = (n - 1) * n / 2 + 1;
      printf("%lld", ans);
    } else {
      ans = r * (r + 1) / 2;
      printf("%lld", ans);
    }
  }
}
