#include <bits/stdc++.h>
using namespace std;
int main(void) {
  double a, b, c, d;
  cin >> a >> b >> c >> d;
  double p1 = a / b, p11 = p1, p2 = c / d;
  double res = p1;
  for (int i = 0; i < 100; i++) {
    res += (1 - p11) * (1 - p2) * p1;
    p11 = 1 - (1 - p11) * (1 - p2) * (1 - p1);
  }
  cout << setprecision(9) << res << endl;
  return 0;
}
