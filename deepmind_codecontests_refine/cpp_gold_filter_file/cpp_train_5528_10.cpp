#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  s = s + s;
  int ans = 1;
  int f = 0, e = 0;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] != s[i - 1]) {
      e++;
      if (e - f + 1 < s.size() / 2) {
        ans = max(ans, e - f + 1);
      }
      if (e - f + 1 >= s.size() / 2) {
        ans = s.size() / 2;
      }
    } else {
      f = i, e = i;
    }
  }
  cout << ans;
  return 0;
}
