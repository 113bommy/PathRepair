#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> s;
    if (s.length() < 3)
      cout << "FILIPINO" << '\n';
    else {
      n = s.length();
      if (s[n - 1] == 'u')
        cout << "JAPANESE" << '\n';
      else if (s[n - 1] == 'a')
        cout << "KOREAN" << '\n';
      else
        cout << "FILIPINO";
    }
  }
  return 0;
}
