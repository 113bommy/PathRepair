#include <bits/stdc++.h>
using namespace std;
string gl = "aeiou ";
bool sogl(char c) { return find(gl.begin(), gl.end(), c) == gl.end(); }
int main() {
  string s;
  cin >> s;
  for (int i = 2; i < s.size(); i++) {
    if (sogl(s[i]) and sogl(s[i - 1]) and sogl(s[i - 2]) and
        (s[i - 2] != s[i - 1] or s[i - 2] != s[i])) {
      s = (s.substr(0, i) + " " + s.substr(i));
      i++;
    }
  }
  cout << s;
  return 0;
}
