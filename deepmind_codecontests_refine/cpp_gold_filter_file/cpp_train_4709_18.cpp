#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int t = 0;
  int t1 = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] <= 90 && s[i] >= 65) t++;
  }
  if (s[0] <= 124 && s[0] >= 97) t1++;
  if (t == s.size())
    transform(s.begin(), s.end(), s.begin(), ::tolower);
  else if (t == s.size() - 1 && t1 == 1) {
    s[0] = s[0] - 32;
    transform(s.begin() + 1, s.end(), s.begin() + 1, ::tolower);
  }
  cout << s;
  return 0;
}
