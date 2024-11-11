#include <bits/stdc++.h>
using namespace std;
int main() {
  string s[8];
  for (int i = 0; i < 8; i++) {
    cin >> s[i];
  }
  int a1, a2;
  int f1 = 0;
  for (int i = 1; i < 8; i++) {
    int l = s[i].size();
    for (int j = 0; j < l; j++) {
      if (s[i][j] == 'W') {
        int k;
        for (k = 0; k < i; k++) {
          if (s[k][j] == 'B') break;
        }
        if (k == i) {
          a1 = i;
          f1 = 1;
          break;
        }
      }
    }
    if (f1 == 1) break;
  }
  int f2 = 0;
  for (int i = 7; i >= 0; i--) {
    int l = s[i].size();
    for (int j = 0; j < l; j++) {
      if (s[i][j] == 'B') {
        int k;
        for (k = 7; k > i; k--) {
          if (s[k][j] == 'W') break;
        }
        if (k == i) {
          a2 = i;
          f2 = 1;
          break;
        }
      }
    }
    if (f2 == 1) break;
  }
  a2 = 7 - a2;
  if (a1 < a2) {
    cout << 'A';
    return 0;
  } else if (a1 > a2) {
    cout << 'B';
    return 0;
  }
}
