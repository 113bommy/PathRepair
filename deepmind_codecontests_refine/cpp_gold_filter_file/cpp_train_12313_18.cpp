#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, x, y, num;
  double tmp, b;
  cin >> a >> x >> y;
  tmp = (double)y / a;
  num = y / a;
  if (fabs(tmp - num) < 1e-7) {
    cout << -1;
    return 0;
  } else {
    b = (double)a / 2;
    if (num == 0 || num % 2 == 1) {
      if ((x < 0 && x <= -b) || (x > 0 && x >= b)) {
        cout << -1;
        return 0;
      } else {
        if (num == 0 || num == 1)
          cout << num + 1;
        else {
          num = (num / 2) * 2 + (num - (num / 2));
          cout << num + 1;
          return 0;
        }
      }
    } else {
      if ((fabs(x) >= a) || (x == 0)) {
        cout << -1;
        return 0;
      } else {
        num = (num / 2 - 1) * 2 + (num + 1 - num / 2);
        if (x < 0)
          cout << num + 1;
        else
          cout << num + 2;
      }
    }
  }
  return 0;
}
