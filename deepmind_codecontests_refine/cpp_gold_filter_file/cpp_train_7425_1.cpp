#include <bits/stdc++.h>
using namespace std;
string obrabotkaCd(string b, string k) {
  string res;
  if (b[0] == '/') {
    string s = "";
    for (int i = 0; i < b.length(); i++) {
      if (b[i] == '.' && b[i + 1] == '.') {
        s.pop_back();
        unsigned found = s.rfind("/");
        unsigned length = s.length();
        s.erase(found + 1, length - found);
        i++;
      } else {
        if (s.back() != '/' || b[i] != '/') s += b[i];
      }
    }
    if (s.back() != '/') s += '/';
    res = s;
  } else {
    string s = k;
    for (int i = 0; i < b.length(); i++) {
      if (b[i] == '.' && b[i + 1] == '.') {
        s.pop_back();
        unsigned found = s.rfind("/");
        unsigned length = s.length();
        s.erase(found + 1, length - found);
        i++;
      } else {
        if (s.back() != '/' || b[i] != '/') s += b[i];
      }
    }
    if (s.back() != '/') s += '/';
    res = s;
  }
  return res;
}
void program() {
  int n;
  cin >> n;
  string s = "/";
  string a, b;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a == "pwd") {
      if (s.length() == 1)
        cout << "/" << endl;
      else
        cout << s << endl;
    } else {
      cin >> b;
      s = obrabotkaCd(b, s);
    }
  }
}
int main() {
  program();
  return 0;
}
