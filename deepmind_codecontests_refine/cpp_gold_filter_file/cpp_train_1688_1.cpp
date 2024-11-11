#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a;
    string p, h;
    cin >> p >> h;
    if (p.length() > h.length()) {
      cout << "NO\n";
    } else {
      sort(p.begin(), p.end());
      int l1 = p.length();
      int l2 = h.length();
      for (int i = 0; i <= (l2 - l1); i++) {
        a = 0;
        string temp = h.substr(i, p.length());
        sort(temp.begin(), temp.end());
        if (temp == p) {
          a = 1;
          cout << "YES\n";
          break;
        }
      }
      if (a != 1) cout << "NO\n";
    }
  }
  return 0;
}
