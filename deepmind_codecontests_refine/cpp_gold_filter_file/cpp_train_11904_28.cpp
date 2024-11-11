#include <bits/stdc++.h>
using namespace std;
int main() {
  long long s, a, b, c;
  cin >> s;
  cin >> a >> b >> c;
  long long r = a + b + c;
  if (r == 0) {
    cout << "0.0 0.0 0.0" << endl;
    return 0;
  }
  double x = double(a * s) / double(r);
  double y = double(b * s) / double(r);
  double z = double(c * s) / double(r);
  cout << setiosflags(ios::showpoint | ios::fixed) << setprecision(15) << x
       << ' ' << y << ' ' << z << endl;
  return 0;
}
