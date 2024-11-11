#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0, m = 0;
  cin >> n;
  string s, t;
  cin >> s;
  m = s.size();
  for (int i = 0; i < n - 1; ++i) {
    cin >> t;
    for (int j = 0; j < m; ++j) {
      if (s[j] != t[j]) {
        m = j + 1;
        break;
      }
    }
  }
  cout << m;
  return 0;
}
