#include <bits/stdc++.h>
using namespace std;
int main() {
  long double a, b, c, d;
  cin >> a >> b >> c >> d;
  printf("%.18Lf\n", ((a / b) / (1.0 - (1.0 - a / b) * (1.0 - c / d))));
  return 0;
}
