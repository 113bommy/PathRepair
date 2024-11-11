#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
long long n, m, k;
long long a[N];
long long ans = 0;
long long check(long long idx) {
  long long boxes = 1;
  long long curleft = k;
  for (long long i = idx; i <= n; i++) {
    if (curleft - a[i] < 0) {
      boxes++;
      curleft = k - a[i];
    } else
      curleft -= a[i];
    if (boxes > m) return 0;
  }
  return 1;
}
long long binsearch(long long lo, long long hi) {
  while (lo < hi) {
    long long mid = (lo + hi) / 2;
    if (check(mid) == 1) {
      ans = mid;
      hi = mid;
    } else
      lo = mid + 1;
  }
  return lo;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m >> k;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  ans = binsearch(1, n);
  cout << n - ans + 1;
  return 0;
}
