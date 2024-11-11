#include <bits/stdc++.h>
using namespace std;
int n;
long double ans1[1000000];
long double ans2[1000000];
long double sa[1000000];
long double sb[1000000];
long double x1[1000000];
long double x[1000000];
long double sqr(long double x) { return x * x; }
long double sqrtt(long double x) {
  if (x < 0) return 0;
  return sqrt(x);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> x[i];
  for (int i = 1; i <= n; i++) cin >> x1[i];
  for (int i = 1; i <= 1; i++) {
    long double D = sqrtt(-4 * x[i] + sqr(x1[i] + x[i]));
    ans1[i] = (x1[i] + x[i] + D) / 2.;
    ans2[i] = x[i] / ans1[i];
    sa[i] = ans1[i];
    sb[i] = ans2[i];
  }
  for (int i = 2; i <= n; i++) {
    long double a = 1;
    long double b = sa[i - 1] - x[i] - sb[i - 1] - x1[i];
    long double c = x[i] - sa[i - 1] * x[i] - x1[i] * sa[i - 1];
    long double D = sqrtt(b * b - a * c * 4);
    ans1[i] = (-b + D) / 2.;
    ans2[i] = (x[i] - ans1[i] * sb[i - 1]) / (ans1[i] + sa[i - 1]);
    sa[i] = ans1[i] + sa[i - 1];
    sb[i] = ans2[i] + sb[i - 1];
  }
  cout.precision(9);
  for (int i = 1; i <= n; i++) cout << fixed << ans1[i] << ' ';
  cout << "\n";
  for (int i = 1; i <= n; i++) cout << fixed << ans2[i] << ' ';
  cout << "\n";
}
