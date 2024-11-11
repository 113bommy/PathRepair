#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t, i, n, c;
  cin >> t;
  while (t--) {
    string s[9];
    for (long long i = 0; i < 9; i++) cin >> s[i];
    for (long long i = 0; i < 9; i++) {
      for (long long j = 0; j < 9; j++) {
        if (s[i][j] == '8')
          cout << "1";
        else
          cout << s[i][j] << endl;
      }
      cout << endl;
    }
  }
}
