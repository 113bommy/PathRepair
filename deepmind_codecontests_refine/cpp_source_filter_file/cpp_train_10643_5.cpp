#include <bits/stdc++.h>
using namespace std;
int decimal(string s) {
  int i, t, t1 = 1;
  i = s.size() - 1;
  while (i >= 0) {
    if (s[i] == '1') t = t + t1;
    i--;
    t1 = t1 * 2;
  }
  return t;
}
string rev(string s) {
  int i;
  string s1 = "";
  for (i = (s.size() - 1); i >= 0; i--) s1 = s1 + s[i];
  return s1;
}
string binary(int i) {
  string s = "";
  while (i > 0) {
    if (i % 2 == 0)
      s = s + '0';
    else
      s = s + '1';
    i = i / 2;
  }
  s = rev(s);
  return s;
}
int main() {
  int i, b, x, t;
  string s, s1;
  getline(cin, s);
  t = 0;
  for (i = 0; i < s.size(); i++) {
    s1 = binary(int(s[i]));
    while (s1.size() < 8) s1 = '0' + s1;
    b = decimal(rev(s1));
    x = 256 - b + t;
    if (x >= 256) x = x % 256;
    cout << x << endl;
    t = b;
  }
  return 0;
}
