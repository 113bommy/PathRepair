#include <bits/stdc++.h>
using namespace std;
const long long mx = 2e9, mx2 = 2e18;
long long calc(long long x, long long y) {
  return ((1LL << x) - 1) * y + y * (y - 1) / 2;
}
long long eval(long long n, long long x) {
  long long low = 0, high = mx, mid = -1;
  while (low <= high) {
    mid = (low + high) / 2;
    long long cur = calc(x, mid);
    if (cur < n)
      low = mid + 1;
    else if (cur > n)
      high = mid - 1;
    else
      return mid;
  }
  return -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  bool ok = false;
  for (long long x = 0; (1LL << x) < mx2; x++) {
    long long y = eval(n, x);
    for (long long z = 1; z < 1e6; z += 2)
      if (calc(x, z) == n) {
        y = z;
        break;
      }
    if (y != -1 && y % 2) {
      ok = true;
      cout << (1LL << x) * y << endl;
    }
  }
  if (!ok) cout << -1 << endl;
  return 0;
}
