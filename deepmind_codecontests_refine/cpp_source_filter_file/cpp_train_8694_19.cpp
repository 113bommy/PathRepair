#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6 + 123;
const long long INF = (long long)1e18 + 123;
const int inf = (int)1e9 + 123;
const double eps = 1e-6;
inline void boost() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
}
double a, b, c, x[5];
int main() {
  boost();
  cin >> a >> b >> c;
  double delta = b * b - 4.0 * (a * c);
  x[0] = (-b + sqrt(delta)) / (2.0 * a);
  x[1] = (-b - sqrt(delta)) / (2.0 * a);
  sort(x, x + 1);
  reverse(x, x + 1);
  cout << fixed << setprecision(6) << x[0] << endl << setprecision(6) << x[1];
  return 0;
}
