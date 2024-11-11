#include <bits/stdc++.h>
const int mod = 1e9 + 7;
int n, l, fac[2000005], ifac[2000005], ans1, ans2, X[2000005], Y[2000005];
void NoAnswer() {
  puts("NO");
  exit(0);
}
long long s[2000005], tx, ty, N[2000005], M[2000005], D[2000005], LB[2000005],
    RB[2000005], tl, x[2000005], y[2000005], t[2000005];
char ORD[] = "DLRU";
struct point {
  long long t, x, y, w;
} p[2000005];
int cmp(point a, point b) { return a.w < b.w; }
int binom(int n, int m) {
  if (n < 0 || m < 0 || n < m) return 0;
  return (long long)fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
void build(long long *t, long long *x, int *B) {
  tl = 0;
  long long L = 0, R = l;
  t[0] = 0;
  x[0] = 0;
  for (int i = 1; i <= n; ++i) {
    if (t[i] / l != t[i - 1] / l) {
      D[++tl] = t[i] / l - t[i - 1] / l;
      N[tl] = t[i] % l - t[i - 1] % l;
      M[tl] = x[i] - x[i - 1];
      LB[tl] = t[i - 1] % l;
      RB[tl] = t[i] % l;
      long long lb, rb;
      if (D[tl] > 0) {
        lb = (M[tl] - N[tl]) / D[tl];
        rb = M[tl] / D[tl];
      } else {
        lb = M[tl] / D[tl];
        rb = (M[tl] - N[tl]) / D[tl];
      }
      L = std::max(lb, L);
      R = std::min(rb, R);
    } else {
      if (x[i] - x[i - 1] > t[i] % l - t[i - 1] % l || x[i] < x[i - 1])
        NoAnswer();
      for (int j = t[i - 1] % l;
           j < t[i] % l && j - t[i - 1] % l < x[i] - x[i - 1]; ++j)
        B[j] = 1;
    }
  }
  int ans = 0;
  for (int vx = L; vx <= R; ++vx) {
    int tot = 1;
    for (int j = 1; j <= tl; ++j) {
      tot = (long long)tot * binom(N[j], (long long)M[j] - vx * D[j]) % mod;
    }
    long long d1 = vx - (x[n] - (long long)(t[n] / l) * vx);
    if (d1 < 0 || d1 > l) continue;
    tot = (long long)tot * binom(l - t[n] % l, d1) % mod;
    if (tot) {
      for (int j = 1; j <= tl; ++j) {
        long long cnt = M[j] - vx * D[j];
        for (int i = LB[j]; i < RB[j] && i - LB[j] < cnt; ++i) B[i] = 1;
      }
      for (int i = t[n] % l; i < l && i - t[n] % l < d1; ++i) B[i] = 1;
      return;
    }
  }
  NoAnswer();
}
int main() {
  scanf("%d%d", &n, &l);
  fac[0] = ifac[0] = ifac[1] = 1;
  for (int i = 1; i <= l; ++i) fac[i] = (long long)fac[i - 1] * i % mod;
  for (int i = 2; i <= l; ++i)
    ifac[i] = (long long)(mod - mod / i) * ifac[mod % i] % mod;
  for (int i = 2; i <= l; ++i) ifac[i] = (long long)ifac[i] * ifac[i - 1] % mod;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld%lld%lld", &p[i].t, &tx, &ty);
    if ((tx + ty + p[i].t) % 2 || (ty - tx + p[i].t) % 2) {
      puts("NO");
      return 0;
    }
    p[i].x = (tx + ty + p[i].t) / 2;
    p[i].y = (ty - tx + p[i].t) / 2;
    p[i].w = p[i].t % l;
  }
  std::sort(p + 1, p + n + 1, cmp);
  for (int i = 1; i <= n; ++i) {
    t[i] = p[i].t, x[i] = p[i].x;
    y[i] = p[i].y;
  }
  build(t, x, X);
  build(t, y, Y);
  for (int i = 0; i < l; ++i) printf("%c", ORD[X[i] * 2 + Y[i]]);
  return 0;
}
