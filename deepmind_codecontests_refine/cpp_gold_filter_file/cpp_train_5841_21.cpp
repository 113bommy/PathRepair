#include <bits/stdc++.h>
using namespace std;
int bx, by, cx, cy;
int main() {
  int n;
  cin >> n;
  int ax, ay;
  cin >> ax >> ay;
  cin >> bx >> by;
  cin >> cx >> cy;
  int t = (ax - bx) * (ax - cx);
  int s = (ay - by) * (ay - cy);
  if (t > 0 && s > 0)
    cout << "YES";
  else
    cout << "NO";
}
