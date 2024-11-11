#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int ans = 0;
  int f = 0;
  for (int i = 0; i < s.size(); i++) {
    f = 0;
    for (int j = i; j < s.size(); j++) {
      for (int k = 1; j - 2 * k >= i; k++) {
        if (s[j - k] == s[j] && s[j] == s[j - 2 * k]) {
          ans += (s.size() - j);
          f = 1;
          break;
        }
      }
      if (f) break;
    }
  }
  cout << ans << endl;
}
