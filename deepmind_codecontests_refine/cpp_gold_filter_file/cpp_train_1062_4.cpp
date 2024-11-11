#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long x, dumi;
    cin >> x;
    string s, dum;
    cin >> s;
    string ans = s;
    long long len = ans.size();
    for (int l = 0; l < x; l++) {
      if (ans.size() < x) {
        if (ans[l] > '1') {
          dum = ans.substr(l + 1);
          if (ans[l] == '3') dum += dum;
          ans += dum;
          len = ans.size();
        }
      } else {
        dumi = len - l - 1;
        len = (len + dumi * (ans[l] - '1') + MOD) % MOD;
      }
    }
    cout << len << "\n";
  }
}
