#include <bits/stdc++.h>
using namespace std;
int main() {
  double l1, l2, l3;
  cin >> l1 >> l2 >> l3;
  double k1 = 1 / 12.0;
  double k2 = 1 / (sqrt(2.0) * 3.0);
  double k3 = (38.546168065709 - 8 * k1 - 125 * k2) / 27.0;
  cout.precision(20);
  cout << fixed << k1 * l1 * l1 * l1 + k2 * l2 * l2 * l2 + k3 * l3 * l3 * l3
       << endl;
  return 0;
}
