#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, b, c, d;
  cin >> a >> b >> c >> d;
  printf("%.8lf\n", (1 / b) / (1.0 - ((1.0 - (a / b)) * (1.0 - (c / d)))));
  return 0;
}
