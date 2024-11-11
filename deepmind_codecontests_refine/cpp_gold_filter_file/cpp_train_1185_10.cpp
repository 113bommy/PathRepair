#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, b, c, d;
  cin >> a >> b >> c >> d;
  printf("%.10lf\n", ((a / b) / (1.0 - (1.0 - a / b) * (1.0 - c / d))));
  return 0;
}
