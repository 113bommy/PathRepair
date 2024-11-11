#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.length();
  for (int i = 0; i < n; i++) {
    if (s[i] < 90) {
      s[i] = s[i] + 32;
    }
    if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' &&
        s[i] != 'u' && s[i] != 'y') {
      cout << "." << s[i];
    }
  }
}
