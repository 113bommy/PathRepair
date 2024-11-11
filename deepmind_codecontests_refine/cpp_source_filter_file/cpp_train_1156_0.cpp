#include <bits/stdc++.h>
long long n;
int sum;
long long ans = 1;
int main() {
  scanf("%I64d", &n);
  long long x = n;
  for (long long i = 2; i <= n; i++) {
    if (x % i == 0) {
      ans *= i;
      while (x % i == 0) x /= i;
    }
  }
  long long temp = ans;
  while (ans % n) {
    ans *= ans;
    ++sum;
  }
  printf("%I64d %I64d", temp, ans > n ? sum + 1 : sum);
  return 0;
}
