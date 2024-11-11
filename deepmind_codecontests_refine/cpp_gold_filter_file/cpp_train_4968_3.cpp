#include <bits/stdc++.h>
using namespace std;
long long candy(long long k, long long n) {
  long long ctr = 0;
  while (n > 0) {
    if (n < k) {
      ctr += n;
      n = 0;
    } else {
      n = n - k;
      ctr += k;
      if (n >= 10) n = n - (n / 10);
    }
  }
  return ctr;
}
int main() {
  ios_base::sync_with_stdio(false);
  long long n;
  cin >> n;
  long long lo = 1, hi = n;
  long long ans;
  while (lo <= hi) {
    long long mid = lo + (hi - lo) / 2;
    long long caneat = candy(mid, n);
    if (2 * caneat >= n) {
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  cout << ans << endl;
  return 0;
}
