#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  double x;
  cin >> x;
  for (double a = 1; a <= x; ++a) {
    for (int i = 1; a * i <= x; ++i) {
      double b = a * i;
      if (a * b > x && a / b < x) {
        cout << a << " " << b;
        return 0;
      }
    }
  }
  cout << -1;
  return 0;
}
