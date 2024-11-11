#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  long long rasst1, rasst2, rasst3;
  rasst1 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  rasst2 = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
  rasst3 = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
  if (rasst1 + rasst2 == rasst3) {
    if (x1 < x2) {
      if (y3 >= y2)
        cout << "LEFT" << endl;
      else
        cout << "RIGHT" << endl;
    } else if (x1 > x2) {
      if (y3 >= y2)
        cout << "RIGHT" << endl;
      else
        cout << "LEFT" << endl;
    } else {
      if (x3 > x2 && y2 > y1)
        cout << "RIGHT" << endl;
      else if (x3 > x2 && y2 < y1)
        cout << "LEFT" << endl;
      else if (x3 < x2 && y2 > y1)
        cout << "LEFT" << endl;
      else if (x3 < x2 && y2 < y1)
        cout << "RIGHT" << endl;
    }
  } else
    cout << "TOWARDS" << endl;
}
