#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  while (cin >> t) {
    while (t--) {
      string s;
      cin >> s;
      int n = s.length();
      vector<int> v;
      for (int i = 0; i < n; i++) {
        if (s[i] == 'w') {
          if (i - 1 >= 0 && i + 3 < n && s.substr(i - 1, 3) == "two" &&
              s.substr(i + 1, 3) == "one") {
            v.push_back(i + 1);
            s[i + 1] = 'x';
          } else if (i - 1 >= 0 && i + 1 < n && s.substr(i - 1, 3) == "two") {
            v.push_back(i);
            s[i] = 'x';
          }
        } else if (s[i] == 'n' && i - 1 >= 0 && i + 1 < n &&
                   s.substr(i - 1, 3) == "one") {
          v.push_back(i);
          s[i] = 'x';
        }
      }
      cout << v.size() << endl;
      for (auto it : v) cout << it << " ";
      cout << endl;
    }
  }
  return 0;
}
