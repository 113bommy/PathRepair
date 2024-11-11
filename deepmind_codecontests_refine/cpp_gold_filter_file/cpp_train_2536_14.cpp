#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  string h = "http", f = "ftp";
  string res = "";
  int i;
  for (i = 0; i < s.size(); i++) {
    res += s[i];
    if (res == h || res == f) {
      i++;
      res += "://";
      break;
    }
  }
  string temp = "";
  while (i < s.size()) {
    if (s[i] == 'r' && s[i + 1] == 'u' && temp.size() > 0) {
      temp += ".ru";
      i += 2;
      break;
    } else {
      temp += s[i];
      i++;
    }
  }
  res += temp;
  if (i < s.size()) {
    res += '/';
    res += s.substr(i);
  }
  cout << res;
  return 0;
}
