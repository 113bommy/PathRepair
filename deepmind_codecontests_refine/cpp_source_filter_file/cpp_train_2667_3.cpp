#include <bits/stdc++.h>
int n, t, cnt[2], a[2001], b[2001][2], tt1;
long long mo, f[2001][11][2], dp[2001][11][2], ans[11], tt, tt2, qi[2001], anss,
    s[2001][2001];
int count(int aa) {
  int ss = 0;
  while (aa != 0) {
    aa = aa / 10;
    ss++;
  }
  return (ss);
}
int main() {
  scanf("%d", &t);
  mo = 998244353;
  qi[0] = 1;
  for (long long i = 1; i <= 2000; i++) qi[i] = (qi[i - 1] * i) % mo;
  for (int i = 1; i <= 2000; i++) s[0][i] = 1;
  for (int i = 1; i <= 2000; i++)
    for (int j = 1; j <= 2000; j++) s[i][j] = 0;
  for (int i = 1; i <= 2000; i++) s[1][i] = i;
  for (int i = 2; i <= 2000; i++) {
    long long ss = 0;
    for (int j = 1; j <= 2000; j++) s[i][j] = (s[i][j - 1] + s[i - 1][j]) % mo;
  }
  for (int iii = 1; iii <= t; iii++) {
    scanf("%d", &n);
    cnt[0] = 0;
    cnt[1] = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
      if ((count(a[i])) % 2 == 1) {
        cnt[1]++;
        b[cnt[1]][1] = a[i] % 11;
      } else {
        cnt[0]++;
        b[cnt[0]][0] = a[i] % 11;
      }
    }
    tt = cnt[1] / 2;
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= 10; j++)
        for (int k = 0; k <= 1; k++) {
          dp[i][j][k] = 0;
          f[i][j][k] = 0;
        }
    dp[0][0][0] = 1;
    for (int i = 1; i <= cnt[1]; i++) {
      int l = i % 2, r = 1 - l;
      for (int k = 0; k <= 10; k++) {
        int dbd = (k + b[i][1] * 10) % 11;
        for (int j = 1; j <= tt; j++)
          dp[j][dbd][l] = (dp[j][dbd][l] + dp[j - 1][k][r]) % mo;
      }
      for (int k = 0; k <= 10; k++) {
        int dbd = (k + b[i][1]) % 11;
        for (int j = 0; j <= tt; j++) {
          dp[j][dbd][l] = (dp[j][dbd][l] + dp[j][k][r]) % mo;
          dp[j][k][r] = 0;
        }
      }
    }
    f[0][0][0] = 1;
    for (int i = 1; i <= cnt[0]; i++) {
      int l = i % 2, r = 1 - l;
      for (int k = 0; k <= 10; k++) {
        int dbd = (k + b[i][0] * 10) % 11;
        for (int j = 1; j <= i; j++)
          f[j][dbd][l] = (f[j][dbd][l] + f[j - 1][k][r]) % mo;
      }
      for (int k = 0; k <= 10; k++) {
        int dbd = (k + b[i][0]) % 11;
        for (int j = 0; j <= i; j++) {
          f[j][dbd][l] = (f[j][dbd][l] + f[j][k][r]) % mo;
          f[j][k][r] = 0;
        }
      }
    }
    tt1 = cnt[0] % 2;
    tt = (cnt[1] + 1) / 2;
    tt2 = cnt[1] + 1 - tt;
    for (int i = 0; i <= 10; i++) ans[i] = 0;
    for (int i = 0; i <= cnt[0]; i++)
      for (int j = 0; j <= 10; j++)
        ans[j] =
            (ans[j] +
             ((((f[i][j][tt1] * s[i][tt]) % mo) * s[cnt[0] - i][tt2]) % mo) *
                 ((qi[i] * qi[cnt[0] - i]) % mo)) %
            mo;
    tt1 = cnt[1] % 2;
    tt = cnt[1] / 2;
    anss = 0;
    for (int j = 0; j <= 10; j++) {
      int hh = (11 - j) % 11;
      ;
      anss = (anss + ans[j] * dp[tt][hh][tt1]) % mo;
    }
    anss = (anss * qi[tt]) % mo;
    anss = (anss * qi[cnt[1] - tt]) % mo;
    printf("%I64d\n", anss);
  }
}
