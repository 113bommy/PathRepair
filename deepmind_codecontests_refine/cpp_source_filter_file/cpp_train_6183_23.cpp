#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
using namespace std;
void solve() {
  long double l, d, v, g, r;
  cin >> l >> d >> v >> g >> r;
  long double t1 = d / v, t2 = (l - d) / v, will = t1, cnt = 0;
  while (will >= r + g) {
    will -= r + g;
    ++cnt;
  }
  if (will <= g) {
    cout << fixed << setprecision(8) << t1 + t2;
  } else {
    cout << fixed << setprecision(8) << (r + g) * (cnt + 1) + t2;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
}
