#include <bits/stdc++.h>
using namespace std;
int main() {
  int g1, g2, b1, b2;
  cin >> g1 >> g2 >> b2 >> b1;
  if ((b1 >= g1 && g1 * 2 + 2 >= b1) || (g1 > b1 && g1 <= b1 + 1) ||
      (b2 >= g2 && g2 * 2 + 2 >= b2) || (g2 > b2 && g2 <= b2 + 1))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
