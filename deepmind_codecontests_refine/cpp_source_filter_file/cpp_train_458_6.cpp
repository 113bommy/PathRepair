#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x, x1, x2, y1, y2;
  cin >> n >> m >> x;
  x1 = y1 = 1;
  x2 = n;
  y2 = m;
  x1 = x1 - 1 + x;
  y1 = y1 - 1 + x;
  x2 = x2 + 1 - x;
  y2 = y2 + 1 - x;
  if (x1 <= x2 && y1 <= y2) {
    int s, s1;
    s = (x2 - x1 + 1) * (y2 - y1 + 1);
    if (n % 2 && m % 2)
      s = s / 2 + 1;
    else
      s = s / 2;
    if (x1 + 1 <= x2 - 1 && y1 + 1 <= y2 + 1) {
      s1 = (x2 - x1 - 1) * (y1 - y1 - 1);
      if (n % 2 && m % 2)
        s1 = s1 / 2 + 1;
      else
        s1 = s1 / 2;
    } else
      s1 = 0;
    cout << s - s1 << endl;
  } else
    cout << '0' << endl;
  return 0;
}
