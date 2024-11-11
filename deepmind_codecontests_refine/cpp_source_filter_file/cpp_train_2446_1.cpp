#include <bits/stdc++.h>
using namespace std;
const int MOD = 2520;
long long dp[20][50][2550];
int dis[20];
int Hash[2550];
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long dfs(int len, int num, int lcm, bool flag) {
  if (-1 == len) return num % lcm == 0;
  if (!flag && -1 == dp[len][Hash[lcm]][num]) return dp[len][Hash[lcm]][num];
  long long ans = 0;
  int end = flag ? dis[len] : 9;
  for (int i = 0; i <= end; i++)
    ans += dfs(len - 1, (num * 10 + i) % MOD, i ? lcm * i / gcd(lcm, i) : lcm,
               flag && i == end);
  if (!flag) dp[len][Hash[lcm]][num] = ans;
  return ans;
}
long long solve(long long n) {
  int pos = 0;
  while (n) {
    dis[pos++] = n % 10;
    n /= 10;
  }
  return dfs(pos - 1, 0, 1, 1);
}
int main() {
  int T;
  scanf("%d", &T);
  int cnt = 0;
  for (int i = 1; i <= MOD; i++)
    if (MOD % i == 0) Hash[i] = cnt++;
  memset(dp, -1, sizeof(dp));
  while (T--) {
    long long l, r;
    scanf("%lld%lld", &l, &r);
    printf("%lld\n", solve(r) - solve(l - 1));
  }
  return 0;
}
