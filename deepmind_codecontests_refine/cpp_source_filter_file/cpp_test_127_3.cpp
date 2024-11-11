#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    string t;
    cin >> t;
    sort(s.begin(), s.end());
    bool rg = false;
    if (t[0] == 'a' && t[1] == 'b' && t[2] == 'c') {
      rg = true;
    }
    if (s.size() < 3) {
      rg = false;
    } else {
      bool c1 = false, c2 = false, c3 = false;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a') {
          c1 = true;
        }
        if (s[i] == 'b') {
          c2 = true;
        }
        if (s[i] == 'c') {
          c3 = true;
        }
      }
      if (!c1 || !c2 || !c3) {
        rg = false;
      }
    }
    if (!rg) {
      cout << s << endl;
    } else {
      long long p1 = 0;
      bool p2c = true;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'b' && p2c) {
          p1 = i;
          p2c = false;
        }
        if (s[i] == 'c') {
          swap(s[i], s[p1]);
          break;
        }
      }
      cout << s << endl;
    }
  }
  return 0;
}
