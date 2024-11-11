#include <bits/stdc++.h>
using namespace std;
int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int d1 = max(x1, y1);
  int d2 = x2 + y2;
  if ((x1 <= x2 && y1 <= y2) || d2 <= d1) {
    cout << "Polycarp" << endl;
    return 0;
  }
  {
    cout << "Vasiliy" << endl;
    return 0;
  }
  return 0;
}
