#include <bits/stdc++.h>
using namespace std;
const int _ = 1e5 + 29, yl = 1e9 + 7;
long long a[_], n, sum, ans, f[_], mx;
long long POW(long long x, long long y) {
  long long s = 1;
  while (y) {
    if (y & 1) s = s * x % yl;
    x = x * x % yl;
    y >>= 1;
  }
  return s;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i], sum += a[i];
  f[1] = (sum - 1) * (sum - 1) % yl * POW(sum, yl - 2) % yl;
  f[2] = (f[1] * 2 - 1) % yl;
  for (int i = 3; i <= 100000; ++i) {
    f[i] =
        (2 * f[i - 1] - f[i - 2] - (sum - 1) * POW(sum - i + 1, yl - 2)) % yl;
    if (f[i] < 0) f[i] += yl;
  }
  for (int i = 1; i <= n; ++i) ans += f[a[i]];
  cout << ans % yl << endl;
  return 0;
}
