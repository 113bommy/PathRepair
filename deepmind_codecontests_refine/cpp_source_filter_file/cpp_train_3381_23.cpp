#include <bits/stdc++.h>
using namespace std;
int x, y;
int main() {
  int d;
  cin >> x >> y >> d;
  if (x == 0 && y == 0 && d == 2)
    cout << "Yes" << endl;
  else if (((abs(x) + abs(y)) > d && (d - abs(x) + abs(y)) == 2))
    cout << "Yes" << endl;
  else if (abs(x) + abs(y) == d)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
