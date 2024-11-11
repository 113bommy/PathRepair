#include <bits/stdc++.h>
using namespace std;
string s, t, p;
int main() {
  cin >> s;
  cin >> t;
  p = "";
  int length = s.length();
  int tmp = 0;
  for (int i = 0; i < length; i++)
    if (s[i] == t[i]) tmp++;
  tmp = length - tmp;
  if (tmp % 2 == 1) {
    cout << "impossible";
    return 0;
  } else {
    int tmp2 = 0, i = 0;
    while (tmp2 < tmp / 2) {
      if (s[i] != t[i]) {
        p = p + s[i];
        i++;
        tmp2++;
      } else {
        p = p + s[i];
        i++;
      }
    }
    while (tmp2 < tmp) {
      if (s[i] != t[i]) {
        p = p + t[i];
        i++;
        tmp2++;
      } else {
        p = p + s[i];
        i++;
      }
    }
    while (i < length) {
      p = p + s[i];
      i++;
    }
  }
  cout << p;
}
