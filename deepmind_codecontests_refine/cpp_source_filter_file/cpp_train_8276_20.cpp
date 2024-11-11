#include <bits/stdc++.h>
using namespace std;
int main() {
  int h, m, m1, result;
  char s;
  while (cin >> h >> s >> m) {
    cin >> m1;
    result = h * 60 + m + m1;
    h = result / 60;
    if (h >= 24) {
      m = result - h * 60;
      h = h - 24;
    } else if (h < 24)
      m = result - h * 60;
    if (h < 10)
      cout << 0 << h << ':';
    else
      cout << h << ':';
    if (m < 10)
      cout << 0 << m << endl;
    else
      cout << m << endl;
  }
  return 0;
}
