#include <bits/stdc++.h>
using namespace std;
int main() {
  int x1, x2, x3, y1, y2, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  if (x1 == x2 && x2 == x3)
    cout << "1";
  else if (y1 == y2 && y2 == y3)
    cout << "1";
  else if (x1 == x2 || x2 == x3 || y1 == y2 || y2 == y3 || x1 == x3 ||
           y1 == y3) {
    vector<int> v(3), p(3);
    v[0] = x1, v[1] = x2, v[2] = x3, p[0] = y1, p[1] = y2, p[2] = y3;
    sort(p.begin(), p.end());
    sort(v.begin(), v.end());
    if (x1 == x2 && (y3 == p[0] || y3 == p[2]))
      cout << "2";
    else if (x1 == x3 && (y2 == p[0] || y2 == p[2]))
      cout << "2";
    else if (x2 == x3 && (y1 == p[0] || y1 == p[2]))
      cout << "2";
    else if (y1 == y3 && (x2 == v[0] || x2 == v[2]))
      cout << "2";
    else if (y1 == y2 && (x3 == v[0] || x3 == v[2]))
      cout << "2";
    else if (y2 == y3 && (x1 == v[0] || x1 == v[2]))
      cout << "2";
    else
      cout << "3";
  } else
    cout << "3";
  return 0;
}
