#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  scanf("%lld %lld", &n, &m);
  if (n > m) swap(n, m);
  long long ans = 0;
  if (n == 1) {
    ans = m / 6 * 3 + max(m % 6 - 3, 0ll) * 2;
  } else if (n == 2) {
    switch (m) {
      case 2:
        ans = 0;
        break;
      case 3:
        ans = 4;
        break;
      case 7:
        ans = 12;
        break;
      default:
        ans = m * 2;
    }
  } else {
    ans = n * m / 2 * 2;
  }
  printf("%lld\n", ans);
  return 0;
}
