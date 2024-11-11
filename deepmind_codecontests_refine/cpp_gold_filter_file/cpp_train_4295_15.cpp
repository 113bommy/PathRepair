#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int h, c, t;
    cin >> h >> c >> t;
    if (t <= c) {
      cout << 2 << "\n";
      continue;
    }
    if (t >= h) {
      cout << 1 << "\n"
           << "\n";
      continue;
    }
    double val1, val2, val3, x;
    long long y;
    val1 = (double)(h + c) / 2;
    if (val1 == t) {
      cout << 2 << "\n";
      continue;
    }
    x = (double)(t - h) / (h + c - 2 * t);
    y = x;
    if (x <= 0) y = 1;
    val2 = (double)(y * (h + c) + h) / (2 * y + 1);
    y++;
    val3 = (double)(y * (h + c) + h) / (2 * y + 1);
    int flag = 0;
    double min = h;
    if (abs(t - val1) < min) {
      min = abs(t - val1);
      flag = 1;
    }
    if (abs(t - val2) < min) {
      min = abs(t - val2);
      flag = 2;
    }
    if (abs(t - val3) < min) {
      min = abs(t - val3);
      flag = 3;
    }
    if (abs(t - h) <= min) {
      min = abs(t - h);
      flag = 4;
    }
    if (flag == 1)
      cout << 2 << "\n";
    else if (flag == 2)
      cout << 2 * (y - 1) + 1 << "\n";
    else if (flag == 3)
      cout << 2 * y + 1 << "\n";
    else if (flag == 4)
      cout << 1 << "\n";
  }
}
