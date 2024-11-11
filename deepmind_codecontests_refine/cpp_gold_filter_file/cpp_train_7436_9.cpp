#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  if (k > n / 2) {
    for (int i = k; i < n; i++) {
      cout << "RIGHT" << endl;
    }
    for (int i = s.length() - 1; i >= 0; i--) {
      cout << "PRINT " << s[i] << endl;
      if (i == 0) break;
      cout << "LEFT" << endl;
    }
    return;
  } else if (k < n / 2) {
    for (int i = k; i > 1; i--) {
      cout << "LEFT" << endl;
    }
    for (int i = 0; i < s.length(); i++) {
      cout << "PRINT " << s[i] << endl;
      if (i == s.length() - 1) break;
      cout << "RIGHT" << endl;
    }
    return;
  } else if (k == n / 2) {
    for (int i = k - 1; i >= 0; i--) {
      cout << "PRINT " << s[i] << endl;
      if (i == 0) break;
      cout << "LEFT" << endl;
    }
    for (int i = 1; i <= k; i++) {
      cout << "RIGHT" << endl;
    }
    for (int i = k; i < n; i++) {
      cout << "PRINT " << s[i] << endl;
      if (i == s.length() - 1) break;
      cout << "RIGHT" << endl;
    }
    return;
  }
}
int main() {
  { solve(); }
  return 0;
}
