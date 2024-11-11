#include <bits/stdc++.h>
using namespace std;
bool is_amp(string s) {
  if (s.size() == 0) {
    return false;
  }
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] != ' ') {
      return s[i] == '#';
    }
  }
  return false;
}
int main() {
  string s;
  bool flag = false;
  int c = 0;
  while (getline(cin, s)) {
    if (is_amp(s)) {
      flag = true;
    }
    if (flag) {
      if (c) {
        cout << endl;
        c = 0;
      }
      cout << s << endl;
      flag = false;
    } else {
      ++c;
      for (string::iterator itr = s.begin(); itr != s.end(); ++itr) {
        if (*itr != ' ') {
          cout << *itr;
        }
      }
    }
  }
  if (flag) {
    cout << endl;
  }
}
