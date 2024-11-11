#include <bits/stdc++.h>
using namespace std;
long long n, flag, tx, ty, a, ans;
bool check(long long t) {
  long long sum = t * (t + 1) * 2 + 1, x, y, z;
  x = t - tx + 1;
  if (x > 0) sum -= x * (x + 1) / 2 + (x - 1) * x / 2;
  x = t - ty + 1;
  if (x > 0) sum -= x * (x + 1) / 2 + (x - 1) * x / 2;
  x = t + tx - n;
  if (x > 0) sum -= x * (x + 1) / 2 + (x - 1) * x / 2;
  x = t + ty - n;
  if (x > 0) sum -= x * (x + 1) / 2 + (x - 1) * x / 2;
  x = t - tx + 1, y = n - ty + 1, z = x - y;
  if (z > 0) sum += z * (z + 1) / 2;
  x = t - ty + 1, y = tx, z = x - y;
  if (z > 0) sum += z * (z + 1) / 2;
  x = t + tx - n, y = ty, z = x - y;
  if (z > 0) sum += z * (z + 1) / 2;
  x = t + ty - n, y = n - tx + 1, z = x - y;
  if (z > 0) sum += z * (z + 1) / 2;
  if (sum >= a) return 1;
  return 0;
}
signed main() {
  cin >> n >> tx >> ty >> a;
  long long l = 0, r = n * 2 + 1;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (check(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  cout << ans;
}
