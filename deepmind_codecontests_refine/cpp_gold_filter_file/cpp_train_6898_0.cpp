#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    vector<int> v;
    string r = "\0";
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '1') {
        r += s[i];
        if (i == s.length() - 1) {
          v.push_back(r.length());
        }
      } else {
        v.push_back(r.length());
        r = "\0";
      }
    }
    sort(v.begin(), v.end());
    for (int i = v.size() - 1; i >= 0; i -= 2) ans += v[i];
    cout << ans << "\n";
  }
  return 0;
}
