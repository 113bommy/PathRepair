#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int res = 0;
  for (int i = 0; i < s.length(); i++)
    if (s[i] != '.' && !('0' <= s[i] && s[i] <= '9')) {
      int ind = 0;
      if ('a' <= s[i] && s[i] <= 'z') ind = s[i] - 'a' + 1;
      if ('A' <= s[i] && s[i] <= 'Z') ind = s[i] - 'A' + 1;
      res += int('[' > s[i] && '@' < s[i]) * ind -
             int('`' < s[i] && '{' > s[i]) * ind;
    }
  cout << res;
}
