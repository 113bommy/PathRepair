#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, x1, x2, y1, y2, c = 0;
  cin >> t >> x1 >> y1 >> x2 >> y2;
  string s;
  cin >> s;
  if (x1 >= x2 && y1 >= y2) {
    for (int i = 0; i < t; i++) {
      char ch = s[i];
      if (x1 == x2 && y1 == y2) break;
      if (ch == 'E' || ch == 'W') {
        c++;
        if (x1 != x2) {
          if (ch == 'W') x1 -= 1;
        }
      }
      if (ch == 'N' || ch == 'S') {
        c++;
        if (y1 != y2) {
          if (ch == 'S') y1 -= 1;
        }
      }
    }
  } else if (x1 >= x2 && y1 <= y2) {
    for (int i = 0; i < t; i++) {
      char ch = s[i];
      if (x1 == x2 && y1 == y2) break;
      if (ch == 'E' || ch == 'W') {
        c++;
        if (x1 != x2) {
          if (ch == 'W') x1 -= 1;
        }
      }
      if (ch == 'N' || ch == 'S') {
        c++;
        if (y1 != y2) {
          if (ch == 'N') y1 += 1;
        }
      }
    }
  } else if (x1 <= x2 && y1 >= y2) {
    for (int i = 0; i < t; i++) {
      char ch = s[i];
      if (x1 == x2 && y1 == y2) break;
      if (ch == 'E' || ch == 'W') {
        c++;
        if (x1 != x2) {
          if (ch == 'E') x1 += 1;
        }
      }
      if (ch == 'N' || ch == 'S') {
        c++;
        if (y1 != y2) {
          if (ch == 'S') y1 -= 1;
        }
      }
    }
  } else if (x1 <= x2 && y1 <= y2) {
    for (int i = 0; i < t; i++) {
      char ch = s[i];
      if (x1 == x2 && y1 == y2) break;
      if (ch == 'E' || ch == 'W') {
        c++;
        if (x1 != x2) {
          if (ch == 'E') x1 += 1;
        }
      }
      if (ch == 'N' || ch == 'S') {
        c++;
        if (y1 != y2) {
          if (ch == 'N') y1 += 1;
        }
      }
    }
  }
  if (x1 == x2 && y1 == y2)
    cout << c << "\n";
  else
    cout << "-1\n";
  return 0;
}
