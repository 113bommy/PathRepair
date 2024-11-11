#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1100000;
const int INF = 0;
const long long mod = 1000000007;
int m;
long long dpB1[MAXN], dpB2[MAXN], dpW1[MAXN], dpW2[MAXN];
long long sum[MAXN][2];
long long f[MAXN];
void process(char s[], char c, int n, long long dp1[], long long dp2[]) {
  sum[0][0] = sum[0][1] = 0;
  dp1[0] = 1;
  dp2[0] = 0;
  f[0] = 1;
  s[0] = '*';
  for (int i = 1; i <= n; ++i) {
    sum[i][1] = (s[i] == c) + sum[i - 1][1];
    sum[i][0] = (s[i] == 'X') + sum[i - 1][0];
    if (i >= m && sum[i][0] - sum[i - m][0] + sum[i][1] - sum[i - m][1] == m &&
        s[i - m] != c) {
      dp2[i] = f[i - m];
    } else
      dp2[i] = 0;
    dp1[i] = dp1[i - 1];
    if (s[i] == 'X') dp1[i] = (dp1[i] << 1) % mod;
    if (s[i] != 'X' && s[i] != c || s[i] == 'X')
      f[i] = dp1[i - 1];
    else
      f[i] = 0;
    dp1[i] = (dp1[i] + mod - dp2[i]) % mod;
  }
}
long long slove(char *s, int n) {
  process(s, 'B', n, dpB1, dpB2);
  reverse(s + 1, s + 1 + n);
  process(s, 'W', n, dpW1, dpW2);
  reverse(dpW1 + 1, dpW1 + 1 + n);
  reverse(dpW2 + 1, dpW2 + 1 + n);
  reverse(s + 1, s + 1 + n);
  long long ans(0), tmp(0);
  for (int i = 1; i < n; ++i) {
    if (s[i] == 'B') tmp = (tmp + dpB2[i]) % mod;
    if (s[i] == 'X') tmp = (tmp * 2 + dpB2[i]) % mod;
    ans += tmp * dpW2[i + 1] % mod;
    ans %= mod;
  }
  return ans;
}
char s[MAXN];
int main() {
  int n;
  while (~scanf("%d%d", &n, &m)) {
    scanf("%s", s + 1);
    printf("%I64d\n", slove(s, n));
  }
  return 0;
}
