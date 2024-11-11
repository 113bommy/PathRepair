#include <bits/stdc++.h>
using namespace std;
int main() {
  double a1, a2, b1, b2, c1, c2, n1, n2;
  cin >> a1 >> b1 >> c1;
  cin >> a2 >> b2 >> c2;
  if ((!a1 && !b1 && c1) || (!b2 && !a2 && c2))
    cout << 0 << endl;
  else if ((!a1 && !b1 && !c1) || (!b2 && !a2 && !c2))
    cout << -1 << endl;
  else if (a1 * b2 != a2 * b1)
    cout << 1 << endl;
  else {
    if (a1 == 0 && b1 != 0)
      n1 = -1 * c1 / b1;
    else
      n1 = -1 * c1 / a1;
    if (a2 == 0 && b2 != 0)
      n2 = -1 * c2 / b2;
    else
      n2 = -1 * c2 / a2;
    if (n1 == n2)
      cout << -1 << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}
