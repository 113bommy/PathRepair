#include <bits/stdc++.h>
using namespace std;
long long a, b, cnt = 0, n;
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a);
    b = 0;
    long long k = 1000000000ll;
    while (k != 0) {
      b *= 100;
      b += a / k;
      a %= k;
      k /= 10;
    }
    cnt = (cnt + b % 998244353ll * 11) % 998244353ll;
  }
  printf("%lld", cnt * n % 998244353ll);
}
