#include <bits/stdc++.h>
const int MOD = 1000000007;
int n, m, ret;
int sum[1000005][3], pre[1000005], suf[1000005];
char s[1000005];
long long tmp;
void fix(int &x) { x = (x % MOD + MOD) % MOD; }
int main() {
  scanf("%d%d%s", &n, &m, s + 1);
  for (int i = (1); i <= (n); i++) {
    for (int j = (0); j < (3); j++) sum[i][j] = sum[i - 1][j];
    if (s[i] == 'X') sum[i][0]++;
    if (s[i] == 'B') sum[i][1]++;
    if (s[i] == 'W') sum[i][2]++;
  }
  pre[0] = 1;
  for (int i = (1); i <= (n); i++) {
    pre[i] = pre[i - 1] * (1 + (s[i] == 'X'));
    if (i >= m && sum[i][2] == sum[i - m][2]) {
      if (i == m)
        pre[i]--;
      else if (s[i - m] != 'B')
        pre[i] -= pre[i - m - 1];
    }
    fix(pre[i]);
  }
  suf[n + 1] = 1;
  for (int i = (n + 1) - 1; i >= (1); i--) {
    suf[i] = suf[i + 1] * (1 + (s[i] == 'X'));
    if (i + m - 1 <= n && sum[i + m - 1][1] == sum[i - 1][1]) {
      if (i + m - 1 == n)
        suf[i]--;
      else if (s[i + m] != 'W')
        suf[i] -= suf[i + m + 1];
    }
    fix(suf[i]);
  }
  ret = tmp = 0;
  for (int i = (n - m + 1) - 1; i >= (m); i--) {
    if (s[i + 1] == 'X') tmp = (tmp << 1) % MOD;
    if (sum[i + m][1] == sum[i][1]) {
      if (i + m == n)
        tmp = (tmp + 1) % MOD;
      else if (s[i + m + 1] != 'W')
        tmp = (tmp + suf[i + m + 2]) % MOD;
    }
    if (sum[i][2] == sum[i - m][2]) {
      if (i == m)
        ret += tmp;
      else if (s[i - m] != 'B')
        ret += tmp * pre[i - m - 1] % MOD;
      fix(ret);
    }
  }
  printf("%d\n", ret);
  return 0;
}
