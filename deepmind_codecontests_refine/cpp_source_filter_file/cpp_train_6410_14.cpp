#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const double g = 10.0, eps = 1e-7;
const int N = 1000 + 10, maxn = 500 + 100, inf = 0x3f3f3f;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, m, k, x, y;
  cin >> n >> m >> k >> x >> y;
  if (n == 1) {
    if (k % m == 0)
      cout << k / m << " " << k / m << " " << k / m << endl;
    else
      cout << k / m + 1 << " " << k / m << " "
           << (k % m >= y ? k / m + 1 : k / m) << endl;
    return 0;
  }
  if (n == 2) {
    long long s = k / (2 * m), p = k % (2 * m), ans;
    if (p >= (x - 1) * m + y)
      ans = s + 1;
    else
      ans = s;
    if (p == 0)
      cout << s << " " << s << " " << ans << endl;
    else
      cout << s + 1 << " " << s << " " << ans << endl;
    return 0;
  }
  long long s = k / ((2 * n - 2) * m), p = k % ((2 * n - 2) * m);
  long long maxx, minn, ans;
  if (m < p && p <= n * m)
    maxx = s * 2 + 1;
  else if (p <= m)
    maxx = s * 2;
  else if (p > n * m)
    maxx = s * 2 + 2;
  maxx = max(maxx, 1ll);
  if (p < n * m)
    minn = s;
  else
    minn = s + 1;
  if (x == 1) {
    if (p % m >= y)
      ans = s + 1;
    else
      ans = s;
  } else if (2 <= x && x <= n - 1) {
    if (p < (x - 1) * m + y)
      ans = s * 2;
    else if (p >= (x - 1) * m + y && p < (2 * n - x - 1) * m + y)
      ans = s * 2 + 1;
    else
      ans = s * 2 + 2;
  } else {
    if (p >= (n - 1) * m + y)
      ans = s + 1;
    else
      ans = s;
  }
  cout << maxx << " " << minn << " " << ans << endl;
  return 0;
}
