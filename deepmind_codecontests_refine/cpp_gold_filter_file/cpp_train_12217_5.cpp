#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long l, r;
  cin >> l >> r;
  long long a, b, ans = 0;
  a = ((l + 10) / 10);
  b = ((r) / 10);
  if (a < b) {
    ans += b - a;
  }
  if (l < 10 && r < 10) {
    ans = r - l + 1;
    cout << ans;
    return 0;
  } else if (l < 10) {
    ans += 10 - l;
  } else {
    long long lx = l;
    while (lx >= 10) lx /= 10;
    if (l / 10 * 10 + lx >= l && l / 10 * 10 + lx <= r) ans++;
  }
  long long rx = r;
  while (rx >= 10) rx /= 10;
  if (r / 10 * 10 + rx <= r && r / 10 * 10 + rx > l) ans++;
  cout << ans;
  return 0;
}
