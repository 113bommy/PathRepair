#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
const int N = 1050005;
void solve() {
  string s;
  cin >> s;
  long long n = (long long)s.size();
  vector<long long> dp(1 << 20, -1);
  for (long long i = 0; i <= n - 1; i++) {
    map<long long, long long> mm;
    long long curr = 0;
    for (long long j = i; j >= max(0ll, i - 19); j--) {
      mm[s[j] - 'a']++;
      if (mm[s[j] - 'a'] > 1) break;
      curr |= (1 << (s[j] - 'a'));
      dp[curr] = (long long)mm.size();
    }
  }
  for (long long i = 0; i <= 19; i++) {
    for (long long j = 0; j <= (1 << 20) - 1; j++) {
      if (dp[j] != -1 && (j & (1 << i)) == 0)
        dp[j | (1 << i)] = max(dp[j], dp[j | (1 << i)]);
    }
  }
  long long ans = 0;
  for (long long i = 0; i <= (1 << 20) - 1; i++) {
    ans = max(ans, dp[i] + dp[(~i) & ((1 << 20) - 1)]);
  }
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  while (TESTS--) {
    solve();
  }
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
