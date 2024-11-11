#include <bits/stdc++.h>
inline long long read() {
  char v = getchar();
  int x = 0, f = 1;
  while (!isdigit(v)) {
    if (v == '-') {
      f = -1;
    }
    v = getchar();
  }
  while (isdigit(v)) {
    x = x * 10 + v - 48;
    v = getchar();
  }
  return x * f;
}
long long dp[20][50][2520 + 1], dig[2520 + 1], ind[2520 + 1], cnt, mod,
    num[2520 + 1], l, r, c;
long long gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
long long mylcm(int a, int b) { return a / gcd(a, b) * b; }
long long dfs(long long now, long long lcm, long long sum, int limit) {
  if (!now) {
    return sum % lcm == 0;
  }
  if (!limit && dp[now][num[lcm]][sum] != -1) return dp[now][num[lcm]][sum];
  long long ans = 0, ret = (limit) ? dig[now] : 9;
  for (long long i = 0; i <= ret; ++i) {
    int lcm1 = i ? mylcm(lcm, i) : lcm;
    int sum1 = (sum * 10 + i) % mod;
    ans += dfs(now - 1, lcm1, sum1, limit && i == ret);
  }
  if (!limit) {
    dp[now][num[lcm]][sum] = ans;
  }
  return ans;
}
long long work(long long x) {
  int len = 0;
  while (x) {
    dig[++len] = x % 10;
    x /= 10;
  }
  return dfs(len, 1, 0, 1);
}
int main() {
  memset(dp, -1, sizeof(dp));
  int T = read();
  mod = 2520;
  for (int i = 1; i <= mod; ++i) {
    if (mod % i == 0) {
      num[i] = cnt++;
    }
  }
  while (T--) {
    long long l = read(), r = read();
    printf("%lld\n", work(r) - work(l - 1));
  }
  return 0;
}
