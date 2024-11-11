#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  getline(cin, s);
  int l = s.length();
  int ans;
  for (int a = 0; a < l; ++a) {
    if (s[a] == 'Q') {
      for (int b = a + 1; b < l; ++b) {
        if (s[b] == 'A') {
          for (int c = b + 1; c < l; ++c) {
            if (s[c] == 'Q') {
              ++ans;
            }
          }
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
