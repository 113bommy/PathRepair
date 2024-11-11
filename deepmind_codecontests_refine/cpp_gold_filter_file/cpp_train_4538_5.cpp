#include <bits/stdc++.h>
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
using namespace std;
long long n, k;
long long oula(long long x) {
  long long temp = x;
  for (long long i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      temp = temp / i * (i - 1);
      while (x % i == 0) {
        x /= i;
      }
    }
  }
  if (x > 1) temp = temp / x * (x - 1);
  return temp;
}
int main() {
  scanf("%lld%lld", &n, &k);
  if (k == 1) {
    printf("%lld\n", oula(n) % mod);
  } else {
    if (k % 2 == 0) {
      k--;
    }
    long long cnt = k / 2 + 1;
    long long temp = n;
    while (cnt != 0) {
      cnt--;
      temp = oula(temp);
      if (temp == 1) break;
    }
    temp = (temp + mod) % mod;
    printf("%lld\n", temp);
  }
  return 0;
}
