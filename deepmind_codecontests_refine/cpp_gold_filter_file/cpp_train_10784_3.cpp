#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  long long x, y, p, q;
  while (t--) {
    int ok = 0;
    cin >> x >> y >> p >> q;
    long long ta = q - p, tb = y - x;
    if (x != 0 || p != 0) {
      int l = 0, r = 1e9 + 7, mid;
      while (l < r) {
        mid = (l + r) / 2;
        if (mid * ta >= tb && mid * p >= x)
          r = mid;
        else
          l = mid + 1;
      }
      if (l == 1e9 + 7)
        printf("-1\n");
      else
        printf("%lld\n", l * q - y);
    } else {
      printf("0\n");
      ok = 1;
    }
  }
  return 0;
}
