#include <bits/stdc++.h>
using namespace std;
long long n;
string s[55];
bool solve() {
  long long i, j, m, p, q;
  for (i = 1; i <= n; i++) {
    for (j = 0; j < n; j++) {
      if (s[i][j] == '1') {
        if (s[i][j + 1] == '0' && s[i + 1][j] == '0') {
          return true;
        }
      }
    }
  }
  return false;
}
int main() {
  long long i, j, a, b, c, d, m, t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (i = 1; i <= n; i++) {
      cin >> s[i];
    }
    if (solve()) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
