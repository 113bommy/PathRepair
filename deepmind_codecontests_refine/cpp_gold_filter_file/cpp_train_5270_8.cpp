#include <bits/stdc++.h>
using namespace std;
bool g(char a) {
  return a == 'a' || a == 'o' || a == 'u' || a == 'e' || a == 'i';
}
int f(string s) {
  int fc = 1;
  int u;
  for (int i = 2; i < s.size(); i++) {
    if (s[i] == ' ' || s[i - 1] == ' ' || s[i - 2] == ' ') continue;
    if (!g(s[i]) && !g(s[i - 1]) && !g(s[i - 2]) &&
        (s[i] != s[i - 1] || s[i] != s[i - 2])) {
      fc = 0;
      u = i - 2;
      break;
    }
  }
  if (fc == 0)
    return u;
  else
    return -1;
}
int main() {
  string s;
  cin >> s;
  while (f(s) != -1) {
    int a = f(s);
    s = s.substr(0, a + 2) + ' ' + s.substr(a + 2, s.size() - a - 1);
  }
  cout << s;
}
