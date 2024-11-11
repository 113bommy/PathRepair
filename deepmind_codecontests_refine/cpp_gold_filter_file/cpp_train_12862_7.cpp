#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  int count = 0;
  cin >> t;
  string s[t];
  string str;
  for (int i = 0; i < t; i++) {
    cin >> str;
    if (str[0] == 'O' && str[1] == 'O' && count == 0) {
      str[0] = '+';
      str[1] = '+';
      count++;
    } else if (str[3] == 'O' && str[4] == 'O' && count == 0) {
      str[3] = '+';
      str[4] = '+';
      count++;
    }
    s[i] = str;
  }
  if (count > 0) {
    cout << "YES"
         << "\n";
    for (int i = 0; i < t; i++) {
      cout << s[i] << "\n";
    }
  } else
    cout << "NO"
         << "\n";
  return 0;
}
