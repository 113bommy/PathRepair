#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int mmax = max(((3 * a) / 100), (a - ((a / 250) * c)));
  int vmax = max(((3 * b) / 100), (b - ((b / 250) * d)));
  if (mmax > vmax)
    cout << "Misha" << endl;
  else if (vmax > mmax)
    cout << "Vasya" << endl;
  else
    cout << "Tie" << endl;
  return 0;
}
