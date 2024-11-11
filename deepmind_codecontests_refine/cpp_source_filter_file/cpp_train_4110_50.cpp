#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(0);
  int a, b, c, d, x, y;
  cin >> a >> b >> c >> d;
  x = max(((3 * a) / 10), ((a / 250) * c));
  y = max(((3 * b) / 10), ((b / 250) * d));
  if (x > y)
    cout << "Misha" << endl;
  else if (y > x)
    cout << "Vasya" << endl;
  else
    cout << "Tie" << endl;
}
