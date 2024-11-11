#include <bits/stdc++.h>
int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    long long n, k;
    scanf("%lld %lld", &n, &k);
    long long ans = 0;
    while (n > 1) {
      while (n % k == 0) {
        n /= k;
        ans++;
      }
      long long nxt = (n / k) * k;
      ans += n - nxt;
      n = nxt;
    }
    printf("%lld\n", ans);
  }
}
