#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, p = -1, i, m = -2;
  string s;
  cin >> s;
  n = s.size();
  for (i = 0; i < n; i++) {
    if (s[i] == '<' && (s[i + 1] >= 'a' && s[i + 1] <= 'z') &&
        s[i + 2] == '>') {
      m = m + 2;
      for (int j = 0; j < m; j++) {
        cout << " ";
      }
      cout << s[i] << s[i + 1] << s[i + 2] << endl;
      i = i + 2;
      continue;
    }
    if (s[i] == '<' && (s[i + 2] >= 'a' && s[i + 2] <= 'z') &&
        s[i + 1] == '/' && s[i + 3] == '>') {
      for (int k = m; k > 0; k--) {
        cout << " ";
      }
      cout << s[i] << s[i + 1] << s[i + 2] << s[i + 3] << endl;
      i = i + 3;
    }
    m = m - 2;
  }
}
