#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int len;
  cin >> s >> len;
  int n = s.size(), a = 0, b = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '*') b++;
    if (s[i] == '?') a++;
  }
  if (len < n - 2 * a - 2 * b || (len > n - a - b && b == 0)) {
    cout << "Impossible";
  } else {
    int c = n - a - b;
    for (long long i = 0; i < n; i++) {
      if (s[i + 1] == '*') {
        if (c < len) {
          cout << s[i];
          while (c < len) {
            cout << s[i];
            c++;
          }
        } else if (c == len) {
          cout << s[i];
        } else {
          c--;
        }
      } else if (s[i + 1] == '?') {
        if (c <= len) {
          cout << s[i];
        } else {
          c--;
        }
      } else if (s[i] != '*' && s[i] != '?') {
        cout << s[i];
      }
    }
  }
  return 0;
}
