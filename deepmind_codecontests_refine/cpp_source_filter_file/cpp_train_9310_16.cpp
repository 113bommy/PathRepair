#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int i, x = 0, y = 0;
  string s;
  cin >> s;
  for (i = 2; i < s.length() - 3; i++) {
    if (s[i] == 'd' && s[i + 1] == 'o' && s[i + 2] == 't') {
      s[i] = '.';
      s[i + 1] = '*';
      s[i + 2] = '*';
    }
  }
  for (i = 1; i < s.length() - 2; i++) {
    if (s[i] == 'a' && s[i + 1] == 't') {
      s[i] = '@';
      s[i + 1] = '*';
      break;
    }
  }
  for (i = 0; i < s.length(); i++) {
    if (s[i] != '*') {
      cout << s[i];
    }
  }
}
