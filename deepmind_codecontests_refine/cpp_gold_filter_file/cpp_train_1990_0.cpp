#include <bits/stdc++.h>
using namespace std;
long long n, l, r, k;
inline bool check(long long y) {
  if (y > n || y < 0) return false;
  long long y1min, y1max, ost;
  ost = k % (n + y);
  y1min = y - min(n - r, y) - 1;
  y1max = min(r, y);
  if (y1min <= ost && ost <= y1max) {
    cout << y << endl;
    return true;
  }
  return false;
}
int main() {
  cin >> n >> l >> r >> k;
  r = (r + n - l) % n + 1;
  k -= r;
  if (k < 0) {
    cout << -1 << endl;
    return 0;
  }
  if (check(n - r + k + 1)) return 0;
  if (check(n - r + k)) return 0;
  if (n < 1e7) {
    for (long long y = n; y >= 0; --y)
      if (check(y)) return 0;
    cout << -1 << endl;
    return 0;
  }
  for (long long z = 1; k >= n; ++z) {
    k -= n;
    long long y2 = min(n - r, k / z);
    long long y1 = min(r, (k + 1 - z * y2) / (z + 1));
    long long dy = min(y2, r - y1);
    long long left = z * (y2 + y1) + y1;
    if (left - (y1 ? 1 : 0) == k || left == k || dy >= k - left) {
      cout << y1 + y2 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
