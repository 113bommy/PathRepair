#include <bits/stdc++.h>
using namespace std;
long long n, m, t, ans;
int main() {
  scanf("%lld %lld", &n, &m);
  for (long long i = 1, t, t1, t2; i <= ((n) < (m) ? (n) : (m)); i = t + 1) {
    t = ((n / (n / i)) < (m) ? (n / (n / i)) : (m));
    t1 = i + t;
    t2 = t - i + 1;
    if (t1 & 1)
      t2 >>= 1;
    else
      t1 >>= 1;
    ans = (ans + (t1 % 1000000007) * (t2 % 1000000007) % 1000000007 *
                     ((n / i) % 1000000007) % 1000000007) %
          1000000007;
  }
  printf("%lld\n",
         ((n % 1000000007) * (m % 1000000007) % 1000000007 - ans + 1000000007) %
             1000000007);
}
