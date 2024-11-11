#include <bits/stdc++.h>
using namespace std;
const long long Maxn = 1e5 + 5;
const long long inf = 1e18, Mod = 998244353;
struct node {
  long long x, d1, d2, s, v;
} c[Maxn << 1];
long long n, m, ans, a[Maxn], b[Maxn], p[Maxn][2], val[Maxn << 2][2][2];
long long w[Maxn << 2], umid[Maxn << 2];
bool lit[Maxn][2][2];
long long qpow(long long x, long long k) {
  long long res = 1;
  while (k) {
    if (k & 1) res = res * x % Mod;
    k >>= 1;
    x = x * x % Mod;
  }
  return res;
}
void pushup(long long u) {
  for (long long i = 0; i < 2; i++)
    for (long long j = 0; j < 2; j++) {
      val[u][i][j] = 0;
      for (long long x = 0; x < 2; x++)
        for (long long y = 0; y < 2; y++)
          if (!lit[umid[u]][x][y])
            val[u][i][j] = (val[u][i][j] +
                            (val[u << 1][i][x] * val[u << 1 | 1][y][j]) % Mod) %
                           Mod;
    }
}
void build(long long l, long long r, long long u) {
  if (l == r) {
    val[u][0][0] = p[l][0];
    val[u][1][1] = p[l][1];
    return;
  }
  long long mid = (l + r) >> 1;
  umid[u] = mid;
  w[mid] = u;
  build(l, mid, u << 1);
  build(mid + 1, r, u << 1 | 1);
  pushup(u);
}
bool cmp(node x, node y) { return x.s * y.v < y.s * x.v; }
int main() {
  long long inv100 = qpow(100, Mod - 2);
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld%lld%lld", &a[i], &b[i], &p[i][1]);
    p[i][1] = p[i][1] * inv100 % Mod;
    p[i][0] = (1 - p[i][1] + Mod) % Mod;
  }
  build(1, n, 1);
  for (long long i = 2; i <= n; i++) {
    c[++m] = (node){i - 1, 1, 0, a[i] - a[i - 1], b[i - 1] + b[i]};
    if (b[i - 1] > b[i])
      c[++m] = (node){i - 1, 1, 1, a[i] - a[i - 1], b[i - 1] - b[i]};
    if (b[i - 1] < b[i])
      c[++m] = (node){i - 1, 0, 0, a[i] - a[i - 1], b[i] - b[i - 1]};
  }
  sort(c + 1, c + 1 + m, cmp);
  long long lst = 1, now;
  for (long long i = 1; i <= m; i++) {
    lit[c[i].x][c[i].d1][c[i].d2] = 1;
    for (long long u = w[c[i].x]; u; u >>= 1) pushup(u);
    now = (val[1][0][0] + val[1][0][1] + val[1][1][0] + val[1][1][1]) % Mod;
    ans =
        (ans + c[i].s * qpow(c[i].v, Mod - 2) % Mod * (lst - now + Mod) % Mod) %
        Mod;
    lst = now;
  }
  printf("%lld\n", ans);
  return 0;
}
