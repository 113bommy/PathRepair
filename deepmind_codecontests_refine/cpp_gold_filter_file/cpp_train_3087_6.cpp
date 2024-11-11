#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int t = 1, n;
  cin >> n >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'y' || s[i] == 'u' ||
        s[i] == 'i' || s[i] == 'o') {
      if (t == 1) cout << s[i];
      t = 0;
    } else {
      cout << s[i];
      t = 1;
    }
  }
}
