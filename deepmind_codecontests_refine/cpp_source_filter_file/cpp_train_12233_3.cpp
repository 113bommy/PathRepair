#include <bits/stdc++.h>
long long int largestLovelyDivisor(long long int n) {
  for (long long int idx = 2; idx * idx < n; idx++) {
    while (n % (idx * idx) == 0) {
      n = n / idx;
    }
  }
  return n;
}
int main() {
  long long int n;
  scanf("%lld", &n);
  long long int x = largestLovelyDivisor(n);
  printf("%lld", x);
  return 0;
}
