#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 3e5 + 10;
long long gcd(long long n, long long m) {
  if (n == 0)
    return m;
  else
    return gcd(m % n, n);
}
long long a[N];
long long n, m;
long long check(long long mid) {
  long long k = m - 1;
  for (long long i = n; i >= 1; i--) {
    if (a[i] <= k) {
      k = min(k, a[i] + mid);
    } else if (a[i] + k >= m) {
      k = min(k, a[i] + mid - m);
    } else
      return 0;
  }
  return 1;
}
long long binsearch(long long lo, long long hi) {
  long long ans = 0;
  while (hi >= lo) {
    long long mid = (lo + hi) / 2;
    if (check(mid)) {
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  return ans;
}
int32_t main() {
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cout << binsearch(0, m) << endl;
}
