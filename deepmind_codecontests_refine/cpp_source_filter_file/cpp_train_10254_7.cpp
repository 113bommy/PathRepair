#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int n2, n1;
string sorti(string s) {
  if (s.length() == 1)
    return s;
  else {
    string s1 = sorti(s.substr(0, s.length() / 2));
    string s2 = sorti(s.substr(s.length() / 2, s.length() / 2));
    if (s1 < s2)
      return s1 + s2;
    else
      return s2 + s1;
  }
}
int main() {
  cin >> s1 >> s2;
  if (sorti(s1) == sorti(s2))
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
