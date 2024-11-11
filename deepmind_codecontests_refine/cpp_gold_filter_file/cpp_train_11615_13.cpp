#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
#pragma warning(disable : 4996)
  int n;
  scanf("%d", &n);
  string s;
  getline(cin, s);
  getline(cin, s);
  int ch;
  if (n == 24) {
    ch = (s[0] - '0') * 10 + (s[1] - '0');
    if (ch > 23) {
      s[0] = '0';
    }
    ch = (s[3] - '0') * 10 + (s[4] - '0');
    if (ch > 59) {
      s[3] = '0';
    }
  } else {
    ch = (s[0] - '0') * 10 + (s[1] - '0');
    if (ch > 12) {
      if (s[1] == '0') s[0] = '1';
      if (s[1] != '0') s[0] = '0';
    } else {
      if (ch == 0) s[0] = '1';
    }
    ch = (s[3] - '0') * 10 + (s[4] - '0');
    if (ch > 59) {
      s[3] = '0';
    }
  }
  cout << s;
  return 0;
}
