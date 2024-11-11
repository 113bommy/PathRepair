#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  double x;
  cin >> x;
  for (double b = 1; b <= x; ++b) {
    for (int i = 1; b * i <= x; ++i) {
      double a = b * i;
      if (a * b > x && a / b < x) {
        cout << a << " " << b;
        return 0;
      }
    }
  }
  cout << -1;
  return 0;
}
