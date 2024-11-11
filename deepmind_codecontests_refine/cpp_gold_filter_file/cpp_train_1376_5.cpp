#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int len = s.length();
    int i = len;
    if (s[i - 1] == 'o')
      cout << "FILIPINO" << endl;
    else if (s[i - 1] == 'u')
      cout << "JAPANESE" << endl;
    else if (s[i - 1] == 'a')
      cout << "KOREAN" << endl;
  }
  return 0;
}
