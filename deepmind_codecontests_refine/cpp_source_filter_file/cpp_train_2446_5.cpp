#include <bits/stdc++.h>
using namespace std;
const int INF = 2520;
long long dp[25][2525][50], f[25], val[50];
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long dfs(long long len, long long num, long long LCM, long long flag) {
  if (len < 0) return num % LCM == 0;
  if (!flag && dp[len][num][val[LCM]] != -1) return dp[len][num][val[LCM]];
  int k = flag ? f[len] : 9;
  long long ans = 0;
  for (int i = 0; i <= k; i++) {
    long long nowlcm = LCM;
    long long nownum = (num * 10 + i) % INF;
    if (i > 0) nowlcm = lcm(nowlcm, i);
    ans += dfs(len - 1, nownum, nowlcm, flag && i == k);
  }
  if (!flag) dp[len][num][val[LCM]] = ans;
  return ans;
}
long long solve(long long n) {
  int len = 0;
  while (n) {
    f[len++] = n % 10;
    n /= 10;
  }
  return dfs(len - 1, 0, 1, 1);
}
int main() {
  long long a, b, cnt = 0;
  int i, j, k, sum, t;
  for (i = 1; i <= INF; i++)
    if (INF % i == 0) val[i] = cnt++;
  memset(dp, -1, sizeof(dp));
  scanf("%d", &t);
  while (t--) {
    scanf("%lld%lld", &a, &b);
    printf("%lld\n", solve(b) - solve(a - 1));
  }
  return 0;
}
