#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    string p = s;
    sort(s.begin(), s.end());
    if (p != s) {
      cout << s << endl;
    } else {
      if (s == p) {
        int cnt = 0;
        for (int i = 0; i < s.size() - 1; i++) {
          if (s[i] == s[i + 1]) {
            cnt++;
          }
        }
        if (cnt == s.size() - 1) {
          cout << "-1" << endl;
        } else {
          cout << s << endl;
        }
      } else
        cout << "-1" << endl;
    }
  }
}
