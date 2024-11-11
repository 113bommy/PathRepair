#include <bits/stdc++.h>
const int inf = (1ll << 31) - 1;
const int maxn = (int)1e5 + 10;
const int mod = (int)1e9 + 7;
using namespace std;
int n, m, x, y, c;
bool ok(int cur) {
  int x1 = max(x - cur, 1);
  int x2 = min(x + cur, n);
  long long ans = 0;
  for (int i = x1; i <= x2; i++) {
    int z1 = abs(i - x);
    int k1 = min(y + z1, n);
    int k2 = max(y - z1, 1);
    ans += k1 - k2 + 1;
  }
  return ans >= c;
}
int main() {
  cin >> n >> x >> y >> c;
  int l = 0, r = maxn;
  int ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (ok(mid)) {
      r = mid - 1;
      ans = mid;
    } else
      l = mid + 1;
  }
  cout << ans << endl;
  return 0;
}
