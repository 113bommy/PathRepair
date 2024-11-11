#include <bits/stdc++.h>
using namespace std;
int main() {
  double ax, ay, bx, by, cx, cy, pro;
  cin >> ax >> ay >> bx >> by >> cx >> cy;
  pro = (bx - ax) * (cy - by) - (cx - bx) * (by - ay);
  if (pro == 0)
    cout << "TOWARDS";
  else if (pro < 0)
    cout << "RIGHT";
  else
    cout << "LEFT";
  return 0;
}
