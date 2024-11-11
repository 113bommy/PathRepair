#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  if (k <= n / 2) {
    while (k--) cout << "LEFT" << endl;
    for (int i = 0; i < s.size() - 1; i++) {
      cout << "PRINT " << s[i] << endl;
      cout << "RIGHT" << endl;
    }
    cout << "PRINT " << s[s.size() - 1] << endl;
  } else {
    while (k++ != n) cout << "RIGHT" << endl;
    for (int i = s.size() - 1; i > 0; i--) {
      cout << "PRINT " << s[i] << endl;
      cout << "LEFT" << endl;
    }
    cout << "PRINT " << s[0] << endl;
  }
  return 0;
}
