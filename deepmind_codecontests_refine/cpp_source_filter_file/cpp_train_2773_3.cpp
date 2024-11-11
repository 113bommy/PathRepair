#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, m, h, x, x1, left;
  cin >> x;
  cin >> h >> m;
  if ((h % 10 == 7) || (h % 100 == 7) || (m % 10 == 7) || (m % 100 == 7))
    cout << "0";
  else {
    if (m % 10 > 7)
      t = (m % 10) - 7;
    else
      t = (m % 10) + 10 - 7;
    x1 = 1;
    if (h > 7 && h < 17)
      left = (h - 8) * 60 + m;
    else if (h < 7)
      left = (h + 6) * 60 + 60 - m;
    else
      left = (h - 17 - 1) * 60 + m;
    while (1) {
      if ((t + (x1 - 1) * 10) % x == 0) break;
      n = t + (x1 - 1) * 10;
      if (n > left) break;
      x1++;
    }
    n = t + (x1 - 1) * 10;
    if (n < left)
      cout << n / x;
    else {
      cout << (left / x) + 1;
    }
  }
}
