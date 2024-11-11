#include <bits/stdc++.h>
using namespace std;
long double a, h, d, eps = 0.000001;
int main() {
  cin >> d;
  for (a = 1; a <= 10; a++)
    for (h = 1; h <= 10; h++)
      if (abs(d - (a * h / (sqrt(4 * h * h + a * a)))) < eps) {
        cout << round(a) << " " << round(h);
        return 0;
      }
  return 0;
}
