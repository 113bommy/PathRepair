#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(void) {
  cin.tie(0)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int b, p, f, h, c;
    cin >> b >> p >> f >> h >> c;
    int ans = 0;
    if (c > h) {
      while (b > 1 && f > 0) {
        ans += c;
        f--;
        b -= 2;
      }
      while (b > 1 && p > 0) {
        ans += h;
        p--;
        b -= 2;
      }
    } else {
      while (b > 1 && p > 0) {
        ans += h;
        p--;
        b -= 2;
      }
      while (b > 1 && f > 0) {
        ans += c;
        f--;
        b -= 2;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
