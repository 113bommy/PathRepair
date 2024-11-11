#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d, x, y;
  cin >> a >> b >> c >> d;
  x = max(3 * a / 10, a - b / 250 * x);
  y = max(3 * b / 10, b - b / 250 * y);
  if (x > y)
    cout << "Misha";
  else if (y > x)
    cout << "Vasya";
  else
    cout << "Tie";
  return 0;
}
