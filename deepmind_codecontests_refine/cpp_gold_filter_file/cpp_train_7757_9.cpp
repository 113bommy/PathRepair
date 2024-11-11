#include <bits/stdc++.h>
char str[100010];
long long mod = 1000000007LL;
long long min(long long a, long long b) { return a < b ? a : b; }
long long dp1[2010][2010];
long long calc1(long long n, long long p) {
  long long q = n - p;
  if (p < 0) return 0;
  if (p > n) return 0;
  if (q > p) return 0;
  if (n == p) return 1;
  if (dp1[n][p] != -1) return dp1[n][p];
  return dp1[n][p] = ((calc1(n - 1, p - 1) + calc1(n - 1, p)) % mod);
}
long long dp2[2010][2010];
long long calc2(long long n, long long p) {
  if (p < 0) return 0;
  if (p > n) return 0;
  if (p == n) return 1;
  if (dp2[n][p] != -1) return dp2[n][p];
  return dp2[n][p] = ((calc2(n - 1, p - 1) + calc2(n - 1, p + 1)) % mod);
}
int main() {
  long long n, m;
  long long flag, open;
  long long a, b;
  long long left;
  long long i;
  long long buff;
  memset(dp1, -1, sizeof(dp1));
  memset(dp2, -1, sizeof(dp1));
  while (~scanf("%I64d%I64d", &n, &m)) {
    scanf("%s", str);
    flag = 0;
    open = 0;
    left = 0;
    for (i = 0; str[i]; i++) {
      if (str[i] == '(')
        flag++, left++;
      else
        flag--;
      open = min(open, flag);
    }
    open = -open;
    if (open < 0) open = 0;
    long long ans;
    ans = 0;
    if (n % 2 != 1) {
      for (i = 0; i <= n - m; i++)
        for (a = (i - open + 1) / 2 + open; a <= i; a++) {
          buff = calc1(i, a);
          buff = buff * calc2(n - m - i, left + a - (m + i - (left + a))) % mod;
          ans = (ans + buff) % mod;
        }
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
