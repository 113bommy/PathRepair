#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
int n;
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    double theta1 = PI / n, x = 0.5 / sin(0.5 * theta1),
           theta2 = PI / n * round(n / 4.0);
    printf("%.9lf\n", x / sin(PI / 4) * sin(theta2) +
                          x / sin(PI / 4) * sin(PI / 2 - theta2));
  }
  return 0;
}
