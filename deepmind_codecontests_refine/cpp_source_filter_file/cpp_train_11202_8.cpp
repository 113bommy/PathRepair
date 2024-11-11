#include <bits/stdc++.h>
using namespace std;
string ss, s, temp, s1, s2;
int main() {
  cin >> s1 >> s2 >> s;
  ss = s;
  for (int i = 0; i < (int)s.size(); i++)
    for (int j = 0; j < 26; j++) {
      s[i] = tolower(s[i]);
      if (s[i] == s1[j]) {
        if (isupper(ss[i])) {
          s[i] = toupper(s2[j]);
          cout << s2[i];
        } else
          cout << s2[j];
        break;
      } else if (isdigit(s[i])) {
        cout << ss[i];
        break;
      }
    }
  return 0;
}
