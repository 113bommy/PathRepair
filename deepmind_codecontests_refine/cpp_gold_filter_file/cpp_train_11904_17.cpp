#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-1;
const double PI = 3.1415926535897932384626433832795;
long long i64INF = 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL;
long long i32INF = 1000 * 1000 * 1000;
long long mod = 1000000007;
int main() {
  double s, a, b, c;
  cin >> s >> a >> b >> c;
  if (a < EPS && b < EPS && c < EPS) {
    cout << "0.00 0.00 0.00" << endl;
    return 0;
  }
  double x = a * s / (a + b + c);
  double y = b * s / (a + b + c);
  double z = c * s / (a + b + c);
  printf("%0.19lf %0.19lf %0.19lf\n", x, y, z);
  return 0;
}
