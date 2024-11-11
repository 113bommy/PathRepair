#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    bool f = false;
    long long idx = -1;
    for (long long i = 0; i < s.length(); i++) {
      if (s[i] == '8') {
        f = true;
        idx = i;
        break;
      }
    }
    if (s.length() - idx >= 8 && f) {
      cout << "YES" << endl;
    } else
      cout << "NO" << endl;
  }
  return 0;
}
