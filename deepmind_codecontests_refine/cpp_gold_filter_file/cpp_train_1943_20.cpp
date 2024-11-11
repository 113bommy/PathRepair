#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long k;
long long a[1020];
long long dp[1020][1020][2];
long long dfs(long long pos, long long memor, bool have, bool limit) {
  if (pos <= 0) return have == 1;
  if (!limit && dp[pos][memor][have] != -1) return dp[pos][memor][have];
  long long up = limit ? a[pos] : 9;
  long long ans = 0;
  for (long long i = 0; i <= up; ++i) {
    bool ha = have;
    long long me = memor;
    if (i == 4 || i == 7) {
      me = pos;
      if (memor && (memor - pos) <= k) ha = 1;
    }
    ans = (ans + dfs(pos - 1, me, ha, limit && i == a[pos])) % MOD;
  }
  if (!limit) dp[pos][memor][have] = ans % MOD;
  return ans;
}
long long solve(string x) {
  long long tot = 0;
  memset(a, 0, sizeof(a));
  for (long long i = x.length() - 1; i >= 0; --i)
    a[++tot] = (long long)(x[i] - '0');
  return dfs(tot, 0, 0, 1);
}
bool judge(string &s) {
  long long pos = -1;
  for (long long i = 0; i < s.length(); ++i) {
    if (s[i] == '4' || s[i] == '7') {
      if (i - pos <= k && pos != -1) return 1;
      pos = i;
    }
  }
  return 0;
}
int main() {
  long long t;
  cin >> t >> k;
  memset(dp, -1, sizeof(dp));
  while (t--) {
    string x, y;
    cin >> x >> y;
    long long ans = solve(y) - solve(x);
    if (judge(x)) ans += 1;
    cout << (ans % MOD + MOD) % MOD << endl;
  }
  return 0;
}
