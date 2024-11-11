#include <bits/stdc++.h>
using namespace std;
const int M = 100005;
long long read() {
  long long x = 0, f = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9') {
    if (c == '-') f = -1;
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
long long n, k, r, t, h[M], rk[M];
double m, p[M], g[M];
struct mat {
  double a[4][4];
  mat() { memset(a, 0, sizeof a); }
  mat operator*(const mat &b) const {
    mat r;
    for (long long i = 1; i <= 3; i++)
      for (long long j = 1; j <= 3; j++)
        for (long long k = 1; k <= 3; k++) r.a[i][k] += a[i][j] * b.a[j][k];
    return r;
  }
} dp, A[35];
double Abs(double x) { return x > 0 ? x : -x; }
double get(double x, long long i) { return p[i] * x + g[i]; }
bool cmp(long long a, long long b) {
  if (Abs(p[a] - p[b]) < 1e-14) return g[a] > g[b];
  return p[a] < p[b];
}
mat con(long long x) {
  mat r;
  r.a[2][2] = r.a[3][2] = r.a[3][3] = 1;
  r.a[1][1] = 1 - p[x];
  r.a[2][1] = p[x] * m;
  r.a[3][1] = g[x];
  return r;
}
signed main() {
  n = read();
  t = read();
  for (long long i = 1; i <= n; i++) {
    double a, b;
    rk[i] = i;
    scanf("%lf %lf %lf", &a, &b, &p[i]);
    m = max(m, b * p[i]);
    g[i] = a * p[i];
  }
  sort(rk + 1, rk + 1 + n, cmp);
  for (long long j = 1; j <= n; j++) {
    long long i = rk[j];
    while (k > 1 && (g[i] - g[h[k]]) * (p[h[k]] - p[h[k - 1]]) >=
                        (g[h[k]] - g[h[k - 1]]) * (p[i] - p[h[k]]))
      k--;
    h[++k] = i;
  }
  dp.a[1][3] = 1;
  double sp = 0;
  for (long long f = 1, now = 0; f <= k;) {
    while (f <= k && get(sp, h[f]) <= get(sp, h[f + 1])) f++;
    A[0] = con(h[f]);
    for (long long i = 1; i <= 34; i++) A[i] = A[i - 1] * A[i - 1];
    for (long long i = 34; i >= 0; i--) {
      if (now + (1ll << i) >= t) continue;
      mat tmp = dp;
      tmp = tmp * A[i];
      double cur = tmp.a[1][2] * m - tmp.a[1][1];
      if (f == k || get(cur, h[f]) >= get(cur, h[f + 1])) {
        now += (1ll << i);
        dp = tmp;
        sp = cur;
      }
    }
    dp = dp * A[0];
    now++;
    sp = now * m - dp.a[1][1];
    if (now == t) break;
  }
  printf("%.8f\n", dp.a[1][1]);
}
