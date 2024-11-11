#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d, x, y;
  cin >> a >> b >> c >> d;
  x = max(3 * a / 10, a - a / 250 * c);
  y = max(3 * b / 10, b - b / 250 * d);
  if (x > y)
    cout << "Misha";
  else if (y > x)
    cout << "Vasya";
  else
    cout << "Tie";
  return 0;
}
