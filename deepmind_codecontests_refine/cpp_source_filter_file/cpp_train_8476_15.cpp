#include <bits/stdc++.h>
using namespace std;
int main() {
  double a = 3, h = 2, X;
  cin >> X;
  bool has = false;
  for (int i = 1; i <= 10; ++i) {
    for (int j = 1; j <= 10; ++j) {
      a = i;
      h = j;
      double S = 4 * a / 2 * sqrt(h * h + a * a / 4);
      double V = a * a * h;
      if (fabs(V - X * S) < 1e-6) {
        printf("%d %d\n", i, j);
        return 0;
      }
    }
  }
}
