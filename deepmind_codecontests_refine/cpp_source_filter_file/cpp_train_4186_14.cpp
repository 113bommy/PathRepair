#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<int> v;
    int n, ans = 0, i, ans1, ans2, idx1 = 0, idx2 = 0;
    cin >> n;
    string s;
    cin >> s;
    for (i = 0; i < s.size(); i++) {
      if (s[i] == '1') idx1 = i;
    }
    for (i = s.size() - 1; i >= 0; i--) {
      if (s[i] == '1') {
        idx2 = i;
      }
    }
    ans = max(2 * (idx1 + 1), 2 * (n - idx2));
    if (idx1 == 0 && idx2 == 0)
      cout << n << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
