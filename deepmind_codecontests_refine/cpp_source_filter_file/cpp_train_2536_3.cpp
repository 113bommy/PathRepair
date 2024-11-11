#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  size_t a;
  cin >> s;
  if (s[0] == 'h') {
    s.insert(s.begin() + 4, ':');
    s.insert(s.begin() + 5, 2, '/');
    a = s.find("ru", 9);
    if (a != string::npos) s.insert(s.begin() + a, '.');
    if ((s[a + 3]) != '\0') s.insert(s.begin() + a + 3, '/');
  } else if (s[0] == 'f') {
    s.insert(s.begin() + 3, ':');
    s.insert(s.begin() + 4, 2, '/');
    a = s.find("ru", 8);
    if (a != string::npos) s.insert(s.begin() + a, '.');
    if ((s[a + 3]) != '\0') s.insert(s.begin() + a + 3, '/');
  }
  cout << s << '\n';
  return 0;
}
