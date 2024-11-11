#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  for (int zz = 0; zz < tc; zz++) {
    int len;
    cin >> len;
    int a[2][len];
    int b[2][len];
    string s, t;
    cin >> s >> t;
    for (int j = 0; j < len; j++) {
      a[0][j] = s[j] - '0';
    }
    for (int j = 0; j < len; j++) {
      a[1][j] = t[j] - '0';
    }
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < len; j++) {
        if (a[i][j] == 1 || a[i][j] == 2) {
          b[i][j] = 0;
        } else
          b[i][j] = 1;
      }
    }
    bool deki = 1;
    int pos = 0;
    int lv = 0;
    int cur = 0;
    while (pos < len) {
      if (cur == 0) {
        if (b[0][pos] == 1 && b[1][pos] == 1) {
          cur = 1;
          pos++;
        } else if (b[0][pos] == 0) {
          pos++;
        } else {
          deki = 0;
          break;
        }
      } else {
        if (b[0][pos] == 1 && b[1][pos] == 1) {
          cur = 0;
          pos++;
        } else if (b[1][pos] == 0) {
          pos++;
        } else {
          deki = 0;
          break;
        }
      }
    }
    if (cur != 1) {
      deki = 0;
    }
    if (deki) {
      cout << "YES\n";
    } else
      cout << "NO\n";
  }
}
