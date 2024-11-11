#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int a[20001];
long long R(long long p) {
  if (p == 0) {
    return 1;
  } else if (p == 1) {
    return 2;
  } else {
    long long temp = R(p / 2);
    if (p % 2 == 1) {
      return (temp * temp * 2) % mod;
    } else {
      return (temp * temp) % mod;
    }
  }
}
long long N;
int main() {
  scanf("%I64d", &N);
  long long u = R(N - 1);
  long long ans = (u * ((1 + 2 * u) % mod)) % mod;
  if (N == 0) {
    printf("1\n");
  } else {
    printf("%I64d\n", ans);
  }
  return 0;
}
