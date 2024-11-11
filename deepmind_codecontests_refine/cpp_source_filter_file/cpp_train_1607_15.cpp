#include <bits/stdc++.h>
using namespace std;
const int oo = 999999999;
const double PI = 3.1415931;
const double eps = 1e-9;
int main() {
  ios::sync_with_stdio(false);
  int x1, x2, x3, y1, y2, y3;
  cin >> x1 >> x2 >> x3 >> y1 >> y2 >> y3;
  int tk = fabs(x1 - y1) + fabs(x2 - y2) + fabs(x3 - y3);
  if (tk <= 1)
    cout << "YES";
  else
    cout << "NO";
  cout << endl;
  ;
  return 0;
}
