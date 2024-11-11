#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  for (int test = 0; test < T; test++) {
    double a, b;
    cin >> a >> b;
    double res;
    if (b == 0 && a != 0) {
      res = 1.0;
    } else if (b == 0 && a == 0) {
      res = .0;
    } else if (4 * b < a) {
      res = 1.0 - b / a;
    } else {
      res = .5 + a / b / 16.0;
    }
    printf("%1.10lf\n", res);
  }
  return 0;
}
