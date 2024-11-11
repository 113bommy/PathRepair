#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  string s;
  cin >> s;
  int a[4];
  a[0] = s[0] - '0';
  a[1] = s[1] - '0';
  ;
  a[2] = s[3] - '0';
  a[3] = s[4] - '0';
  int x = a[0] * 10 + a[1];
  int y = a[2] * 10 + a[3];
  int i = 0;
  while (i < 20) {
    if ((x % 10) == (y / 10) && (x / 10) == (y % 10)) {
      cout << i;
      break;
    }
    ++i;
    if (y == 59) {
      if (x == 23) {
        x = 0;
        y = 0;
      } else {
        x += 1;
        y = 0;
      }
    } else
      ++y;
  }
  return 0;
}
