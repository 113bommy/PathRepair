#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  if (s.find("at") != string::npos) {
    int a = s.find("at");
    s = s.substr(0, a) + "@" + s.substr(a + 2);
  }
  if (s[0] == '@') {
    if (s.find("at") != string::npos) {
      int a = s.find("at");
      s = s.substr(0, a) + "@" + s.substr(a + 2);
    }
    s = "at" + s.substr(1);
  }
  while (s.find("dot") != string::npos) {
    int a = s.find("dot");
    s = s.substr(0, a) + '.' + s.substr(a + 3);
  }
  if (s[0] == '.') {
    s = "dot" + s.substr(1);
  }
  if (s[s.size() - 1] == '.') {
    s = s.substr(0, s.size() - 2) + "dot";
  }
  cout << s << endl;
  return 0;
}
