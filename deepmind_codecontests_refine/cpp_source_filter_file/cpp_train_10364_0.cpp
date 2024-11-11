#include <bits/stdc++.h>
using namespace std;
int n, k;
double l, v1, v2;
double binser(double target) { return target / (v1 + v2); }
double msafa;
double solve(double start, double End, int students) {
  if (start >= End) {
    msafa = End;
    return 0;
  }
  if (students == 0) {
    msafa = min(start + 0.1, End);
    return min(0.1, End - start) / v2;
  }
  double t = binser(min(0.2, 2.0 * (End - start)));
  double r = solve(start + v1 * t, End, max(0, students - k));
  if (start == 0) return l / (msafa / (r + t));
  return r + t;
}
int main() {
  cin >> n >> l >> v1 >> v2 >> k;
  if (k == n) {
    cout << fixed << setprecision(7) << l / v2 << endl;
    return 0;
  }
  cout << fixed << setprecision(10) << solve(0, l, n - k) << endl;
  return 0;
}
