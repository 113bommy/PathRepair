#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  if (x > 0 && y > 0)
    cout << "0 " << x + y << " " << x + y << " 0" << endl;
  else if (x < 0 && y < 0)
    cout << x + y << " 0 0 " << x + y << endl;
  else if (x < 0 && y > 0)
    cout << (x * (-1) + y) * (-1) << " 0 0 " << x * (-1) + y << endl;
  else if (x > 0 && y < 0)
    cout << "0 " << x * (-1) + y << " " << x + y * (-1) << endl;
  return 0;
}
