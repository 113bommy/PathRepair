#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int flag = 0;
  if (s[0] == '-') {
    s.erase(0, 1);
    flag = 1;
  }
  int t;
  t = s.find('.');
  if (t == -1) {
    t = s.length();
    s += ".00";
  } else if (s.length() - t == 2) {
    s = s + "0";
  } else {
    s = s.substr(0, t + 3);
  }
  for (int i = t - 3; i > 0; i--) {
    s.insert(i, ",");
  }
  s = '$' + s;
  if (flag == 1) {
    s = '(' + s + ')';
  }
  cout << s;
  return 0;
}
