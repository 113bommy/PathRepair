#include <bits/stdc++.h>
using namespace std;
int main() {
  double x;
  cin >> x;
  for (int i = (0); i < (11); i++) {
    for (int j = (0); j < (11); j++) {
      double a = i;
      double b = j;
      a /= 2;
      double v = a * b / sqrt(a * a + b * b);
      if (abs(v - x) <= 0.00001) {
        cout << i << " " << j << endl;
        return 0;
      }
    }
  }
  return 0;
}
