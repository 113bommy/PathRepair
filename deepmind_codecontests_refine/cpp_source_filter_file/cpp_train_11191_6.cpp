#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
long double PI = 4 * atan(1);
double x, b, a, ans = 1e9;
int l, r, mid;
double bin() {
  while (l < r) {
    mid = (l + r) / 2;
    if (x / (2 * mid) >= b) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return 2 * (l - 1);
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> a >> b;
  l = 0, r = 1000000000, x = a + b;
  if (bin() > 0) ans = min(ans, (double)x / (double)bin());
  l = 0, r = 1000000000, x = a - b;
  if (bin() > 0) ans = min(ans, (double)x / (double)bin());
  if (ans == 1e9) {
    cout << fixed << setprecision(10) << -1;
  } else {
    cout << fixed << setprecision(10) << ans;
  }
  return 0;
}
