#include <bits/stdc++.h>
using namespace std;
long double pi = 3.141592653589793238462643383;
int main() {
  long double n, r;
  cin >> n >> r;
  long double ans =
      1.0 * n * r * r * 1.0 /
      (1.0 / (1.0 * tan(pi / (2.0 * n))) + 1.0 / (1.0 * tan(pi / n)));
  cout << fixed << setprecision(15) << ans << endl;
  return 0;
}
