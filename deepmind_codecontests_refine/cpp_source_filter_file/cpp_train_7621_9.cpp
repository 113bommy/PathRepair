#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
const int modu = 998244353;
long long d[maxn][maxn];
long long L[maxn], R[maxn], l[maxn], r[maxn];
long long disc1[maxn * 3], tot1, disc2[maxn * 3], tot2;
int n;
void exgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return;
  }
  long long tx, ty;
  exgcd(b, a % b, tx, ty);
  x = ty;
  y = tx - a / b * ty;
}
long long rev(long long a) {
  long long x, y;
  exgcd(a, modu, x, y);
  x %= modu;
  return (x + modu) % modu;
}
long long C(long long m, long long n) {
  long long res = 1;
  for (long long i = m; i >= m - n + 1; --i) res = res * i % modu;
  long long tmp = 1;
  for (int i = 1; i <= n; ++i) tmp = tmp * i % modu;
  return res * rev(tmp) % modu;
}
int main() {
  scanf("%d", &n);
  long long det = 1;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld%lld", &L[i], &R[i]);
    disc1[tot1++] = L[i];
    disc1[tot1++] = R[i];
    disc1[tot1++] = R[i] + 1;
    det = det * (R[i] - L[i] + 1) % modu;
  }
  sort(disc1, disc1 + tot1);
  tot2 = 0;
  disc2[0] = -1;
  for (int i = 0; i < tot1; ++i)
    if (disc2[tot2] < disc1[i]) disc2[++tot2] = disc1[i];
  for (int i = 1; i <= n; ++i) {
    l[i] = lower_bound(disc2, disc2 + tot2 + 1, L[i]) - disc2;
    r[i] = lower_bound(disc2, disc2 + tot2 + 1, R[i]) - disc2;
  }
  memset(d, 0, sizeof(d));
  for (int i = 0; i <= tot2 + 1; ++i) d[0][i] = 1;
  l[0] = r[0] = tot2;
  for (int i = 1; i <= n; ++i) {
    for (int j = l[i]; j <= r[i]; ++j) {
      d[i][j] = d[i - 1][j + 1] * (disc2[j + 1] - disc2[j]) % modu;
      for (int k = i - 1; k >= 1; --k)
        if (l[k] <= j && j <= r[k])
          d[i][j] = (d[i][j] + C(disc2[j + 1] - disc2[j] + i - k, i - k + 1) *
                                   d[k - 1][j + 1]) %
                    modu;
        else
          break;
    }
    for (int j = tot2; j >= 0; --j) d[i][j] = (d[i][j] + d[i][j + 1]) % modu;
  }
  printf("%lld\n", d[n][0] * rev(det) % modu);
  return 0;
}
