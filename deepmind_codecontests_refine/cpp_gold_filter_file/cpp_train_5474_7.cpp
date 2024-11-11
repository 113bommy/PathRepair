#include <bits/stdc++.h>
using namespace std;
long long lmt = 1e9 + 14;
long long int gcd(long long a, long long b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x, y, p, q;
    cin >> x >> y >> p >> q;
    long long dv = gcd(x, y);
    if (x / dv == p && y / dv == q) {
      cout << "0\n";
      continue;
    }
    if (p == q && x != y) {
      cout << "-1\n";
      continue;
    }
    long long lo = 0, hi = lmt, mid;
    while (lo < hi) {
      mid = lo + (hi - lo) / 2;
      if (q * mid - y <= 0 || p * mid - x < 0) {
        lo = mid + 1;
      } else if ((q - p) * mid >= y - x) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    if (hi == 0 || hi == lmt)
      cout << "-1\n";
    else
      cout << (q * hi - y) << "\n";
  }
  return 0;
}
