#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5, MOD = 1e9 + 7;
long long n, s, dp[19][19 * 9 + 5][2];
string into_string(long long num) {
  string tmp = "";
  while (num) {
    tmp += (num % 10) + '0';
    num /= 10;
  }
  reverse(tmp.begin(), tmp.end());
  return tmp;
}
long long solve(long long pos, long long matches, long long sum, string num) {
  if (sum < 0) return 0;
  if (pos >= num.size()) return sum == 0;
  if (dp[pos][sum][matches] != -1) return dp[pos][sum][matches];
  long long dig = num[pos] - '0', ret = 0;
  for (long long i = 0; i < 10; i++) {
    if (!matches && i > dig) break;
    ret += solve(pos + 1, matches | (i < dig), sum - i, num);
  }
  return dp[pos][sum][matches] = ret;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long ans = 0;
  cin >> n >> s;
  for (long long i = 1; i <= 15; i++) {
    if (s + i > n) break;
    memset(dp, -1, sizeof(dp));
    long long p1 = solve(0, 0, i, into_string(n));
    memset(dp, -1, sizeof(dp));
    long long p2 = solve(0, 0, i, into_string(s + i - 1));
    ans += p1 - p2;
  }
  cout << ans;
  return 0;
}
