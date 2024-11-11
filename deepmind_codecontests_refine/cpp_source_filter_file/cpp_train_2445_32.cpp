#include <bits/stdc++.h>
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int exp(long long int x, long long int y) {
  long long int res = 1;
  x = x % 1000000007;
  while (y > 0) {
    if (y & 1) res = (res * x) % 1000000007;
    y = y >> 1;
    x = (x * x) % 1000000007;
  }
  return res;
}
using namespace std;
const long long int inf = 0x3f3f3f3f3f3f3f3fll;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int a, b, q, l, m, t, r, mid, val, x;
  cin >> a >> b >> q;
  while (q--) {
    cin >> l >> t >> m;
    if (a + (l - 1) * b > t)
      cout << -1;
    else {
      x = l;
      r = 1e8;
      while (r >= l) {
        mid = (l + r) / 2;
        val = (mid - x + 1) +
              b * ((mid * (mid - 1) / 2) - ((x - 1) * (x - 2) / 2));
        if ((a + (mid - 1) * b <= t) && val <= m * t)
          l = mid + 1;
        else
          r = mid - 1;
      }
      cout << r;
    }
    cout << '\n';
  }
  return 0;
}
