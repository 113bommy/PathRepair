#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000LL * 1000 * 1000 + 7;
const int INF = 1e9;
const int BASE = 1e9;
const int MAX = 200002;
const double EPS = 1e-9;
const double PI = acos(-1.);
long long pow(long long x) {
  long long xx = x;
  for (int i = (0); i < (4); ++i) {
    x *= xx;
    x %= 100000;
  }
  return x % 100000;
}
int main() {
  double a, b, c;
  cin >> a >> b >> c;
  double res = 0;
  res += sqrt(2.) / 4. * a * a * a;
  res += b * b * b / sqrt(2.);
  a = c;
  res += (5. * a * a * tan(54. / 180. * PI) / 4.) *
         sqrt(a * a - (a * a) / (4. * sin(PI / 5.) * sin(PI / 5.)));
  cout << fixed << setprecision(6) << res / 3. << endl;
  return 0;
}
