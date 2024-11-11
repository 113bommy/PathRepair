#include <bits/stdc++.h>
const long long MOD = 1000000007;
const int N = 300010;
long long nlen[11], len[N], res[11];
char s[N];
int toti[N], pt[N], targ[N];
long long pow10(long long n) {
  if (n == 0) return 1;
  long long ans = pow10(n / 2);
  ans = (ans * ans) % MOD;
  if (n & 1) ans *= 10;
  return ans % MOD;
}
int main() {
  int n, tot = 0;
  while (scanf("%s%d", s, &n) != EOF) {
    for (int i = 0; i <= n; i++) {
      if (i > 0) scanf("%s", s);
      targ[i] = s[0] - '0';
      int length = strlen(s);
      pt[i] = tot;
      int offset = 0;
      if (i > 0) offset = 3;
      len[i] = length - offset;
      for (int j = offset; j < length; j++) toti[tot++] = s[j] - '0';
    }
    for (int i = 0; i < 10; i++) {
      res[i] = i;
      nlen[i] = 10;
    }
    long long ans, r1;
    for (int i = n; i >= 0; i--) {
      ans = 0;
      r1 = 1;
      for (int j = 0; j < len[i]; j++) {
        int num = toti[pt[i] + len[i] - 1 - j];
        ans += res[num] * r1 % MOD;
        if (ans >= MOD) ans %= MOD;
        r1 *= nlen[num];
        if (r1 >= MOD) r1 %= MOD;
      }
      nlen[targ[i]] = r1;
      res[targ[i]] = ans;
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
