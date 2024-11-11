#include <bits/stdc++.h>
using namespace std;
int t(char a) {
  if ('a' <= a && a <= 'z') return 1;
  if ('A' <= a && a <= 'Z') return 2;
  return 3;
}
int main() {
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < (int)s.size(); ++i)
      if ('a' <= s[i] && s[i] <= 'z')
        a++;
      else if ('A' <= s[i] && s[i] <= 'Z')
        b++;
      else
        c++;
    if (a && b && c) {
      cout << s << '\n';
    } else if (a && b) {
      if (t(s[0]) == t(s[1]))
        s[0] = '1';
      else
        s[2] = '1';
      cout << s << '\n';
    } else if (a && c) {
      if (t(s[0]) == t(s[1]))
        s[0] = 'A';
      else
        s[3] = 'A';
      cout << s << '\n';
    } else if (b && c) {
      if (t(s[0]) == t(s[1]))
        s[0] = 'a';
      else
        s[3] = 'a';
      cout << s << '\n';
    } else if (a) {
      s[0] = 'A';
      s[1] = '1';
      cout << s << '\n';
    } else if (b) {
      s[0] = 'a';
      s[1] = '1';
      cout << s << '\n';
    } else {
      s[0] = 'a';
      s[1] = 'A';
      cout << s << '\n';
    }
  }
  return 0;
}
