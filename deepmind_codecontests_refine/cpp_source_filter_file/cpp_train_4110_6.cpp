#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, mish = 0, vas = 0;
  cin >> a >> b >> c >> d;
  mish = max(((3 * a) / 10), (a - ((a / 250) * c)));
  vas = max(((3 * b) / 10), (b - ((b / 250) * d)));
  if (mish > vas)
    cout << "Misha" << endl;
  else if (vas < mish)
    cout << " Vasya" << endl;
  else
    cout << "Tie" << endl;
  return 0;
}
