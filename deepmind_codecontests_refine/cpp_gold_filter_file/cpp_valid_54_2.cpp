#include <bits/stdc++.h>
long long power(long long a, int k) {
  long long p = 1;
  while (k) {
    if (k & 1) p = p * a % 1000000007;
    a = a * a % 1000000007;
    k >>= 1;
  }
  return p;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k, i, ans;
    scanf("%d%d", &n, &k);
    if (k == 0)
      printf("1\n");
    else if (n % 2 == 1)
      printf("%lld\n", power(power(2, n - 1) + 1, k));
    else {
      ans = power(power(2, n - 1) - 1, k);
      for (i = 0; i < k; i++)
        ans = (ans +
               power(power(2, n - 1) - 1, i) * power(power(2, n), k - 1 - i)) %
              1000000007;
      printf("%d\n", ans);
    }
  }
  return 0;
}
