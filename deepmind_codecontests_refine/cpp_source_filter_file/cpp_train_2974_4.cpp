#include <bits/stdc++.h>
using namespace std;
string s, ss;
char pr = '!';
int in = 0;
bool f = false;
int main() {
  cin >> in >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'o' || s[i] == 'g') {
      if (s[i] == 'o') {
        if (!f) {
          if (pr == '!') {
            ss += "o";
            pr = 'o';
          } else if (pr == 'g') {
            f = true;
            ss = "";
            pr = '!';
          } else if (pr == 'o') {
            cout << ss;
            pr = 'o';
            ss = "o";
          }
        } else {
          if (pr == '!') {
            cout << "***" << ss;
            f = false;
            ss = "o";
            pr = 'o';
          } else {
            ss = "";
            pr = '!';
          }
        }
      } else {
        if (!f) {
          if (pr == '!') {
            cout << "g";
          } else if (pr == 'g') {
            cout << ss << "g";
            ss = "";
            pr = '!';
          } else if (pr == 'o') {
            pr = 'g';
            ss += "g";
          }
        } else {
          if (pr == '!') {
            ss = "g";
            pr = 'g';
          } else {
            cout << "***" << ss;
            f = false;
            pr = '!';
            ss = "";
          }
        }
      }
    } else {
      if (f) cout << "***";
      cout << ss;
      ss = "";
      f = false;
      pr = '!';
      cout << s[i];
    }
  }
  if (f) cout << "***";
  cout << ss;
  return 0;
}
