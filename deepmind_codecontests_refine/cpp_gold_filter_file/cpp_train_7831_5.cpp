#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    set<char> se;
    for (int i = 0; i < s.length(); i++) {
      se.insert(s[i]);
    }
    if (se.size() == 1) {
      cout << s;
    } else {
      for (int i = 0; i < s.length(); i++) {
        cout << "01";
      }
    }
    cout << endl;
  }
  return 0;
}
