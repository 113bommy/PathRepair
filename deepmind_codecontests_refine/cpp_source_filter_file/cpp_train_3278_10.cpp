#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] - '0' == 0) {
      cout << "YES" << endl << 0;
      return 0;
    }
  }
  s = s + "00";
  int l = s.length();
  for (int i = 0; i < l; i++) {
    for (int j = i + 1; j < l; j++) {
      for (int k = i + 1; k < l; k++) {
        long long int x = 100 * (s[i] - '0') + 10 * (s[j] - '0') + (s[k] - '0');
        if (x % 8 == 0 && x != 0) {
          cout << "YES" << endl << x;
          return 0;
        }
      }
    }
  }
  cout << "NO";
  return 0;
}
