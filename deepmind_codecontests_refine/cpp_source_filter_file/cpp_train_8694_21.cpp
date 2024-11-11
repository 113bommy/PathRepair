#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  long double a, b, c;
  cin >> a >> b >> c;
  b = b / a;
  c = c / a;
  long double root = sqrt(b * b - 4. * a * c);
  long double r;
  if (b > 0)
    r = (-b - root) / 2.;
  else
    r = (-b + root) / 2;
  cout.precision(18);
  cout << max(r, c / r) << endl << min(r, c / r) << endl;
  return 0;
}
