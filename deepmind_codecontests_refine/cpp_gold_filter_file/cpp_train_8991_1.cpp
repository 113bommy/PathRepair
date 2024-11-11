#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  getline(cin, s);
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '"') {
      string t = "";
      i++;
      while (s[i] != '"') {
        t += s[i];
        i++;
      }
      cout << "<" << t << ">" << endl;
    } else if (s[i] == ' ')
      continue;
    else {
      string t = "";
      while (s[i] != ' ' && s[i] != '\0') {
        t += s[i];
        i++;
      }
      cout << "<" << t << ">" << endl;
    }
  }
  return 0;
}
