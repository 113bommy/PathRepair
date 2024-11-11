#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    int n;
    cin >> n >> s;
    int ans = 0, bal = 0;
    for (char& c : s) {
      if (c == '(')
        bal++;
      else
        bal--;
      if (bal < 0) {
        bal = 0;
        ans++;
      }
    }
    cout << ans;
  }
  return 0;
}
