#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, b, c, d, p, r;
  cin >> a >> b >> c >> d;
  p = a / b;
  r = (a / b) * (1 - c / d);
  printf("%.15f", p / (1 - r));
  return 0;
}
