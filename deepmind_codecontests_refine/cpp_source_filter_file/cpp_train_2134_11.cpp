#include <bits/stdc++.h>
using namespace std;
using namespace std;
int main(int argc, char** argv) {
  int x, y, x1, y1, x2, y2;
  cin >> x >> y >> x1 >> y1 >> x2 >> y2;
  int z, c, v;
  bool f = false;
  int z1 = x - x1 - x2, z2 = x - y1 - y2, c1 = x - x1 - y2, c2 = x - x2 - y2,
      v1 = y - x1 - x2, v2 = y - y2 - y1, b1 = y - x2 - y1, b2 = y - x1 - y2;
  if ((z1 >= 0 && y1 <= y && y2 <= y))
    f = true;
  else if (z2 >= 0 && y >= x1 && x2 <= y)
    f = true;
  else if (c1 >= 0 && y >= x2 && y >= y1)
    f = true;
  else if (c2 >= 0 && y >= x1 && y >= y1)
    f = true;
  else if (v1 >= 0 && x >= y2 && x >= y1)
    f = true;
  else if (v2 >= 0 && x >= x1 && x >= x2)
    f = true;
  else if (b1 >= 0 && x >= x1 && x >= y2)
    f = true;
  else if (b2 >= 0 && x >= x2 && x >= y1)
    f = true;
  if (f == true)
    cout << "YES\n";
  else
    cout << "NO" << endl;
  return 0;
}
