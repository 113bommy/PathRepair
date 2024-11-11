#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  if (s[0] == '4') {
    cout << "NO" << endl;
    return 0;
  }
  if (s.length() >= 3) {
    for (int i = 0; i < s.length(); i++) {
      if (s[i] != '4' && s[i] != '1') {
        cout << "NO" << endl;
        return 0;
      }
      if (i < s.length() - 2 && s[i] == '4' && s[i + 1] == '4' &&
          s[i + 2] == '4') {
        cout << "NO" << endl;
        return 0;
      }
    }
    cout << "YES" << endl;
  }
  if (s.length() < 3) {
    if (s != "1" && s != "11" && s != "14") {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}
