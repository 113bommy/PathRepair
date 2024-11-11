#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, p, r;
  cin >> a >> b >> c >> d;
  p = max((3 * a) / 10, a - (a / 250) * c);
  r = max((3 * b) / 10, b - (b / 250) * d);
  if (p == r)
    cout << "Tie" << endl;
  else if (p < r)
    cout << "Vasya" << endl;
  else
    cout << "Misha" << endl;
  return 0;
}
