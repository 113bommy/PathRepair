#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  int n = s.length();
  int ct = 0;
  int c = 0, p = 0;
  for (int i = 1; i < n; i++) {
    if (s[i] != s[i - 1]) {
      ct++;
      c = 0;
      p = 0;
    } else if (s[i] == 'C') {
      c++;
      if (c == 5 && i < n) {
        c = 0;
        ct++;
      }
    } else if (s[i] == 'P') {
      p++;
      if (p == 5 && i < n) {
        p = 0;
        ct++;
      }
    }
  }
  cout << ct + 1;
  return 0;
}
