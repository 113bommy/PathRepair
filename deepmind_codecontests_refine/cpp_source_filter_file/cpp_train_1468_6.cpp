#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.size() - 1; i++) {
    if (s[i] == 'n')
      continue;
    else if (s[i] != 'a' && s[i + 1] != 'a' && s[i] != 'e' && s[i + 1] != 'e' &&
             s[i] != 'i' && s[i + 1] != 'i' && s[i] != 'o' && s[i + 1] != 'o' &&
             s[i] != 'u' && s[i + 1] != 'u') {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
