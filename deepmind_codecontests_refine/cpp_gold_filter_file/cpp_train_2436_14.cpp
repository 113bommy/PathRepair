#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, p[101][3], x, y, i;
  string s;
  p[0][1] = 0;
  p[0][2] = 0;
  cin >> a >> b;
  cin >> s;
  if (a == 0 && b == 0) {
    cout << "Yes" << endl;
    return 0;
  }
  for (i = 1; i <= s.size(); i++) {
    if (s[i - 1] == 'L') {
      p[i][1] = p[i - 1][1] - 1;
      p[i][2] = p[i - 1][2];
    }
    if (s[i - 1] == 'R') {
      p[i][1] = p[i - 1][1] + 1;
      p[i][2] = p[i - 1][2];
    }
    if (s[i - 1] == 'U') {
      p[i][1] = p[i - 1][1];
      p[i][2] = p[i - 1][2] + 1;
    }
    if (s[i - 1] == 'D') {
      p[i][1] = p[i - 1][1];
      p[i][2] = p[i - 1][2] - 1;
    }
  }
  if (p[s.size()][1] == 0 || p[s.size()][2] == 0) {
    if (p[s.size()][1] == 0 && p[s.size()][2] == 0) {
      for (i = 1; i <= s.size(); i++) {
        if (a == p[i][1] && b == p[i][2]) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    } else if (p[s.size()][1] == 0) {
      for (i = 1; i <= s.size(); i++) {
        x = a - p[i][1];
        y = b - p[i][2];
        if (x != 0) continue;
        if (y % p[s.size()][2] == 0) {
          if (y / p[s.size()][2] >= 0) {
            cout << "Yes" << endl;
            return 0;
          }
        }
      }
    } else {
      for (i = 1; i <= s.size(); i++) {
        x = a - p[i][1];
        y = b - p[i][2];
        if (y != 0) continue;
        if (x % p[s.size()][1] == 0) {
          if (x / p[s.size()][1] >= 0) {
            cout << "Yes" << endl;
            return 0;
          }
        }
      }
    }
  } else {
    for (i = 1; i <= s.size(); i++) {
      x = a - p[i][1];
      y = b - p[i][2];
      if (x % p[s.size()][1] == 0 && y % p[s.size()][2] == 0 &&
          x / p[s.size()][1] == y / p[s.size()][2]) {
        if (x / p[s.size()][1] >= 0 && y / p[s.size()][2] >= 0) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
}
