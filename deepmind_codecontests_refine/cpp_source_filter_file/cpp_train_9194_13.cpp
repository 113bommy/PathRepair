#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007ll;
long long dp[2650][110];
long long n;
string s;
long long get(long long rem, long long idx) {
  if (rem < 0) return 0;
  if (idx == n + 1) {
    if (rem == 0) return 1;
    return 0;
  }
  long long& ans = dp[rem][idx];
  if (ans != -1) return ans;
  ans = 0;
  for (long long i = 0; i <= 25; i++) {
    ans = (ans + get(rem - i, idx + 1)) % MOD;
  }
  return ans;
}
void solve() {
  cin >> s;
  n = s.size();
  long long x = 0;
  for (auto i : s) x += i - 'a';
  cout << get(x, 1) - 1 << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  memset(dp, -1, sizeof dp);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
