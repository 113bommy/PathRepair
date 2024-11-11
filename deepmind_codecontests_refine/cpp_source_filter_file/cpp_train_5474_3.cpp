#include <bits/stdc++.h>
using namespace std;
long long x, y, p, q;
int check(long long mul) {
  long long np = p * mul;
  long long nq = q * mul;
  if (np >= x && nq >= y && (nq - y >= np - x)) return true;
  return false;
}
void solve() {
  cin >> x >> y >> p >> q;
  if (!x && !p) {
    cout << 0 << '\n';
    return;
  }
  if (!!x && !p) {
    cout << -1 << '\n';
    return;
  }
  long long lo = 0, hi = (long long)(1e9);
  long long res = -1;
  while (lo + 1 < hi) {
    long long mid = lo + (hi - lo) / 2;
    if (check(mid)) {
      res = mid;
      hi = mid;
    } else {
      lo = mid;
    }
  }
  if (res == -1)
    cout << -1 << '\n';
  else {
    long long nq = q * res;
    cout << nq - y << '\n';
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
