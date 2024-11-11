#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  s = '0' + s + '0';
  for (int i = 1; i <= n; i++) {
    if (s[i] == s[i + 1] && s[i] != '?') {
      cout << "No";
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    if ((s[i - 1] == s[i + 1]) && s[i] == '?') {
      cout << "Yes";
      return 0;
    }
    if (s[i] == s[i + 1] && s[i] == '?') {
      cout << "Yes";
      return 0;
    }
    if ((i == 1 && s[i] == '?') || (i == n && s[i] == '?')) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
  return 0;
}
