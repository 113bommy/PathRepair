#include <bits/stdc++.h>
using namespace std;
long long sum[100010], a, b;
long long calc(long long n) {
  long long ans = n + 1;
  ans -= n / (a * b) * sum[a * b];
  ans -= sum[n % (a * b)];
  return ans;
}
int main() {
  long _ = 1, __ = 1, n, i;
  long long x, y;
  for (((1) ? scanf("%ld", &_) : EOF); _; _--, __++) {
    scanf("%lld%lld%ld", &a, &b, &n);
    for (i = 1; i <= a * b; i++) {
      sum[i] = sum[i - 1];
      if (i % a % b == i % b % a) sum[i]++;
    }
    for (i = 1; i <= n; i++) {
      scanf("%lld%lld", &x, &y);
      printf("%lld ", calc(y) - calc(x - 1));
    }
    printf("\n");
  }
  return 0;
}
