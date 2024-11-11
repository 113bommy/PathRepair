#include <bits/stdc++.h>
using namespace std;
long long pr(long long x, long long y) {
  long long t = x, ans = 1;
  while (y) {
    if (y & 1) {
      ans *= t;
      ans %= 1000000007;
    }
    t *= t;
    t %= 1000000007;
    y /= 2;
  }
  return ans;
}
int main() {
  long long a, b, n, x;
  cin >> a >> b >> n >> x;
  long long trm1, trm2, trm3, trm4;
  if (a == 1) {
    trm1 = x;
    trm1 %= 1000000007;
    n %= 1000000007;
    trm2 = n * b;
    trm2 %= 1000000007;
    cout << (trm1 + trm2) % 1000000007;
  } else {
    n = n % (1000000007 - 1);
    trm3 = pr(a, n);
    trm1 = (trm3 * x) % 1000000007;
    trm2 = (b * (trm3 - 1 + 1000000007)) % 1000000007;
    trm2 = (trm2 * pr(a - 1, 1000000007 - 2)) % 1000000007;
    cout << (trm1 + trm2) % 1000000007;
  }
}
