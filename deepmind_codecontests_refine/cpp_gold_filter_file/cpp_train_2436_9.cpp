#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  string s;
  cin >> a >> b >> s;
  int x = 0, y = 0;
  if (a == 0 && b == 0) {
    cout << "Yes";
    return 0;
  }
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'L')
      x--;
    else if (s[i] == 'R')
      x++;
    else if (s[i] == 'U')
      y++;
    else if (s[i] == 'D')
      y--;
    if (x == a && y == b) {
      cout << "Yes";
      return 0;
    }
  }
  if (x == 0 && y == 0) {
    cout << "No";
    return 0;
  }
  int xx = x, yy = y;
  x = 0;
  y = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'L')
      x--;
    else if (s[i] == 'R')
      x++;
    else if (s[i] == 'U')
      y++;
    else if (s[i] == 'D')
      y--;
    if (xx == 0) {
      if (x == a && y != b && (b - y) % yy == 0 && (b - y) / yy >= 0) {
        cout << "Yes";
        return 0;
      }
    } else if (yy == 0) {
      if (y == b && x != a && (a - x) % xx == 0 && (a - x) / xx >= 0) {
        cout << "Yes";
        return 0;
      }
    } else if ((a - x) / xx == (b - y) / yy && (a - x) % xx == 0 &&
               (b - y) % yy == 0 && (b - y) / yy >= 0) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
  return 0;
}
