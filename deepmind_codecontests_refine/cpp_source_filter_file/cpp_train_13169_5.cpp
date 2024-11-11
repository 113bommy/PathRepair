#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000009;
struct sett {
  long long k[50][50];
} ans, base;
long long N, n, m, q;
long long mp[25][25];
sett mul(sett a, sett b) {
  sett c;
  memset(c.k, 0, sizeof(c.k));
  for (long long i = 1; i <= N; i++)
    for (long long r = 1; r <= N; r++)
      for (long long p = 1; p <= N; p++)
        c.k[i][r] = (c.k[i][r] + a.k[i][p] * b.k[p][r]) % mod;
  return c;
}
void qpow(long long b) {
  for (; b; b >>= 1, base = mul(base, base))
    if (b & 1) ans = mul(base, ans);
}
void build() {
  for (long long i = 1; i <= N; i++)
    for (long long r = 1; r <= N; r++) {
      long long a = ((i - 1) / m) + 1, b = (i - 1) % m + 1;
      long long A = ((r - 1) / m) + 1, B = (r - 1) % m + 1;
      long long dist = abs(A - a) + abs(B - b);
      if (mp[a][b] == 0 && mp[A][B] == 0 && dist <= 1)
        base.k[i][r] = 1;
      else
        base.k[i][r] = 0;
    }
}
signed main() {
  scanf("%lld%lld%lld", &n, &m, &q);
  N = n * m;
  ans.k[1][1] = 1;
  long long plk = 1;
  while (q--) {
    build();
    long long op, x, y, t;
    scanf("%lld%lld%lld%lld", &op, &x, &y, &t);
    qpow(t - plk);
    plk = t;
    if (op == 2) ans.k[(x - 1) * m + y][1] = 0, mp[x][y] = 1;
    if (op == 3) ans.k[(x - 1) * m + y][1] = 0, mp[x][y] = 0;
    if (op == 1) printf("%lld\n", ans.k[(x - 1) * m + y][1]);
  }
}
