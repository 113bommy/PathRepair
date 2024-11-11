#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x = -1, res = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '8') {
        x = i + 1;
        break;
      }
    }
    if (x == -1) {
      cout << "NO"
           << "\n";
    } else {
      res = n - x;
      if (res >= 11) {
        cout << "YES"
             << "\n";
      } else {
        cout << "NO"
             << "\n";
      }
    }
  }
  return 0;
}
