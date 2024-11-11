#include <bits/stdc++.h>
using namespace std;
const long long P = 1e9 + 7;
long long Pow(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = res * a % P;
    a = a * a % P, n >>= 1;
  }
  return res;
}
int main(void) {
  long long x, k;
  while (~scanf("%lld%lld", &x, &k)) {
    if (x == 0) {
      printf("0\n");
      continue;
    }
    long long ans = Pow(2, k + 1) * (x % P) % P;
    ans -= Pow(2, k) - 1;
    ans = (ans % P + P) % P;
    printf("%lld\n", ans);
  }
  return 0;
}
