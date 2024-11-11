#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long mod = 1e9 + 7;
const long long N = 1e6 + 10;
int main() {
  ios::sync_with_stdio(false);
  long long a, b, n;
  cin >> a >> b >> n;
  while (n--) {
    long long l, t, m;
    cin >> l >> t >> m;
    l--;
    if (a + l * b > t) {
      cout << -1 << endl;
      continue;
    }
    long long r = l;
    long long x = l, y = 2e6 + 65;
    while (x <= y) {
      long long mid = (x + y) / 2;
      long long cnt = mid - l + 1;
      if (a + mid * b <= t &&
          (mid - l + 1) * a + (mid * (mid + 1) / 2 - l * (l - 1) / 2) * b <=
              t * m) {
        r = mid;
        x = mid + 1;
      } else
        y = mid - 1;
    }
    cout << r + 1 << endl;
  }
  return 0;
}
