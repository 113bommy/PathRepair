#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n, d;
  cin >> n >> d;
  auto foo = [&](long long x) { return (x * x + x) / 2; };
  long long start = 0;
  if (d > 32) {
    if (foo(d) > n) {
      cout << "NO" << '\n';
      return 0;
    }
    start = 1;
  }
  long long lo = 1, hi = 33;
  if (!start) {
    while (lo <= hi) {
      long long mid = (lo + hi) / 2;
      if (n < foo(mid + d - 1) - foo(mid - 1)) {
        hi = mid - 1;
      } else if (mid << d < n + mid) {
        lo = mid + 1;
      } else {
        start = mid;
        break;
      }
    }
  }
  if (!start) {
    cout << "NO" << '\n';
    return 0;
  }
  cout << "YES" << '\n' << start;
  long long last = start;
  for (long long i{2}; i <= d && n > 0; ++i) {
    n -= last;
    long long lo = last + 1, hi = 2 * last;
    while (lo <= hi) {
      long long mid = (lo + hi) / 2;
      long long diff = foo(mid + (d - i)) - foo(mid - 1);
      if (diff > n)
        hi = mid - 1;
      else {
        lo = mid + 1;
        last = mid;
      }
    }
    cout << ' ' << last;
  }
  return 0;
}
