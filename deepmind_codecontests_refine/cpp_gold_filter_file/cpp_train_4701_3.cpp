#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC tsmthget("avx2")
using namespace std;
const long long one = 1;
const long double INF = 2e18;
const long long MOD = 1e9 + 7;
const long long N = 2010;
const long long nul = 0;
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long ball = 0, bal = 0;
  for (auto i : s) {
    if (i == '(')
      ball++;
    else if (i == ')')
      ball--;
  }
  vector<long long> pref(n + 1, 0);
  for (long long i = 1; i <= n; i++) {
    if (s[i - 1] == ')')
      pref[i] = pref[i - 1] - 1;
    else
      pref[i] = pref[i - 1] + 1;
  }
  bool flag = 0;
  if (pref[n] < 0) flag = 1;
  for (long long i = 1; i < n; i++) {
    if (pref[i] <= 0) flag = 1;
  }
  if (flag) {
    cout << ":(" << endl;
    return 0;
  }
  if (pref[n] != 0) {
    long long x = pref[n];
    if (pref[n] % 2 == 1) flag = 1;
    for (long long i = n; i > 0; i--) {
      if (s[i - 1] == '?') {
        x -= 2;
        s[i - 1] = ')';
      }
      if (x == 0) break;
    }
    for (char &i : s) {
      if (i == '?') i = '(';
    }
    if (x != 0) flag = 1;
    bal = 0;
    for (long long i = 0; i < n - 1; i++) {
      if (s[i] == '(')
        bal++;
      else
        bal--;
      if (bal <= 0) flag = 1;
    }
    if (flag)
      cout << ":(" << endl;
    else
      cout << s << endl;
  } else {
    for (char &i : s) {
      if (i == '?') i = '(';
    }
    cout << s << endl;
  }
}
