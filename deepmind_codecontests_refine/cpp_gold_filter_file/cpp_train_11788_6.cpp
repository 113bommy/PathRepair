#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int i, j, m = 1, n = 0, count = 0;
    for (i = 0; i < s.length(); i++) {
      if (s[i] == '1') {
        m = i;
        break;
      }
    }
    for (j = s.length(); j > 0; j--) {
      if (s[j] == '1') {
        n = j;
        break;
      }
    }
    for (int k = m; k <= n; k++) {
      if (s[k] == '0') count++;
    }
    cout << count << endl;
  }
  return 0;
}
