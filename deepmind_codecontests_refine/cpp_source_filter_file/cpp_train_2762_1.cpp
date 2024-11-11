#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[] = {1990, 1991, 1992, 1993, 1994, 1995, 1996, 1997, 1998, 1989};
  int(testow);
  cin >> testow;
  while (testow--) {
    string s;
    cin >> s;
    s = s.substr(4, s.length() - 1);
    if (s.length() == 1) {
      cout << (arr[s[0] - '0']) << "\n";
      continue;
    }
    if (s.length() == 2) {
      if (s == "99")
        cout << 1999 << "\n";
      else {
        cout << 20 << s << "\n";
      }
      continue;
    }
    if (s.length() == 3) {
      if (s[0] == '0') {
        if (s == "099")
          cout << 2099 << "\n";
        else
          cout << 3 << s << "\n";
      } else {
        cout << 2 << s << "\n";
      }
      continue;
    }
    if (s.length() == 4) {
      if (s <= "3098") {
        cout << 1 << s << "\n";
      } else {
        cout << s << "\n";
      }
      continue;
    }
    int t = s.length();
    string temp;
    t -= 4;
    while (t--) temp += "1";
    temp += "0398";
    if (s <= temp) {
      cout << 1 << s << "\n";
    } else {
      cout << s << "\n";
    }
  }
  return 0;
}
