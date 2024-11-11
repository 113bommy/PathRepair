#include <bits/stdc++.h>
using namespace std;
int main() {
  double x, h;
  cin >> x >> h;
  double h_1 = sqrt(h * h / x);
  cout << fixed << setprecision(5) << h_1 << " ";
  for (int i = 1; i <= x - 2; i++) {
    cout << fixed << setprecision(5) << sqrt(h * h / x + h_1 * h_1) << " ";
    h_1 = sqrt(h * h / x + h_1 * h_1);
  }
}
