#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int n, m, k, a[N], b[N], ans, pos[25];
string s, t, sf1[N], sf2[N];
pair<int, int> dp[(1 << 20) + 5];
string sw(string s) {
  string t = s;
  for (int i = 0; i < k; i++) t[pos[i]] = s[i];
  return t;
}
int msk(string s) {
  int res = 0;
  for (int i = 0; i < k; i++) {
    res *= 2;
    res += s[i] - '0';
  }
  return res;
}
int cnt(int s) {
  int res = 0;
  for (int i = 0; i < k; i++)
    if ((1 << i) & s) res++;
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k;
  cin >> s >> t;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  sf2[n + 1] = t;
  sf1[n + 1] = s;
  for (int i = 0; i < k; i++) pos[i] = i;
  for (int i = n; i >= 1; i--) {
    swap(pos[a[i]], pos[b[i]]);
    sf1[i] = sw(s);
    sf2[i] = sw(t);
  }
  for (int mask = (1 << k) - 1; mask >= 0; mask--)
    dp[mask].first = 1000000007ll;
  for (int i = 1; i <= n + 1; i++) dp[msk(sf2[i])].second = i;
  for (int i = n; i >= 1; i--) dp[msk(sf1[i])].first = i;
  for (int mask = (1 << k) - 1; mask >= 0; mask--)
    for (int i = 0; i < k; i++)
      if (!(mask & (1 << i))) {
        dp[mask].second = max(dp[mask].second, dp[mask + (1 << i)].second);
        dp[mask].first = min(dp[mask].first, dp[mask + (1 << i)].first);
      }
  for (int mask = 1; mask < (1 << k); mask++)
    if (dp[mask].second - dp[mask].first >= m) ans = max(ans, cnt(mask));
  cout << ans + ans + k - cnt(msk(s)) - cnt(msk(t)) << endl;
  for (int mask = 0; mask < (1 << k); mask++)
    if (dp[mask].second - dp[mask].first >= m && cnt(mask) == ans) {
      cout << dp[mask].first << " " << dp[mask].second - 1 << endl;
      return 0;
    }
  return 0;
}
