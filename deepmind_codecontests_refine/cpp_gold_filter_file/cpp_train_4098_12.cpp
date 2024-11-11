#include <bits/stdc++.h>
using namespace std;
inline bool check(string s) {
  if ((int)s.size() > 16 || (int)s.size() < 1) return false;
  for (int(i) = 0; (i) < ((int)s.size()); ++(i))
    if (s[i] >= 'a' && s[i] <= 'z')
      ;
    else if (s[i] >= 'A' && s[i] <= 'Z')
      ;
    else if (s[i] == '_')
      ;
    else if (s[i] >= '0' && s[i] <= '9')
      ;
    else
      return false;
  return true;
}
inline void bad() {
  cout << "NO\n";
  exit(0);
}
string s;
int main() {
  cin >> s;
  int pos = 0;
  while (pos < (int)s.size() && s[pos] != '@') ++pos;
  if (pos == (int)s.size()) bad();
  if (!check(s.substr(0, pos))) bad();
  s.erase(0, pos + 1);
  pos = 0;
  while (pos < (int)s.size() && s[pos] != '/') ++pos;
  if (pos < (int)s.size() && !check(s.substr(pos + 1, (int)s.size() - pos - 1)))
    bad();
  if (pos > 32 || pos == 0) bad();
  string t = s.substr(0, pos);
  for (int(i) = 0; (i) < ((int)t.size()); ++(i))
    if (t[i] == '.') {
      if (i == 0 || i == (int)t.size() - 1 || t[i - 1] == ' ') bad();
      t[i] = ' ';
    }
  istringstream iss(t);
  while (iss >> t)
    if (!check(t)) bad();
  cout << "YES\n";
}
