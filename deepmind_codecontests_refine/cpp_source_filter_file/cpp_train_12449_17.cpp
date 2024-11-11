#include <bits/stdc++.h>
using namespace std;
long long dp[17][65538][17];
char a[20];
long long b[20];
long long mo[1100005];
long long f(long long m, long long p, long long pos) {
  if (dp[m][p][pos] != -1) return dp[m][p][pos];
  if (pos == 0) {
    if (((1 << m) & p))
      dp[m][p][pos] = 1;
    else
      dp[m][p][pos] = 0;
    return dp[m][p][pos];
  }
  long long j = 0;
  for (long long i = 0; i <= 15; i++) {
    j += f(max(m, i), mo[p * 16 + i], pos - 1);
  }
  return dp[m][p][pos] = j;
}
int main() {
  long long t, n, i, j, k, l, r, m, p, ans1;
  mo[0] = 0;
  for (i = 1; i <= 1100000; i++) {
    mo[i] = mo[i - 1] + 1;
    if (mo[i] == 65536) mo[i] = 0;
  }
  memset(dp, -1, sizeof dp);
  f(0, 0, 14);
  scanf("%I64d", &t);
  while (t--) {
    scanf("%s", a);
    n = strlen(a);
    l = 0;
    for (i = 0; i < n; i++) {
      l = l * 16;
      if (a[i] >= '0' && a[i] <= '9')
        l += a[i] - '0';
      else
        l += a[i] - 'a' + 10;
    }
    ans1 = 0;
    if (l > 0) {
      l--;
      j = l;
      for (i = 0; i < n; i++) {
        b[i] = j % 16;
        j /= 16;
      }
      m = p = 0;
      for (j = n - 1; j >= 0; j--) {
        for (k = 0; k < b[j]; k++) ans1 -= dp[max(m, k)][mo[p * 16 + k]][j];
        m = max(m, b[j]);
        p = mo[p * 16 + b[j]];
      }
      ans1 -= dp[m][p][0];
    }
    scanf("%s", a);
    n = strlen(a);
    r = 0;
    for (i = 0; i < n; i++) {
      r = r * 16;
      if (a[i] >= '0' && a[i] <= '9')
        r += a[i] - '0';
      else
        r += a[i] - 'a' + 10;
    }
    j = r;
    for (i = 0; i < n; i++) {
      b[i] = j % 16;
      j /= 16;
    }
    m = p = 0;
    for (j = n - 1; j >= 0; j--) {
      for (k = 0; k < b[j]; k++) ans1 += dp[max(m, k)][mo[p * 16 + k]][j];
      m = max(m, b[j]);
      p = mo[p * 16 + b[j]];
    }
    ans1 += dp[m][p][0];
    printf("%I64d\n", ans1);
  }
  return 0;
}
