#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  s += ",";
  vector<string> v1, v2;
  bool flag = 0;
  int ns = 0, lx = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ',' || s[i] == ';') {
      if (ns == 0) flag = 1;
      if (ns == 1 && s[lx] == '0') flag = 0;
      if (flag) {
        v2.push_back(s.substr(lx, ns));
      } else {
        v1.push_back(s.substr(lx, ns));
      }
      flag = 1;
      ns = 0;
      lx = i + 1;
      continue;
    }
    ns++;
    if (ns == 1) {
      if (s[i] == '0') {
        flag = 1;
      }
    }
    if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'a' && s[i] <= 'z') ||
        s[i] == '.')
      flag = 1;
  }
  if (v1.size() == 0)
    cout << "-\n";
  else {
    cout << '"';
    cout << v1[0];
    for (int i = 1; i < v1.size(); i++) cout << ',' << v1[i];
    cout << '"' << "\n";
  }
  if (v2.size() == 0)
    cout << "-\n";
  else {
    cout << '"';
    cout << v2[0];
    for (int i = 1; i < v2.size(); i++) cout << ',' << v2[i];
    cout << '"' << "\n";
  }
  return 0;
}
