#include <bits/stdc++.h>
using namespace std;
int dp1[2005][1005][11], Q, n, x, p[4005], inv[4005], dp2[2005][2005][11],
    a1[2005], a2[2005], n1, n2, m, ans;
const int mu = 998244353;
inline int read() {
  char c = getchar();
  int t = 0;
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') t = t * 10 + c - '0', c = getchar();
  return t;
}
inline int ksm(int x, int y) {
  int ans = 1, now = x;
  for (; y; y >>= 1, now = 1ll * now * now % mu)
    if (y & 1) ans = 1ll * ans * now % mu;
  return ans;
}
int cal(int x, int y) {
  if (y == 0) return 1;
  x = y + x - 1;
  int t = inv[x - y] * 1ll * inv[y] % mu * p[x] % mu;
  return 1ll * p[y] * t % mu;
}
int main() {
  scanf("%d", &Q);
  p[0] = 1;
  for (int i = 1; i <= 4000; i++) p[i] = p[i - 1] * 1ll * i % mu;
  inv[0] = 1;
  inv[4000] = ksm(p[4000], mu - 2);
  for (int i = 3999; i; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % mu;
  while (Q--) {
    scanf("%d", &n);
    n1 = 0, n2 = 0;
    for (int i = 1; i <= n; i++) {
      x = read();
      int cnt = 0, w = 1, t = 0;
      while (x > 0) {
        cnt++;
        t += (x % 10) * w;
        w = w * (-1);
        x /= 10;
      }
      if (cnt & 1)
        a1[++n1] = (t + 11) % 11;
      else
        a2[++n2] = (t + 11) % 11;
    }
    m = (n1 + 1) / 2;
    ans = 0;
    dp1[0][0][0] = 1;
    for (int i = 0; i < n1; i++)
      for (int j = 0; j <= min(i, m); j++)
        for (int k = 0; k <= 10; k++) {
          dp1[i + 1][j + 1][(k + a1[i + 1] + 11) % 11] =
              ((dp1[i][j][k]) +
                           (dp1[i + 1][j + 1][(k + a1[i + 1] + 11) % 11]) >=
                       mu
                   ? (dp1[i][j][k]) +
                         (dp1[i + 1][j + 1][(k + a1[i + 1] + 11) % 11]) - mu
                   : (dp1[i][j][k]) +
                         (dp1[i + 1][j + 1][(k + a1[i + 1] + 11) % 11]));
          dp1[i + 1][j][(k - a1[i + 1] + 11) % 11] =
              ((dp1[i][j][k]) + (dp1[i + 1][j][(k - a1[i + 1] + 11) % 11]) >= mu
                   ? (dp1[i][j][k]) +
                         (dp1[i + 1][j][(k - a1[i + 1] + 11) % 11]) - mu
                   : (dp1[i][j][k]) +
                         (dp1[i + 1][j][(k - a1[i + 1] + 11) % 11]));
        }
    dp2[0][0][0] = 1;
    for (int i = 0; i < n2; i++)
      for (int j = 0; j <= i; j++)
        for (int k = 0; k <= 10; k++) {
          dp2[i + 1][j + 1][(k + a2[i + 1] + 11) % 11] =
              ((dp2[i][j][k]) +
                           (dp2[i + 1][j + 1][(k + a2[i + 1] + 11) % 11]) >=
                       mu
                   ? (dp2[i][j][k]) +
                         (dp2[i + 1][j + 1][(k + a2[i + 1] + 11) % 11]) - mu
                   : (dp2[i][j][k]) +
                         (dp2[i + 1][j + 1][(k + a2[i + 1] + 11) % 11]));
          dp2[i + 1][j][(k - a2[i + 1] + 11) % 11] =
              ((dp2[i][j][k]) + (dp2[i + 1][j][(k - a2[i + 1] + 11) % 11]) >= mu
                   ? (dp2[i][j][k]) +
                         (dp2[i + 1][j][(k - a2[i + 1] + 11) % 11]) - mu
                   : (dp2[i][j][k]) +
                         (dp2[i + 1][j][(k - a2[i + 1] + 11) % 11]));
        }
    if (n2 == 0)
      printf("%d\n", 1ll * dp1[n1][m][0] * p[n1 - m] % mu * p[m] % mu);
    else if (n1 == 0) {
      printf("%d\n", dp2[n2][0][0] * 1ll * p[n2] % mu);
    } else {
      for (int i = 0; i <= n2; i++)
        for (int k = 0; k <= 10; k++) {
          int t = cal(n1 - m + 1, i) * 1ll * cal(m, n2 - i) % mu;
          ans = ((1ll * t * p[n1 - m] % mu * p[m] % mu *
                  dp2[n2][i][(11 - k) % 11] % mu * dp1[n1][m][k] % mu) +
                             (ans) >=
                         mu
                     ? (1ll * t * p[n1 - m] % mu * p[m] % mu *
                        dp2[n2][i][(11 - k) % 11] % mu * dp1[n1][m][k] % mu) +
                           (ans)-mu
                     : (1ll * t * p[n1 - m] % mu * p[m] % mu *
                        dp2[n2][i][(11 - k) % 11] % mu * dp1[n1][m][k] % mu) +
                           (ans));
        }
      printf("%d\n", ans);
    }
    for (int i = 0; i <= n1 + 1; i++)
      for (int j = 0; j <= min(i, m) + 1; j++)
        for (int k = 0; k <= 10; k++) dp1[i][j][k] = 0;
    for (int i = 0; i <= n2; i++)
      for (int j = 0; j <= i; j++)
        for (int k = 0; k <= 10; k++) dp2[i][j][k] = 0;
  }
}
