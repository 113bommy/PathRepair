#include <bits/stdc++.h>
using namespace std;
int main() {
  bool o = 1, e = 1, si = 1, n = 1;
  string s;
  int mod = 0;
  string arr[7] = {"1869", "6198", "1896", "1689", "1986", "1968", "1698"};
  cin >> s;
  if (s.size() == 4) {
    cout << "1869";
    return 0;
  }
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1' && o) s.erase(s.begin() + i), o = 0, i--;
    if (s[i] == '6' && si) s.erase(s.begin() + i), si = 0, i--;
    if (s[i] == '8' && e) s.erase(s.begin() + i), e = 0, i--;
    if (s[i] == '9' && n) s.erase(s.begin() + i), n = 0, i--;
  }
  sort(s.begin(), s.end());
  reverse(s.begin(), s.end());
  if (s[0] == '0') {
    cout << "1869" << s;
    return 0;
  }
  for (int i = 0; i < s.size(); i++) {
    mod = mod * 10 + (s[i] - '0');
    mod %= 7;
  }
  cout << s << arr[mod];
  return 0;
}
