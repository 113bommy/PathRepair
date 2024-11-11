#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
double EPS = 1e-9;
int a, b, l;
long double f(long double x) { return (b + a * tan(x) - l * sin(x)) * cos(x); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> a >> b >> l;
  if (b > a) swap(a, b);
  if (l <= b) return cout << l, 0;
  if (b < l && l <= a) return cout << b, 0;
  long double s = 0, e = acos(-1) / 2;
  int cnt = 100;
  while (cnt--) {
    long double mid1 = (s + s + e) / 3;
    long double mid2 = (e + s + e) / 3;
    if (f(mid1) < f(mid2))
      e = mid2;
    else
      s = mid1;
  }
  long double ans = f(s);
  if (ans < EPS) return cout << "My poor head =(", 0;
  cout << fixed << setprecision(12) << ans;
  return 0;
}
