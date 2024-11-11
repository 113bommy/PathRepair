#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  int q;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int n;
    string s;
    cin >> n;
    cin >> s;
    if (n > 2) {
      cout << "YES\n";
      cout << 2 << endl;
      cout << s[0] << " " << s.substr(1) << endl;
    } else if (s[0] > s[1]) {
      cout << "YES\n";
      cout << 2 << endl;
      cout << s[0] << " " << s[1] << endl;
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
