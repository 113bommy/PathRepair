#include <bits/stdc++.h>
using namespace std;
int test, n;
string t;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> test;
  while (test--) {
    cin >> t;
    n = t.size();
    bool ok = 1;
    for (int i = 1; i <= n; i++) {
      if (t[i] != t[i - 1]) {
        ok = 0;
      }
    }
    if (ok) {
      cout << t << '\n';
      continue;
    }
    string s;
    s += t[0];
    for (int i = 1; i <= n; i++) {
      if (t[i] == t[i - 1]) {
        s += t[i] ^ '0' ^ '1';
      }
      s += t[i];
    }
    cout << s << '\n';
  }
  return 0;
}
