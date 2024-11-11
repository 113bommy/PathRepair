#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d, e, i, j, k;
  string s;
  cin >> s;
  for (i = 0; i < s.length(); i++) {
    long long x = s[i] - '0';
    if (x % 8 == 0) {
      cout << "YES" << endl;
      cout << x << endl;
      return 0;
    }
  }
  for (i = 0; i < s.length(); i++) {
    for (j = i + 1; j < s.length(); j++) {
      long long x = (s[i] - '0') * 10 + s[j] - '0';
      if (x % 8 == 0) {
        cout << "YES" << endl;
        cout << x << endl;
        return 0;
      }
    }
  }
  for (i = 0; i < s.length(); i++) {
    for (j = i + 1; j < s.length(); j++) {
      for (k = j + 1; k < s.length(); k++) {
        long long x = (s[i] - '0') * 100 + (s[j] - '0') * 10 + s[k] - '0';
        if (x % 8 == 0) {
          cout << "YES" << endl;
          cout << x << endl;
          return 0;
        }
      }
    }
  }
  cout << "NO" << endl;
}
