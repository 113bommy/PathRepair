#include <bits/stdc++.h>
using namespace std;
const long long NR = 2e5 + 1e2;
const long long oo = 1e16 + 100;
const long long MOD = 1e9 + 7;
const long long MOD2 = 1e9 + 9;
double a[NR], b[NR], p;
int n;
bool ok(double x) {
  double sec = 0;
  for (int i = 1; i <= n; ++i) {
    sec += max((double)0, (a[i] * x - b[i])) / p;
  }
  return sec <= x;
}
signed main() {
  long long i;
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> p;
  double sum = 0;
  for (i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
    sum += a[i];
  }
  if (sum <= p) {
    cout << "-1\n";
    return 0;
  }
  double st, dr, mid, sol = 0;
  st = 0;
  dr = 1e18;
  for (i = 1; i <= 300; ++i) {
    mid = (st + dr) / 2;
    if (ok(mid)) {
      sol = mid;
      st = mid;
    } else {
      dr = mid;
    }
  }
  cout << setprecision(10) << fixed << sol << '\n';
  return 0;
}
