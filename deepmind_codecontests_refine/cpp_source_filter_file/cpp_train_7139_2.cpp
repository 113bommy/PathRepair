#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
struct CP {
  double x, y;
  CP(double xx = 0, double yy = 0) { x = xx, y = yy; }
};
const double pi = acos(-1);
CP operator+(CP aa, CP bb) { return CP(aa.x + bb.x, aa.y + bb.y); }
CP operator-(CP aa, CP bb) { return CP(aa.x - bb.x, aa.y - bb.y); }
CP operator*(CP aa, CP bb) {
  return CP(aa.x * bb.x - aa.y * bb.y, aa.y * bb.x + aa.x * bb.y);
}
int pp[N];
void FFT(CP *f, int len, int flag) {
  for (int i = 0, iE = len - 1; i <= iE; i++)
    if (pp[i] < i) swap(f[i], f[pp[i]]);
  for (int i = 2; i <= len; i <<= 1) {
    CP ch(cos(2 * pi / i), flag * sin(2 * pi / i));
    for (int j = 0, l = (i >> 1); j < len; j += i) {
      CP now(1, 0);
      for (int k = j; k < j + l; k++) {
        CP nowa = f[k], nowb = f[k + l] * now;
        f[k] = nowa + nowb, f[k + l] = nowa - nowb, now = now * ch;
      }
    }
  }
  if (flag == -1)
    for (int i = 0, iE = len - 1; i <= iE; i++) f[i].x /= len;
}
int n, m, lim = 1, mod, jc[N], njc[N], Ans = 1;
int dp[2][N], ans[N], sav[2][N], G[N];
CP aa[N], bb[N], a_[N], b_[N], P0[N], P1[N], P2[N];
void Mul(int *a, int *b, int *ans) {
  for (int i = 0, iE = lim - 1; i <= iE; i++)
    aa[i].x = aa[i].y = bb[i].x = bb[i].y = a_[i].x = b_[i].x = a_[i].y =
        b_[i].y = P0[i].x = P0[i].y = P1[i].x = P1[i].y = P2[i].x = P2[i].y = 0;
  for (int i = 0, iE = n; i <= iE; i++)
    aa[i].x = (a[i] & 1023), a_[i].x = (a[i] >> 10), bb[i].x = (b[i] & 1023),
    b_[i].x = (b[i] >> 10);
  FFT(aa, lim, 1), FFT(bb, lim, 1), FFT(a_, lim, 1), FFT(b_, lim, 1);
  for (int i = 0, iE = lim - 1; i <= iE; i++)
    P0[i] = aa[i] * bb[i], P1[i] = aa[i] * b_[i] + a_[i] * bb[i],
    P2[i] = b_[i] * a_[i];
  FFT(P0, lim, -1), FFT(P1, lim, -1), FFT(P2, lim, -1);
  for (int i = 0, iE = n; i <= iE; i++)
    ans[i] = ((long long)(P0[i].x + 0.49) +
              ((long long)(P1[i].x + 0.49) << 10) % mod +
              ((long long)(P2[i].x + 0.49) << 20) % mod) %
             mod;
}
int main() {
  scanf("%d%d%d", &n, &m, &mod);
  if (m <= 2) return printf("0\n"), 0;
  for (; lim <= n * 2 + 1; lim <<= 1)
    ;
  for (int i = 0, iE = lim - 1; i <= iE; i++)
    pp[i] = ((pp[i >> 1] >> 1) | ((i & 1) * (lim >> 1)));
  dp[1][1] = 1;
  int now = 1;
  for (int i = log2(m) - 1, iE = 1; i >= iE; i--) {
    for (int t = 0, tE = 1; t <= tE; t++) {
      for (int j = 1, jE = n; j <= jE; j++) G[j] = (dp[0][j] + dp[1][j]) % mod;
      G[0] = 1;
      Mul(G, dp[(now & 1) ^ t], sav[t]);
      for (int j = 1, jE = n; j <= jE; j++) (sav[t][j] += dp[t][j]) %= mod;
    }
    for (int t = 0, tE = 1; t <= tE; t++)
      for (int j = 1, jE = n; j <= jE; j++) dp[t][j] = sav[t][j], sav[t][j] = 0;
    now <<= 1;
    if ((m >> i) & 1) {
      now++;
      for (int j = n, jE = 1; j >= jE; j--)
        (dp[now & 1][j] += (dp[0][j - 1] + dp[1][j - 1]) % mod) %= mod;
      (dp[now & 1][1] += 1) %= mod;
    }
    for (int i = 1; i <= n; i += 2) (Ans += dp[1][i]) %= mod;
  }
  printf("%d\n", Ans);
  return 0;
}
