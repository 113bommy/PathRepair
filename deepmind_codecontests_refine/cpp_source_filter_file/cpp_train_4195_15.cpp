#include <bits/stdc++.h>
using namespace std;
int t;
long long a, b, c, d;
long long solve(long long x) {
  long long times = x / d + 1;
  long long sum = (x / d + 1) * a;
  long long finished;
  if (x < c) {
    finished = 0;
  } else {
    finished = (x - c) / d + 1;
  }
  long long left = times - finished;
  long long a1 = x - (x / d) * d;
  sum -= left * a1 * b + left * (left - 1) / 2 * d * b;
  sum -= finished * b * c;
  return sum;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> a >> b >> c >> d;
    if (d >= c) {
      if (a > b * c) {
        cout << -1 << endl;
      } else {
        cout << a << endl;
      }
    } else {
      if (a > b * c) {
        cout << -1 << endl;
      } else {
        long long l = 0, r = 1e9 / d;
        while (l < r - 5) {
          long long ml = (l + r) / 2;
          long long mr = (ml + r) / 2;
          if (solve(ml * d) <= solve(mr * d)) {
            l = ml;
          } else {
            r = mr;
          }
        }
        long long mx = 0;
        for (long long i = l; i <= r; i++) {
          mx = max(mx, solve(i * d));
        }
        cout << mx << endl;
      }
    }
  }
  return 0;
}
