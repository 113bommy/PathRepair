#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int a;
  cin >> a;
  string ans = "";
  for (int i = 0; i < s.length(); i++) {
    char c = s[i];
    if (c < a + 'a') {
      ans += toupper(c);
    } else {
      ans += tolower(c);
    }
  }
  cout << ans << endl;
  return 0;
}
