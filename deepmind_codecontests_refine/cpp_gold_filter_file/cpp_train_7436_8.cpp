#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, pos, i;
  cin >> n >> pos;
  string s;
  cin >> s;
  if (pos == 1 && n == 2) {
    for (i = pos - 1; i > 0; i--) cout << "LEFT\n";
    for (i = 0; i < n; i++) {
      cout << "PRINT " << s[i] << "\n";
      if (i != n - 1) cout << "RIGHT\n";
    }
  } else if (pos > n / 2) {
    for (i = pos - 1; i < n - 1; i++) cout << "RIGHT\n";
    for (i = n - 1; i >= 0; i--) {
      cout << "PRINT " << s[i] << "\n";
      if (i != 0) cout << "LEFT\n";
    }
  } else {
    for (i = pos - 1; i > 0; i--) cout << "LEFT\n";
    for (i = 0; i < n; i++) {
      cout << "PRINT " << s[i] << "\n";
      if (i != n - 1) cout << "RIGHT\n";
    }
  }
  return 0;
}
