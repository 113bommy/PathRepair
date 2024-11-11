#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int n;
int cnt1, cnt2;
long long fac[2005], a[2005], b[2005];
long long c[2005][2005], dp1[2][2005][11], dp2[2][2005][11];
int lowbit(int now) { return (now & (-now)); }
int getlen(int now) {
  int res = 0;
  while (now) {
    res++;
    now /= 10;
  }
  return res;
}
long long getans(long long x, long long y) {
  if (y != 0)
    return (fac[x] * c[x + y - 1][y - 1]) % mod;
  else if (x)
    return 0;
  return 1;
}
int main() {
  fac[0] = 1;
  for (int i = 1; i <= 2000; i++) fac[i] = (fac[i - 1] * i) % mod;
  c[0][0] = 1;
  for (int i = 1; i <= 2000; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < 2000; j++)
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
  }
  int _;
  scanf("%d", &_);
  while (_--) {
    memset(dp1, 0, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    cnt1 = cnt2 = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      int x;
      scanf("%d", &x);
      int len = getlen(x);
      if (len & 1)
        a[++cnt1] = x % 11;
      else
        b[++cnt2] = x % 11;
    }
    dp1[0][0][0] = dp2[0][0][0] = 1;
    for (int i = 1; i <= cnt1; i++) {
      memset(dp1[i & 1], 0, sizeof(dp1[i & 1]));
      for (int j = 0; j <= cnt1 / 2; j++) {
        for (int k = 0; k <= 10; k++) {
          dp1[i & 1][j][k] = dp1[(i & 1) ^ 1][j][((k - a[i]) % 11 + 11) % 11];
          if (j != 0)
            dp1[i & 1][j][k] += dp1[(i & 1) ^ 1][j - 1][(k + a[i]) % 11];
          if (dp1[i & 1][j][k] >= mod) dp1[i & 1][j][k] -= mod;
        }
      }
    }
    for (int i = 1; i <= cnt2; i++) {
      memset(dp2[i & 1], 0, sizeof(dp2[i & 1]));
      for (int j = 0; j <= cnt2; j++) {
        for (int k = 0; k <= 10; k++) {
          dp2[i & 1][j][k] = dp2[(i & 1) ^ 1][j][(k - b[i] + 11) % 11];
          if (j != 0)
            dp2[i & 1][j][k] += dp2[(i & 1) ^ 1][j - 1][(k + b[i]) % 11];
          if (dp2[i & 1][j][k] >= mod) dp2[i & 1][j][k] -= mod;
        }
      }
    }
    for (int k = 0; k <= 10; k++) {
      dp1[cnt1 & 1][cnt1 / 2][k] = (dp1[cnt1 & 1][cnt1 / 2][k] * fac[cnt1 / 2] %
                                    mod * fac[cnt1 - cnt1 / 2]) %
                                   mod;
    }
    long long ans = 0;
    for (int i = 0; i <= cnt2; i++) {
      for (int j = 0; j <= 10; j++) {
        long long temp =
            (dp1[cnt1 & 1][cnt1 / 2][j] * dp2[cnt2 & 1][i][(11 - j) % 11]) %
            mod;
        temp = (temp * getans(i, (cnt1 + 1) / 2)) % mod;
        temp = (temp * getans(cnt2 - i, cnt1 + 1 - (cnt1 + 1) / 2)) % mod;
        ans = (ans + temp) % mod;
      }
    }
    printf("%I64d\n", ans);
  }
}
