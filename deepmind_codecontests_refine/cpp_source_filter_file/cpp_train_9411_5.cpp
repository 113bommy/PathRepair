#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  bool flag = 0;
  int by1, by2;
  int x, y;
  for (int i = 0; i <= a; i++) {
    x = a - i;
    y = i;
    by1 = b - x;
    by2 = c - y;
    if (by1 == by2 and by1 > 0) {
      flag = 1;
      break;
    }
  }
  if (flag)
    cout << x << " " << y << " " << by1 << endl;
  else
    cout << "Impossible" << endl;
}
