#include <bits/stdc++.h>
using namespace std;
int main() {
  bool temp = true, temp2 = true;
  int idx;
  string s;
  string t = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_";
  getline(cin, s);
  idx = s.find('@');
  if (idx < 1 || idx == s.length() - 1)
    temp = false;
  else {
    for (int i = 0; i < idx; i++) {
      if (i > 15) temp = false;
      if (t.find(s[i]) == -1) temp = false;
    }
  }
  s = s.substr(idx + 1);
  idx = s.find('/');
  if (idx == s.length() - 1) temp = false;
  if (idx != -1) {
    for (int i = idx + 1; i < s.length(); i++) {
      if (i - idx > 15) temp = false;
      if (t.find(s[i]) == -1) temp = false;
    }
    s = s.substr(0, idx);
  }
  if (s.length() > 32) temp = false;
  while (temp2) {
    idx = s.find('.');
    if (idx == 0 || idx == s.length() - 1) temp = false;
    if (idx == -1) {
      for (int i = 0; i < s.length(); i++) {
        if (i > 15) temp = false;
        if (t.find(s[i]) == -1) temp = false;
      }
      temp2 = false;
    } else {
      for (int i = 0; i < idx; i++) {
        if (i > 15) temp = false;
        if (t.find(s[i]) == -1) temp = false;
      }
      s = s.substr(idx + 1);
    }
  }
  if (temp)
    cout << "YES";
  else
    cout << "NO";
}
