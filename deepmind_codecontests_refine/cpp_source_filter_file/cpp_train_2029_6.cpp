#include <bits/stdc++.h>
using namespace std;
vector<int> v1, v2;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  string s;
  int m = 0;
  cin >> s;
  for (int i = 0; i < s.length() - 1; i++) {
    if (s[i] == 'A' && s[i + 1] == 'B') {
      m = i + 2;
      break;
    }
  }
  if (m != 0) {
    for (int i = m; i < s.length() - 1; i++) {
      if (s[i] == 'B' && s[i + 1] == 'A') {
        cout << "YES";
        return 0;
      }
    }
  }
  for (int i = 0; i < s.length() - 1; i++) {
    if (s[i] == 'B' && s[i + 1] == 'A') {
      m = i + 2;
      break;
    }
  }
  if (m != 0) {
    for (int i = m; i < s.length() - 1; i++) {
      if (s[i] == 'A' && s[i + 1] == 'B') {
        cout << "YES";
        return 0;
      }
    }
  }
  cout << "NO";
  return 0;
}
