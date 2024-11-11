#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int left = 0, right = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '1') {
        left = i;
        break;
      }
    }
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] == '1') {
        right = i;
        break;
      }
    }
    int ans = 0;
    if (left != 0 and right != 0) {
      for (int i = left; i <= right; i++) {
        if (s[i] == '0') ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
