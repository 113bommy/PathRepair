#include <bits/stdc++.h>
using namespace std;
struct cmp {
  bool operator()(long long a, long long b) { return (a > b); }
};
long long ceil(const long long &a, const long long &b) {
  if (a % b == 0) return a / b;
  return a / b + 1;
}
long long mod = 1000000007;
const long long N = 100005;
long long x, y, p, q, c;
bool solve(long long k) {
  long long z = p * k;
  long long z1 = (q - p) * k;
  if (z < x)
    return false;
  else if (z1 < (y - x))
    return false;
  else
    return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    cin >> x >> y >> p >> q;
    c = p * y - x * q;
    long long l = -1, r = 1e9;
    long long f = 0;
    while (l + 1 < r) {
      long long mid = l + (r - l) / 2;
      if (solve(mid)) {
        f = 1;
        r = mid;
      } else {
        l = mid;
      }
    }
    if (!f || !solve((long long)1e9)) {
      if (p == 0 && x == 0) {
        cout << 0;
      } else {
        cout << -1;
      }
    } else {
      long long ans = r * q - y;
      cout << ans;
    }
    cout << '\n';
    ;
  }
  return 0;
}
