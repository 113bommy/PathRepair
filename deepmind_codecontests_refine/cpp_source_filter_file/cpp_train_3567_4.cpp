#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, r1, r2, r3, d, a[N];
long long one_shot(int k) { return 1LL * k * r1 + r3; }
long long calc_min(int k) {
  return min(1LL * r2 + min({r1, r2, r3}),
             1LL * k * r1 + min(2 * min(r1, r2), r3));
}
void read_input() {
  cin >> n >> r1 >> r2 >> r3 >> d;
  for (int i = 0; i < n; i++) cin >> a[i];
}
void solve() {
  long long x = one_shot(a[0]), y = 1e18, z = 1e18;
  for (int i = 1; i < n; i++) {
    long long xx = x, yy = y, zz = z;
    z = min(zz, xx - one_shot(a[i - 1]) + calc_min(a[i - 1])) + 3 * d +
        calc_min(a[i]);
    y = min(yy, xx) + 2 * d + calc_min(a[i - 1]) + one_shot(a[i]) -
        one_shot(a[i - 1]);
    x = min({xx, zz}) + d + one_shot(a[i]);
  }
  cout << min({x, y, z});
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  read_input(), solve();
  return 0;
}
