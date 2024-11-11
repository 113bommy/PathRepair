#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, y, k;
  cin >> n >> x >> y >> k;
  if (n == 1) return cout << 1, 0;
  bool flag = false;
  if (x <= y)
    x = y - x + 1, y = n - x;
  else
    x = n + 1 - x + y, y = n - x;
  if (k < x) return cout << -1, 0;
  if (n <= 10000) {
    int ans = 0;
    for (int i = 0; i <= x; ++i)
      for (int j = 0; j <= y; ++j)
        if (k % (n + i + j) == (x + i) % (n + i + j) ||
            (i && k % (n + i + j) == (x + i - 1) % (n + i + j))) {
          ans = max(ans, i + j);
          flag = true;
        }
    if (!flag)
      puts("-1");
    else
      cout << ans;
  } else {
    long long ans = 0;
    int l = k / (2 * n) - 1, r = k / n;
    if (k <= 2 * x) {
      if (k == 2 * x)
        ans = n;
      else
        ans = n - (2 * x - k) + 1;
      flag = true;
    }
    for (int t = max(1, l); t <= r; ++t) {
      long long a = 1, b = -1;
      long long s = k - y * t - x - x * t;
      a *= s, b *= s;
      if (a < 0) {
        long long tmp = (a + 1) / t - 1;
        a -= tmp * t, b += tmp * (t + 1);
      }
      if (b < 0) {
        long long tmp = (b + 1) / (t + 1) - 1;
        b -= tmp * (t + 1), a += tmp * t;
      }
      if (b > y) {
        long long tmp = (b - y - 1) / (t + 1) + 1;
        b -= tmp * (t + 1), a += tmp * t;
      }
      if (a > x) {
        long long tmp = (a - x - 1) / t + 1;
        a -= tmp * t, b += tmp * (t + 1);
      }
      if (a >= 0 && b >= 0 && a <= x && b <= y) {
        long long tmp = min(a / t, (y - b) / (t + 1));
        a -= tmp * t, b += tmp * (t + 1);
        flag = true, ans = max(ans, a + b);
      }
    }
    ++k, l = k / (2 * n) - 1, r = k / n;
    for (int t = max(1, l); t <= r; ++t) {
      long long a = 1, b = -1;
      long long s = k - y * t - x - x * t;
      if (s == 0) continue;
      a *= s, b *= s;
      if (a < 0) {
        long long tmp = a / t - 1;
        a -= tmp * t, b += tmp * (t + 1);
      }
      if (b < 0) {
        long long tmp = (b + 1) / (t + 1) - 1;
        b -= tmp * (t + 1), a += tmp * t;
      }
      if (b > y) {
        long long tmp = (b - y - 1) / (t + 1) + 1;
        b -= tmp * (t + 1), a += tmp * t;
      }
      if (a > x) {
        long long tmp = (a - x - 1) / t + 1;
        a -= tmp * t, b += tmp * (t + 1);
      }
      if (a > 0 && b >= 0 && a <= x && b <= y) {
        long long tmp = min((a - 1) / t, (y - b) / (t + 1));
        a -= tmp * t, b += tmp * (t + 1);
        flag = true, ans = max(ans, a + b);
      }
    }
    if (!flag)
      puts("-1");
    else
      cout << ans;
  }
  return 0;
}
