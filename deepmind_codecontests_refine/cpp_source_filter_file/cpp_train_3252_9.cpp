#include <bits/stdc++.h>
using namespace std;
long long a[60];
signed main() {
  long long t;
  a[0] = 1;
  for (long long i = 1; i <= 31; i++) {
    a[i] = a[i - 1] * 4;
  }
  cin >> t;
  long long n = 0;
  while (t--) {
    n++;
    long long y = lower_bound(a, a + 30, n) - a;
    if (a[y] > n) y--;
    long long d = n - a[y];
    long long b = d % 3;
    if (b == 0) {
      cout << a[y] + d / 3 << (" ");
    } else if (b == 1) {
      long long b1 = d / 3;
      long long ans2 = 0;
      long long d3 = 1;
      while (b1) {
        long long r = b1 % 4;
        long long r1 = b1 - r, r2 = 0;
        if (r == 0)
          r2 = 0;
        else if (r == 1)
          r2 = 2;
        else if (r == 2)
          r2 = 3;
        else if (r == 3)
          r2 = 1;
        ans2 += r2 * d3;
        b1 >>= 2;
        d3 *= 4;
      }
      cout << (a[y] * 2 + ans2) << (" ");
    } else if (b == 2) {
      long long b1 = d / 3;
      long long ans2 = 0;
      long long d3 = 1;
      while (b1) {
        long long r = b1 % 4;
        long long r1 = b1 - r, r2 = 0;
        if (r == 0)
          r2 = 0;
        else if (r == 1)
          r2 = 3;
        else if (r == 2)
          r2 = 1;
        else if (r == 3)
          r2 = 2;
        ans2 += r2 * d3;
        b1 >>= 2;
        d3 *= 4;
      }
      cout << (a[y] * 3 + ans2) << (" ");
    }
  }
  return 0;
}
