#include <bits/stdc++.h>
const int MAXN = 2010;
const int MAXM = 200010;
const long long MOD = 1e9 + 7;
long long f[MAXN];
long long fac[MAXM], inv[MAXM];
struct node {
  int x, y;
  node(int x = 0, int y = 0) : x(x), y(y) {}
  inline bool operator<(const node &rhs) const {
    return (x == rhs.x) ? (y < rhs.y) : (x < rhs.x);
  }
} p[MAXN];
int n, h, w;
inline long long qpow(long long a, int b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}
void getinv() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i <= h + w + 2; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = qpow(fac[i], MOD - 2);
  }
}
long long c(int p, int q) { return fac[p] * inv[q] % MOD * inv[p - q] % MOD; }
int main() {
  getinv();
  scanf("%d%d%d", &h, &w, &n);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    p[i] = node(x, y);
  }
  std::sort(p + 1, p + n + 1);
  p[n + 1] = node(h, w);
  for (int i = 1; i <= n + 1; i++) {
    f[i] = c(p[i].x - 1 + p[i].y - 1, p[i].x - 1);
    for (int j = 1; j < i; j++) {
      if (p[j].x > p[i].x || p[j].y > p[i].y) continue;
      f[i] -= c((p[i].x + p[i].y) - (p[j].x + p[j].y), p[i].x - p[j].x) * f[j];
      f[i] = (f[i] + MOD) % MOD;
    }
  }
  printf("%I64d\n", (f[n + 1] + MOD) % MOD);
  return 0;
}
