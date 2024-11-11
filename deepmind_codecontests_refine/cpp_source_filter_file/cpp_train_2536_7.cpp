#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  string res = "";
  int i = 0;
  if (s.substr(0, 4) == "http") {
    res += "http://";
    i = 4;
  } else {
    res += "ftp://";
    i = 3;
  }
  int j;
  for (j = i; j < s.length() - 1; j++) {
    if (s.substr(j, 2) == "ru") {
      break;
    }
  }
  if (j + 2 == s.length()) {
    res += s.substr(i, j - i) + ".ru";
  } else {
    res += s.substr(i, j - i) + ".ru/" + s.substr(j + 2, s.length() - (j + 2));
  }
  cout << res;
  return 0;
}
