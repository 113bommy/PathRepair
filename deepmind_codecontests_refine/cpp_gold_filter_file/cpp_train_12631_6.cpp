#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  string s;
  char c;
  bool row = 1, col = 1;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (i != 0) row = (c != s[0]);
    c = s[0];
    if (row) {
      for (int j = 0; j < s.size(); j++) {
        if (s[0] != s[j]) {
          col = 0;
          break;
        }
      }
    } else
      break;
  }
  if (row && col)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
