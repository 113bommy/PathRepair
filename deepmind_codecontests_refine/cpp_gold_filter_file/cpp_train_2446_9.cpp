#include <bits/stdc++.h>
using namespace std;
long long a, b;
long long gcd(long long a, long long b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long bits[20];
long long hashh[3000];
long long dp[20][3000][50];
long long dfs(long long pos, long long num, long long lm, bool limit) {
  if (pos == -1) return num % lm == 0;
  if (!limit && dp[pos][num][hashh[lm]] >= 0) return dp[pos][num][hashh[lm]];
  long long res = 0;
  long long up = limit ? bits[pos] : 9;
  for (long long i = 0; i <= up; i++) {
    if (i != 0)
      res += dfs(pos - 1, (num * 10 + i) % 2520, lcm(lm, i),
                 limit && i == bits[pos]);
    else
      res += dfs(pos - 1, (num * 10 + i) % 2520, lm, limit && i == bits[pos]);
  }
  if (!limit) dp[pos][num][hashh[lm]] = res;
  return res;
}
long long solve(long long num) {
  long long pos = 0;
  while (num) {
    bits[pos++] = num % 10;
    num /= 10;
  }
  return dfs(pos - 1, 0, 1, true);
}
void init() {
  memset(dp, -1, sizeof dp);
  long long cnt = 0;
  for (long long i = 1; i <= 2520; i++) {
    if (2520 % i == 0) hashh[i] = cnt++;
  }
}
signed main() {
  long long t;
  cin >> t;
  init();
  while (t--) {
    cin >> a >> b;
    cout << solve(b) - solve(a - 1) << endl;
  }
}
