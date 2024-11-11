#include <bits/stdc++.h>
using namespace std;
long long n, a[27], pref[27][1005], dp1[1005], dp2[1005], dp3[1005];
string s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  cin >> s;
  for (long long i = 1; i <= n; ++i) cin >> a[i];
  pref[s[0] - 'a' + 1][1] = 1;
  for (long long i = 2; i <= n; ++i)
    for (long long j = 1; j <= 26; ++j) {
      pref[j][i] = pref[j][i - 1];
      if (j == s[i - 1] - 'a' + 1) pref[j][i]++;
    }
  s = ' ' + s;
  for (long long i = 1; i <= n; ++i) dp3[i] = 1e18;
  dp1[0] = 1;
  for (long long i = 1; i <= n; ++i) {
    for (long long j = 1; j <= i; ++j) {
      long long chk = 1;
      for (long long k = 1; k <= 26; ++k) {
        if (i - j + 1 <= a[k]) continue;
        if (pref[k][i] - pref[k][j - 1] == 0) continue;
        chk = 0;
      }
      if (chk == 0) continue;
      dp1[i] = (dp1[i] + dp1[j - 1]) % 1000000007;
      dp2[i] = max(dp2[i], max(dp2[j - 1], i - j + 1));
      dp3[i] = min(dp3[i], dp3[j - 1] + 1);
    }
  }
  cout << dp1[n] << "\n" << dp2[n] << "\n" << dp3[n] << "\n";
}
