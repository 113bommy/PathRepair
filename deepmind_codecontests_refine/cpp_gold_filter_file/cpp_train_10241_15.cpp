#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int N = 1e6 + 1, mod = 1e9 + 7;
int n, v[N], x[N];
bool check(double t) {
  double mn = 1e19;
  for (int i = n; i >= 1; i--) {
    if (v[i] < 0) {
      mn = min(mn, t * v[i] + x[i]);
    } else if (mn <= t * v[i] + x[i]) {
      return 1;
    }
  }
  return 0;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> v[i];
  }
  double l = 0, r = 1e9 + 1, ans = -1;
  int inter = 100;
  while (inter--) {
    double mid = (l + r) / 2;
    if (check(mid)) {
      r = mid;
      ans = r;
    } else {
      l = mid;
    }
  }
  cout << fixed << setprecision(9) << ans;
}
