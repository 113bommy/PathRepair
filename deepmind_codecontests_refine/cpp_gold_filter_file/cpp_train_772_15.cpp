#include <bits/stdc++.h>
const long long INF = 1000000007;
const long double cp = 2 * asin(1.0);
const long double eps = 1e-9;
const long long mod = 1000000007;
using namespace std;
int main() {
  string s;
  long long k, len, mx = 0;
  cin >> s >> k;
  for (int(i) = 0; (i) < (k); i++) s += '?';
  for (int l = 1; l <= s.size(); l++) {
    for (int i = 0; i < s.size(); i++) {
      bool f = true;
      for (int j = i; j < l + i; j++) {
        if (s[j] == s[j + l] || s[j + l] == '?')
          f = true;
        else {
          f = false;
          break;
        }
      }
      if (f) {
        mx = l * 2;
        break;
      }
    }
  }
  cout << mx;
  return 0;
}
