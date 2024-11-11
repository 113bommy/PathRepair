#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  long double a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << setprecision(12) << fixed
       << (a / b) / (1.0 - (b - a) * (d - c) / (b * d)) << endl;
  return 0;
}
