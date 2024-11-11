#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int n, long long int m) {
  long long int res = 1;
  while (n > 0) {
    if (n & 1) res = (res * x) % m;
    x = (x * x) % m;
    n = n >> 1;
  }
  return res;
}
long long int maxSubsetSum(vector<long long int> v) {
  long long int max_so_far = LLONG_MIN, max_ending_here = 0;
  for (long long int i = 0; i < (long long int)v.size(); i++) {
    max_ending_here += v[i];
    if (max_so_far < max_ending_here) max_so_far = max_ending_here;
    if (max_ending_here < 0) max_ending_here = 0;
  }
  return max_so_far;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int q;
  cin >> q;
  while (q--) {
    long double h, c, t, res = 1e7;
    cin >> h >> c >> t;
    long double d1 = (h + c) / 2;
    long long int lo = 1, hi = 1e12, ans = hi;
    while (lo <= hi) {
      long long int mid = (lo + hi) / 2;
      long double d = (mid * h + (mid - 1) * c) / (long double)(2 * mid - 1);
      if (d - t == 0) {
        ans = 2 * mid - 1;
        break;
      } else if (d - t < 0) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
      if (res >= abs(d - t)) {
        if (res == abs(d - t))
          ans = min(ans, 2 * mid - 1);
        else
          ans = 2 * mid - 1;
        res = abs(d - t);
      }
    }
    if (res == abs(d1 - t))
      ans = min(ans, (long long int)2);
    else if (res > abs(d1 - t))
      ans = min(ans, (long long int)2);
    cout << ans << endl;
  }
  return 0;
}
