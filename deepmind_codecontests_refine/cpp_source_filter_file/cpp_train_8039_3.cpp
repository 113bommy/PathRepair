#include <bits/stdc++.h>
using namespace std;
int n, m, t, q, k, a[300010], l;
string s;
int main() {
  cin >> t;
  for (; t; t--) {
    cin >> s;
    n = s.length();
    if (n == 1) {
      cout << s << "\n";
      continue;
    }
    string kb = "", ke = "";
    int b = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == s[n - 1 - i]) {
        kb += s[i];
        ke = s[n - 1 - i] + ke;
        if ((kb.length() + ke.length()) >= n) {
          b = i + 1;
          break;
        }
      } else {
        b = i;
        break;
      }
    }
    string p = "";
    string k = "";
    for (int i = b; i < (n - b); i++) {
      k += s[i];
      for (int j = 0; j < k.length(); j++) {
        if (k[j] == k[k.length() - 1 - j]) {
          continue;
        } else {
          goto Next1;
        }
      }
      if (k.length() > p.length()) {
        p = k;
      }
    Next1:;
    }
    k = "";
    for (int i = n - b - 1; i >= b; i--) {
      k += s[i];
      for (int j = 0; j < k.length(); j++) {
        if (k[j] == k[k.length() - 1 - j]) {
          continue;
        } else {
          goto Next2;
        }
      }
      if (k.length() > p.length()) {
        p = k;
      }
    Next2:;
    }
    cout << kb << p << ke << "\n";
  }
  return 0;
}
