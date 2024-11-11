#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  getline(cin, s);
  for (int i = 0; i < s.size(); i++)
    if (s[i] == ' ' && !(s[i - 1] >= '0' && s[i - 1] <= '9' &&
                         s[i + 1] >= '0' && s[i + 1] <= '9')) {
      s.erase(i, 1);
      i--;
    }
  for (int i = 0; i < s.size(); i++)
    if (s[i] == ',') s.insert(i + 1, " ");
  int st;
  if (s.find_first_of("...") == 0)
    st = 3;
  else
    st = 1;
  for (int i = st; i < s.size();) {
    if (s.find_first_of("...", i) == i) {
      if (s[i - 1] != ' ') {
        s.insert(i, " ");
        i += 4;
      } else
        i += 3;
    } else
      i++;
  }
  if (s[s.size() - 1] == ' ')
    for (int i = 0; i < s.size() - 1; i++) cout << s[i];
  else
    cout << s;
  return 0;
}
