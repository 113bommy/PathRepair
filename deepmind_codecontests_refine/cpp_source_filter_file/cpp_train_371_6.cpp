#include <bits/stdc++.h>
using namespace std;
using ii = pair<long long, long long>;
const long long mn = 2e3 + 11, mk = 1e7 + 11, inf = 0x3f3f3f3f3f3f3f3f;
template <typename t>
bool ckmax(t& target, const t& source) {
  return target < source ? target = source, 1 : 0;
}
template <typename t>
bool ckmin(t& target, const t& source) {
  return target > source ? target = source, 1 : 0;
}
vector<ii> v;
long long dp[mn][26];
long long n;
char a[mn];
int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> a + 1;
  for (long long i = 0; i <= n; i++)
    for (long long j = 0; j < 26; j++) dp[i][j] = i;
  for (long long i = 1; i <= n; i++) {
    long long acc = 1;
    for (long long j = i + 1; j <= n; j++) {
      acc += (a[j] == a[i]);
      ckmax(dp[j - i + 1 - acc][a[i] - 'a'], j - i + 1);
    }
  }
  for (long long j = 0; j < 26; j++)
    for (long long i = 1; i <= n; i++)
      ckmax(dp[i][j], max(n, dp[i - 1][j] + 1));
  long long q;
  cin >> q;
  while (q--) {
    long long m;
    char c;
    cin >> m >> c;
    cout << dp[m][c - 'a'] << '\n';
  }
}
