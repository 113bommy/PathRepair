#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0, bal = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        bal++;
      } else {
        bal--;
        if (bal < 0) {
          bal = 0;
          ans++;
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
