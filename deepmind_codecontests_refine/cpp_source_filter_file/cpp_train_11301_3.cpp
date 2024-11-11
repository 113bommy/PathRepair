#include <bits/stdc++.h>
using namespace std;
long long ans, l, r, a, b, k, x;
int main() {
  cin >> l >> r >> a >> b >> k;
  if (a >= r || l >= b) {
    if (a == r) {
      ans++;
      if (k == r) ans--;
    }
    if (l == b) {
      ans++;
      if (k == b) ans--;
    }
    cout << ans;
    return 0;
  }
  if (l == a && r == b) {
    ans = r - l + 1;
    if (l <= k && k <= r) ans--;
    cout << ans;
    return 0;
  }
  ans = max(r - a, x);
  if (r > b) ans = max(b - l, x);
  if (r < b && a < l) {
    ans = r - l + 1;
    if (r >= k && k >= l) ans--;
    cout << ans;
    return 0;
  }
  if (b < r && l < a) {
    ans = b - a + 1;
    if (b >= k && k >= a) ans--;
    cout << ans;
    return 0;
  }
  if (ans == r - a && ans != b - l && r >= k && a <= k) ans--;
  if (ans == b - l && ans != r - a && b >= k && l <= k) ans--;
  if (ans < 0) ans = 0;
  cout << ans + 1;
}
