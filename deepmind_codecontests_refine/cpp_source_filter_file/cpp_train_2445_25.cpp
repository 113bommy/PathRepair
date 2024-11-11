#include <bits/stdc++.h>
using namespace std;
long long A, B, n;
long long l, t, m;
long long res;
bool _check(long long r) {
  return (A + B * (r - 1) <= t) &&
         (A * (r - l + 1) + B * (r - 1 + l - 1) * (r - l + 1) / 2 <= m * t);
}
void _input() { cin >> l >> t >> m; }
void _solve() {
  long long x = l, y = m * t + l + 1, mid;
  while (x < y) {
    mid = (x + y) / 2;
    if (_check(mid))
      x = mid;
    else
      y = mid - 1;
    if (x + 1 == y) {
      if (_check(mid))
        x = y;
      else
        y = x;
    }
  }
  if (A + B * (x - 1) <= t)
    res = x;
  else
    res = -1;
}
void _output() { cout << res << '\n'; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> A >> B >> n;
  while (n--) {
    _input();
    _solve();
    _output();
  }
  return 0;
}
