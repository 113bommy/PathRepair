#include <bits/stdc++.h>
using namespace std;
double a, b, c, d, pr, sol;
int main(void) {
  cin >> a >> b >> c >> d;
  pr = (1 - a / b) * (1 - c / d);
  double p = pr;
  sol = a / b;
  for (int i = 1; i <= 100000; ++i) {
    sol += (a / b) * p;
    p *= pr;
  }
  cout << setprecision(10) << sol;
  return (0);
}
