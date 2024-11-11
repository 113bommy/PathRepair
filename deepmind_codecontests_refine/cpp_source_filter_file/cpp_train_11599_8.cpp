#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = (int)s.length();
  int i = 0;
  while (i < n) {
    if ((i <= n - 3) && s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '4') {
      i += 3;
    } else if (i <= n - 2 && s[i] == '1' && s[i + 1] == '4') {
      i += 2;
    } else if (s[i] == '1') {
      i++;
    } else {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
