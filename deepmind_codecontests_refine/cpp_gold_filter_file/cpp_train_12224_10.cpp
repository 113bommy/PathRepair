#include <bits/stdc++.h>
using namespace std;
const long long N = 1005, M = 1e9 + 7;
struct Ask {
  long double x, y, d;
} A[N * N];
long double x1, x2, ___y1, y2, x[N], y[N];
long long tot, n;
long long ksm(long long x, long long y) {
  long long ans = 1;
  for (; y; y >>= 1, x = x * x % M)
    if (y & 1) (ans *= x) %= M;
  return ans;
}
long long cmp(Ask x, Ask y) {
  if (fabs(x.x - y.x) >= 1e-9) return x.x < y.x;
  if (fabs(x.y - y.y) >= 1e-9) return x.y < y.y;
  return x.d < y.d;
}
signed main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) {
    scanf("%Lf%Lf%Lf%Lf", &x1, &x2, &___y1, &y2);
    x[i] = x1 / x2;
    y[i] = ___y1 / y2;
    long double len = sqrt(x[i] * x[i] + y[i] * y[i]);
    x[i] /= len * len;
    y[i] /= len * len;
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++)
    for (long long j = i + 1; j <= n; j++) {
      tot++;
      A[tot].x = x[i] + x[j];
      A[tot].y = y[i] + y[j];
      A[tot].d =
          fabs(x[i] - x[j]) < 1e-9 ? 1e18 : (y[i] - y[j]) / (x[i] - x[j]);
    }
  sort(A + 1, A + tot + 1, cmp);
  for (long long i = 1, j = 1; i <= tot; i = j) {
    while (j <= tot && fabs(A[i].x - A[j].x) < 1e-9 &&
           fabs(A[i].y - A[j].y) < 1e-9)
      j++;
    long long num = 1, cnt = 2;
    for (long long k = i + 1; k <= j; k++)
      if (k == j || fabs(A[k].d - A[k - 1].d > 1e-9))
        (num *= cnt) %= M, cnt = 2;
      else
        cnt++;
    ans = (ans + num + 1ll * M - (j - i + 1)) % M;
  }
  printf("%lld\n", (ans + M) % M);
}
