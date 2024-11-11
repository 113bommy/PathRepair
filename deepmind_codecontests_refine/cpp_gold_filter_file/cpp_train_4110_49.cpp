#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, b, c, d;
  cin >> a >> b >> c >> d;
  double val1 = max(3 * a / 10, a - a / 250 * c);
  double val2 = max(3 * b / 10, b - b / 250 * d);
  if (abs(val1 - val2) < 1e-9)
    cout << "Tie" << endl;
  else if (val1 > val2)
    cout << "Misha" << endl;
  else if (val2 > val1)
    cout << "Vasya" << endl;
  return 0;
}
