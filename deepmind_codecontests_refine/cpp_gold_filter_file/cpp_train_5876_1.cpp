#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  int l = s.size();
  for (int i = 0; i < l / 2; i++) {
    char temp = s[i];
    s[i] = s[l - 1 - i];
    s[l - 1 - i] = temp;
  }
  for (int i = 0; i < l; i++) {
    if (s[i] != t[i]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
