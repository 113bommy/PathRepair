#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, x1, x2, y1, y2;
  cin >> a >> b >> x1 >> y1 >> x2 >> y2;
  int t1, t2;
  if (x1 >= y1)
    t1 = (x1 - y1) / (2 * b);
  else
    t1 = -(1 + (y1 - x1) / (2 * b));
  if (x2 >= y2)
    t2 = (x2 - y2) / (2 * b);
  else
    t2 = -(1 + (y2 - x2) / (2 * b));
  int ans1 = abs(t1 - t2);
  if (x1 + y1 >= 0)
    t1 = (x1 + y1) / (2 * a);
  else
    t1 = -(1 + (y1 + x1) / (2 * a));
  if (x2 + y2 >= 0)
    t2 = (x2 + y2) / (2 * a);
  else
    t2 = -(1 + (y2 + x2) / (2 * a));
  int ans2 = abs(t1 - t2);
  cout << max(ans1, ans2) << endl;
}
