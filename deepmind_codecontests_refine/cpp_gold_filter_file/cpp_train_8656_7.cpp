#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    string s;
    cin >> n >> s;
    bool ok = 0;
    for (int i = 0; i < n; i++) {
      if (n - i >= 11 && s[i] == '8') {
        ok = 1;
        break;
      }
    }
    if (ok == 1) {
      cout << "YES" << '\n';
    } else
      cout << "NO" << '\n';
  }
}
