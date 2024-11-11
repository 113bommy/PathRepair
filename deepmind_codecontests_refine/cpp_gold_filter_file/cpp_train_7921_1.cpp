#include <bits/stdc++.h>
using namespace std;
long long n, m;
signed main() {
  scanf("%lld%lld", &n, &m);
  if (n > m) swap(n, m);
  if (n == 1) {
    if (m <= 3)
      putchar('0');
    else {
      long long ans = m / 6 * 6, k = m % 6;
      if (k == 4) ans += 2;
      if (k == 5) ans += 4;
      printf("%lld", ans);
    }
    return 0;
  }
  if (n == 2) {
    if (m <= 2) putchar('0');
    if (m == 3) printf("4");
    if (m == 4) printf("8");
    if (m == 7) printf("12");
    if (m > 4 && m != 7) printf("%lld", m * 2);
    return 0;
  }
  long long ans = n * m;
  if (ans & 1) ans--;
  cout << ans;
  return 0;
}
