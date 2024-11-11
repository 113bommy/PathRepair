#include <bits/stdc++.h>
using namespace std;
long long a[200500];
long long res[200500];
long long n;
bool check(long long x) {
  for (long long i = 0; i < n; i++) {
    res[i] = 0;
  }
  for (long long i = n - 1; i >= 2; i--) {
    long long f = (a[i] + res[i]) - x;
    if (f < 0) {
      return false;
    }
    long long k = min((f / 3), (a[i] / 3));
    res[i - 1] += k;
    res[i - 2] += 2 * k;
  }
  if (a[0] + res[0] < x) {
    return false;
  }
  if (a[1] + res[1] < x) {
    return false;
  }
  return true;
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long l = 0, r = 10;
    while (r - l > 1) {
      long long mid = (l + r) / 2;
      if (check(mid)) {
        l = mid;
      } else {
        r = mid;
      }
    }
    cout << l << '\n';
  }
}
