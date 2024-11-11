#include <bits/stdc++.h>
using namespace std;
bool valid(string s) {
  int a = -1, b = -1;
  int ca = 0, cb = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '@') {
      a = i;
      ca++;
    }
    if (s[i] == '/') {
      b = i;
      cb++;
    }
  }
  if (ca >= 2 || cb >= 2) return false;
  if (a <= 0 || a > 16) return false;
  for (int i = 0; i < a; i++)
    if (!(('A' <= s[i] && s[i] <= 'Z') || ('a' <= s[i] && s[i] <= 'z') ||
          ('0' <= s[i] && s[i] <= '9') || s[i] == '_'))
      return false;
  int end = s.size() - 1;
  if (b > 0) end = b - 1;
  if (end - a < 1) return false;
  int d = 0;
  for (int i = a + 1; i <= end; i++) {
    if (s[i] == '.') {
      if (d == 0) return false;
      d = 0;
    } else {
      if (!(('A' <= s[i] && s[i] <= 'Z') || ('a' <= s[i] && s[i] <= 'z') ||
            ('0' <= s[i] && s[i] <= '9') || s[i] == '_'))
        return false;
      else
        d++;
      if (d > 16) return false;
    }
  }
  if (d == 0) return false;
  if (b > 0) {
    if (s.size() - 1 - b > 16) return false;
    if (s.size() - 1 - b < 1) return false;
    for (int i = b + 1; i < s.size(); i++)
      if (!(('A' <= s[i] && s[i] <= 'Z') || ('a' <= s[i] && s[i] <= 'z') ||
            ('0' <= s[i] && s[i] <= '9') || s[i] == '_'))
        return false;
  }
  return true;
}
int main(void) {
  string s;
  while (cin >> s)
    if (valid(s))
      cout << "YES\n";
    else
      cout << "NO\n";
}
