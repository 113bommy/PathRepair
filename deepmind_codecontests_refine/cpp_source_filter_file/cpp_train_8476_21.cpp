#include <bits/stdc++.h>
using namespace std;
int main() {
  long double x;
  cin >> x;
  for (long double a = 1; a <= 10; a++)
    for (long double b = 1; b <= 10; b++) {
      if (abs(a / 2 * b / sqrt(a * a / 4 + b * b) - x) < 1e5) {
        cout << a << " " << b;
        return 0;
      }
    }
  return 0;
}
