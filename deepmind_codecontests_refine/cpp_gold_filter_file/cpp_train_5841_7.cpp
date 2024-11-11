#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ax, ay, bx, by, cx, cy;
  cin >> ax >> ay >> bx >> by >> cx >> cy;
  if (bx < ax && cx < ax && by < ay && cy < ay)
    cout << "YES";
  else if (bx > ax && cx > ax && by > ay && cy > ay)
    cout << "YES";
  else if (bx > ax && cx > ax && by < ay && cy < ay)
    cout << "YES";
  else if (bx < ax && cx < ax && by > ay && cy > ay)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
