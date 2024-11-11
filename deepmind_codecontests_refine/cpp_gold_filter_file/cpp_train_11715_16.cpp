#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007ll;
long long n, m, k;
string s;
long long last[30];
long long dp[3014159], pref[3014159];
void solve() {
  cin >> n >> k;
  cin >> s;
  m = s.size();
  memset(last, -1, sizeof last);
  for (long long i = 0; i <= m - 1; i++) last[s[i] - 'a'] = i;
  for (long long i = m; i <= m + n - 1; i++) {
    long long l = 1e10, val = -1;
    for (long long j = 0; j <= k - 1; j++) {
      if (last[j] < l) {
        l = last[j];
        val = j;
      }
    }
    s += ('a' + val);
    last[val] = i;
  }
  dp[0] = 1;
  pref[0] = 1;
  memset(last, 0, sizeof last);
  for (long long i = 1; i <= m + n; i++) {
    long long x = s[i - 1] - 'a';
    if (last[x] == 0)
      ;
    else {
      dp[i] += -pref[last[x] - 1] + MOD;
    }
    dp[i] += pref[i - 1];
    dp[i] %= MOD;
    pref[i] = pref[i - 1] + dp[i];
    pref[i] %= MOD;
    last[x] = i;
  }
  cout << pref[n + m];
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
