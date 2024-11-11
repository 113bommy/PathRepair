#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b = 99999999, c = 0;
  cin >> a;
  string s[a];
  for (int i = 0; i < a; i++) {
    cin >> s[i];
    if (s[i][0] == s[i][1] && s[i][0] == 'O') {
      c = 0;
      b = i;
    } else if (s[i][3] == s[i][4] && s[i][3] == 'O') {
      c = 1;
      b = i;
    }
    if (i == a - 1 && b == 99999999) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < a; i++) {
    if (i == b && c == 0) {
      cout << "++" << s[i][2] << s[i][3] << s[i][4] << endl;
    } else if (i == b && c == 1) {
      cout << s[i][0] << s[i][1] << s[i][2] << "++" << endl;
    } else {
      cout << s[i] << endl;
    }
  }
}
