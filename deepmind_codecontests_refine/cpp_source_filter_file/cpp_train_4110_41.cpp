#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  long long misha, vashia;
  long long x, y;
  x = (3 * a) / 10;
  y = a - ((a / 250) * c);
  misha = max(x, y);
  x = (3 * b) / 10;
  y = b - ((b / 250) * d);
  vashia = max(x, y);
  if (misha > vashia)
    cout << "Maisha" << endl;
  else if (vashia > misha)
    cout << "vasya" << endl;
  else
    cout << "Tie" << endl;
  return 0;
}
