#include <bits/stdc++.h>
using namespace std;
long long n;
long long mod = 1000000007;
int main() {
  while (scanf("%I64d", &n) == 1) {
    if (n == 0)
      printf("1\n");
    else {
      long long k = n - 1;
      long long cr = 1;
      long long s = 2;
      long long ans = 0;
      while (k > 0) {
        if (k % 2 == 1) cr = cr * s % mod;
        s = s * s % mod;
        k = k / 2;
      }
      ans = cr * cr % mod * 2 % mod;
      cr = 1;
      k = n - 1;
      s = 2;
      while (k > 0) {
        if (k % 2 == 1) cr = cr * s % mod;
        s = s * s % mod;
        k = k / 2;
      }
      ans = (ans + cr) % mod;
      printf("%I64d\n", ans);
    }
  }
}
