#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  scanf("%I64d", &n);
  long long ans;
  ans = 1;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      ans *= i;
    }
    while (n % i == 0) {
      n /= i;
    }
  }
  if (n > 1) {
    ans *= n;
  }
  printf("%I64d", ans);
}
