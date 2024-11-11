#include <bits/stdc++.h>
using namespace std;
const int mod1 = 998244353, mod = 1e9 + 7;
const int MAXN = 300001, MAXM = 200010;
long long zer[(long long)1e6 + 6], dp[(long long)1e6 + 6],
    nxt[(long long)1e6 + 6];
long long n;
string s;
void Solve() {
  cin >> s;
  n = s.length();
  for (long long i = 0; i < n; ++i)
    if (s[i] == '0') zer[i] = (i > 0 ? zer[i - 1] : 0) + 1;
  for (long long i = 0; i <= n; i++) {
    nxt[i] = n;
  }
  for (long long i = n - 1; i >= 0; --i) {
    dp[i] = ((zer[i] <= zer[n - 1]) + dp[nxt[0]] + dp[nxt[zer[i] + 1]]) % mod;
    nxt[zer[i]] = i;
  }
  long long ans = n;
  if (nxt[0] < n) ans = dp[nxt[0]] * (nxt[0] + 1);
  cout << ans;
}
signed main() {
  if (fopen(""
            ".inp",
            "r")) {
    freopen(
        ""
        ".inp",
        "r", stdin);
    freopen(
        ""
        ".out",
        "w", stdout);
  };
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long TC = 1;
  while (TC--) Solve();
  return 0;
}
