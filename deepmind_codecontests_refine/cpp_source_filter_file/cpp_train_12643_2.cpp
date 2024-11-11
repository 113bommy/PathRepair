#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, y, m;
  long long a[7] = {0};
  while (cin >> x >> y) {
    scanf("%lld", &n);
    a[1] = x;
    a[2] = y;
    a[3] = y - x;
    a[4] = -x;
    a[5] = -y;
    a[6] = -a[3];
    if (n <= 6) {
      m = a[n];
      if (a[n] < 0) m += 1000000007;
      printf("%lld\n", m % 1000000007);
    } else {
      if (n % 6 == 0)
        m = a[6];
      else
        m = a[n % 6];
      if (m < 0) m += 1000000007;
      printf("%lld\n", m % 1000000007);
    }
  }
  return 0;
}
