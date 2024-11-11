#include <bits/stdc++.h>
using namespace std;
int main() {
  int ax, ay, bx, by, cx, cy;
  int n;
  cin >> n;
  cin >> ax >> ay >> bx >> by >> cx >> cy;
  int flag = (cx - ax) * (bx - ax) * (by - ay) * (cy - ay) > 0 ? 1 : 0;
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
