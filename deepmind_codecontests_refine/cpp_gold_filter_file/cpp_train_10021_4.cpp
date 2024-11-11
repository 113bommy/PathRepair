#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 10;
const long long base = 3e18;
const long long mod = 1e9 + 7;
const long double eps = 1e-10;
long long dp[maxn];
long long cnt[maxn];
long long nxt[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (fopen("t.inp", "r")) {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
  }
  string s;
  cin >> s;
  long long suf = 0;
  while (s.size() && s.back() == '0') {
    s.pop_back();
    suf++;
  }
  if (s.size() == 0) {
    cout << suf;
    return 0;
  }
  long long pre = 0;
  while (s[pre] == '0') pre++;
  for (int i = pre; i < s.size(); i++) {
    if (i) cnt[i] = cnt[i - 1];
    if (s[i] == '1')
      cnt[i] = 0;
    else
      cnt[i]++;
  }
  for (int i = 0; i <= s.size(); i++) nxt[i] = s.size();
  for (int i = s.size() - 1; i >= pre; i--) {
    dp[i] = (dp[i] + dp[nxt[0]]) % mod;
    dp[i] = (dp[i] + dp[nxt[cnt[i] + 1]]) % mod;
    if (s[i] == '1') dp[i] = (dp[i] + 1) % mod;
    nxt[cnt[i]] = i;
  }
  cout << (((pre + 1) * dp[pre]) % mod * (suf + 1)) % mod;
}
