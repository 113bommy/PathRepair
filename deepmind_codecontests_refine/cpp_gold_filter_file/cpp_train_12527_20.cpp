#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int a = -1, b = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '.') {
      if (a == -1)
        a = i;
      else {
        b = a;
        a = i;
        if (a - b > 12 || a - b <= 2) {
          cout << "NO" << endl;
          return 0;
        }
      }
      if (a == 0) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  if (a == -1 || s.length() - a > 4 || a == s.length() - 1 ||
      (b == 0 && a > 8)) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  int temp = -1;
  for (int i = 0; i < s.length(); i++) {
    cout << s[i];
    if (s[i] == '.') {
      if (s[i + 3] == '.')
        temp = i + 1;
      else if (s[i + 4] == '.')
        temp = i + 2;
      else
        temp = i + 3;
    }
    if (i == temp) cout << endl;
  }
  if (temp - s.length() < 3) cout << endl;
}
