#include <bits/stdc++.h>
using namespace std;
int n, alpha;
int len;
string name;
string modle;
bool check(string s) {
  for (int i = 0; i < modle.length(); i++)
    if (modle[i] == '0') {
      bool dist = false;
      for (int j = 0; j < len; j++) {
        if (s[i + j] != name[j] || s[i + j] == '.') dist = true;
      }
      if (dist == false) return false;
    }
  return true;
}
int main() {
  srand(unsigned(time(NULL)));
  while (cin >> n >> alpha) {
    cin >> name;
    len = name.length();
    cin >> modle;
    string s = "";
    for (int i = 1; i <= n; i++) s += ".";
    bool BAD = false;
    for (int i = 0; i < modle.length(); i++)
      if (modle[i] == '1')
        for (int j = 0; j < len; j++) {
          if (s[i + j] != '.' && s[i + j] != name[j]) BAD = true;
          s[i + j] = name[j];
        }
    for (int i = 0; i < modle.length(); i++)
      if (modle[i] == '0') {
        bool dist = false;
        for (int j = 0; j < len; j++) {
          if (s[i + j] != name[j] || s[i + j] == '.') dist = true;
        }
        if (dist == false) BAD = true;
      }
    string ans = "";
    if (!BAD) {
      for (int i = 1; i <= 500; i++) {
        string tryit = s;
        for (int i = 0; i < tryit.length(); i++)
          if (tryit[i] == '.') {
            if (i < alpha)
              tryit[i] = char('a' + i);
            else
              tryit[i] = char('a' + rand() % alpha);
          }
        if (check(tryit)) {
          ans = tryit;
          break;
        }
      }
    }
    if (BAD)
      cout << "No solution" << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
