#include <bits/stdc++.h>
using namespace std;
double n, v[1000009 * 2];
double f(double x) {
  double ans = 0, sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += v[i] - x;
    ans = max(sum, ans);
    if (sum < 0) sum = 0;
  }
  sum = 0;
  double ans1 = 1000000009;
  for (int i = 1; i <= n; i++) {
    sum += v[i] - x;
    ans1 = min(sum, ans1);
    if (sum > 0) sum = 0;
  }
  return max(abs(ans1), ans);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> v[i];
  double l = -10000, r = 10000;
  for (int i = 1; i <= 100; i++) {
    double m1 = l + (r - l) / 3;
    double m2 = r - (r - l) / 3;
    if (f(m1) < f(m2))
      r = m2;
    else
      l = m1;
  }
  printf("%.6lf", f(l));
}
