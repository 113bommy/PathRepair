#include <bits/stdc++.h>
using namespace std;
const int INF = 20050226;
long long n, c, x, y;
bool check(long long val) {
  long long total = 1 + 2ll * val * (val + 1);
  total -= min(x - 1 - val, 0ll) * min(x - 1 - val, 0ll);
  total -= min(y - 1 - val, 0ll) * min(y - 1 - val, 0ll);
  total -= min(n - (x + val), 0ll) * min(n - (x + val), 0ll);
  total -= min(n - (y + val), 0ll) * min(n - (y + val), 0ll);
  total += min(x - 1 + y - 1 - val + 1, 0ll) *
           (min(x - 1 + y - 1 - val + 1, 0ll) - 1) / 2;
  total += min(x - 1 + n - y + -val + 1, 0ll) *
           (min(x - 1 + n - y - val + 1, 0ll) - 1) / 2;
  total += min(n - x + n - y - val + 1, 0ll) *
           (min(n - x + n - y - val + 1, 0ll) - 1) / 2;
  total += min(n - x + y - 1 - val + 1, 0ll) *
           (min(n - x + y - 1 - val + 1, 0ll) - 1) / 2;
  return total >= c;
}
int main() {
  cin >> n >> x >> y >> c;
  long long l = -1, r = (long long)x * y;
  while (l + 1 < r) {
    long long mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  cout << r;
}
