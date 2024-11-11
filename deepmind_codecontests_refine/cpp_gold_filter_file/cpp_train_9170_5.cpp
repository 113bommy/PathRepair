#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, q, x, y;
  cin >> n >> q;
  while (q--) {
    cin >> x >> y;
    long long ans = 0;
    if ((x + y) & 1) {
      if (n & 1) {
        if (x & 1) {
          ans += (x - 1) * n / 2;
          ans += y / 2;
        } else {
          ans += (x - 2) * n / 2;
          ans += n / 2;
          ans += (y + 1) / 2;
        }
      } else {
        if (x & 1) {
          ans += (x - 1) * n / 2;
          ans += y / 2;
        } else {
          ans += (x - 2) * n / 2;
          ans += n / 2;
          ans += (y + 1) / 2;
        }
      }
      if (n & 1)
        ans += n * n / 2 + 1;
      else
        ans += (n * n) / 2;
    } else {
      if (n & 1) {
        if (x & 1) {
          ans += (x - 1) * n / 2;
          ans += (y + 1) / 2;
        } else {
          ans += (x - 2) * n / 2;
          ans += n / 2 + 1;
          ans += y / 2;
        }
      } else {
        if (x & 1) {
          ans += (x - 1) * n / 2;
          ans += (y + 1) / 2;
        } else {
          ans += (x - 2) * n / 2;
          ans += n / 2;
          ans += y / 2;
        }
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
