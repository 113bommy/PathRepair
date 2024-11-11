#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  n--;
  if (n > k * (k - 1) / 2) {
    cout << -1;
    return 0;
  }
  auto check = [&](long long x) {
    return (k * (k - 1) - (k - x) * (k - x - 1)) / 2 >= n;
  };
  long long lo = -1, hi = k - 1;
  while (hi - lo > 1) {
    long long mid = hi + lo >> 1;
    if (check(mid))
      hi = mid;
    else
      lo = mid;
  }
  cout << hi;
  return 0;
}
