#include <bits/stdc++.h>
using namespace std;
int getmax(string s) {
  int ans = -1;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] - '0' > ans) ans = s[i] - '0';
  }
  return ans;
}
int main() {
  for (string s, ss; cin >> s >> ss;) {
    int base = max(getmax(s), getmax(ss)) + 1;
    if (s.length() > ss.length()) swap(s, ss);
    s = string(ss.length() - s.length(), '0') + s;
    int jin = 0;
    for (int i = ss.length() - 1; i >= 0; i--) {
      jin = jin + ss[i] + s[i] - '0' - '0';
      jin = jin / base;
    }
    if (jin)
      cout << ss.length() + 1 << endl;
    else
      cout << ss.length() << endl;
  }
}
