#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    long long x;
    cin >> x;
    string s = "", c = "";
    cin >> s;
    long long clen = 0, slen = s.length();
    for (long long i = 1; i < x; i++) {
      if (s[i - 1] == '1') continue;
      string temp = s.substr(i, s.length() - i);
      c = temp;
      if (s.length() > x) break;
      for (long long j = 1; j < s[i - 1] - '0'; j++) {
        if (s.length() > x) break;
        s += c;
      }
    }
    for (long long i = 1; i <= x; i++) {
      clen = (slen - i) % MOD;
      slen = i % MOD;
      clen = ((s[i - 1] - '0') * clen) % MOD;
      slen = (slen + clen) % MOD;
      if (slen < 0) s += MOD;
    }
    cout << slen << "\n";
  }
  return 0;
}
