#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int len = s.length();
  int b = 0;
  int d = 0;
  int bz;
  for (int i = 2; i <= len - 1; i++) {
    if (s[i] != 'e' && s[i] != '0') d = 1;
    if (s[i] == 'e') {
      bz = i;
      break;
    }
  }
  for (int i = bz + 1; i <= len - 1; i++) {
    b = b * 10 + s[i] - '0';
  }
  if (b == 0) {
    if (d != 0) {
      cout << s[0] << ".";
      for (int i = 2; i < bz; i++) cout << s[i];
    }
    if (d == 0) {
      cout << s[0];
    }
  } else {
    cout << s[0];
    for (int i = 2; i <= min(bz - 1, 1 + b); i++) {
      cout << s[i];
    }
    if (1 + b >= bz - 1) {
      for (int i = 1; i <= 1 + b - bz + 1; i++) {
        cout << 0;
      }
      cout << endl;
    } else {
      cout << ".";
      for (int i = 2 + b; i < bz; i++) {
        cout << s[i];
      }
    }
  }
}
