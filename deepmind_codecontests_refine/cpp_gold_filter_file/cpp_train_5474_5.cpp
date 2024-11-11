#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long tc;
  cin >> tc;
  while (tc--) {
    long long x, y, p, q;
    cin >> x >> y >> p >> q;
    if ((p / q) == 1 && x / y != 1) {
      cout << -1 << "\n";
      continue;
    }
    if (p == 0) {
      if (x == 0)
        cout << 0 << "\n";
      else
        cout << -1 << "\n";
      continue;
    }
    long long b = y;
    if (y % q != 0) b = b - y % q + q;
    long long a = (p * b) / q;
    if (a < x) {
      b = (x * q) / p;
      if (b % q != 0) b = b - b % q + q;
    }
    a = p * (b / q);
    long long start = 0, end = 1000000000;
    long long ans = -1;
    while (start <= end) {
      long long mid = (start + end) / 2;
      a = p * ((b + mid * q) / q);
      if ((b + mid * q) - y >= a - x) {
        end = mid - 1;
        ans = mid;
      } else {
        start = mid + 1;
      }
    }
    cout << b + ans * q - y << "\n";
  }
}
