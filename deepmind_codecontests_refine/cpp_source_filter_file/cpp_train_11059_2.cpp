#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int n = s.size(), ans = 1, prev = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'R') {
        ans = max(ans, i - prev + 1);
        prev = i + 1;
      }
    }
    ans = max(ans, n + 1 - prev);
    cout << ans;
  }
  return 0;
}
