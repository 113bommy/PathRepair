#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int k;
  cin >> k;
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    for (int j = 1; j < 200; j++) {
      if (i + (j + 1) * 2 - 1 >= s.size() + k || (j + 1) * 2 < ans) continue;
      bool ok = true;
      for (int p = 0; p <= j; p++) {
        if (i + p + (j + 1) >= s.size()) break;
        if (s[i + p] != s[i + p + (j + 1)]) {
          ok = false;
          break;
        }
      }
      if (ok) ans = max(ans, (j + 1) * 2);
    }
  }
  cout << ans << endl;
}
