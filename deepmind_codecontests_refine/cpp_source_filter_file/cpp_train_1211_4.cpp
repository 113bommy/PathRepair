#include <bits/stdc++.h>
using namespace std;
void qmax(int &x, int y) {
  if (x < y) x = y;
}
void qmin(int &x, int y) {
  if (x > y) x = y;
}
inline int read() {
  char s;
  int k = 0, base = 1;
  while ((s = getchar()) != '-' && s != EOF && !(isdigit(s)))
    ;
  if (s == EOF) exit(0);
  if (s == '-') base = -1, s = getchar();
  while (isdigit(s)) {
    k = k * 10 + (s ^ '0');
    s = getchar();
  }
  return k * base;
}
inline void write(int x) {
  static char cnt, num[15];
  cnt = 0;
  if (!x) {
    putchar('0');
    return;
  }
  for (; x; x /= 10) num[++cnt] = x % 10;
  for (; cnt; putchar(num[cnt--] + 48))
    ;
}
const int maxn = 110;
const long long mod = 1e9 + 7;
long long dp[110][110][110];
long long g[110][110];
int n, id, po[maxn], ne[maxn * 2], to[maxn * 2], X, Y;
int sz[maxn];
void add(int x, int y) {
  id++;
  to[id] = y;
  ne[id] = po[x];
  po[x] = id;
}
void Mod(long long x) {
  if (x >= mod) x -= mod;
}
void f(int x, int Fa) {
  sz[x] = 1;
  dp[x][1][1] = 1;
  for (int i = po[x]; i; i = ne[i]) {
    if (Fa == to[i]) continue;
    f(to[i], x);
    memset(g, 0, sizeof(g));
    for (int p = 1; p <= sz[x]; p++)
      for (int k = 1; k <= (sz[x] - p + 1); k++)
        if (dp[x][p][k] != 0) {
          for (int q = 1; q <= sz[to[i]]; q++)
            for (int s = 1; s <= sz[to[i]] - q + 1; s++) {
              g[p + q][k] += dp[x][p][k] * dp[to[i]][q][s] % mod * s % mod;
              Mod(g[p + q][k]);
              g[p + q - 1][k + s] += dp[x][p][k] * dp[to[i]][q][s] % mod;
              Mod(g[p + q - 1][k + s]);
            }
        }
    sz[x] += sz[to[i]];
    for (int p = 1; p <= sz[x]; p++)
      for (int k = 1; k <= sz[x]; k++) dp[x][p][k] = g[p][k];
  }
}
long long ans[maxn];
long long jie[maxn * 2], ny[maxn];
long long ksm(long long x, int y) {
  if (y < 0) return 0;
  long long sum = 1;
  while (y) {
    if (y & 1) sum = sum * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return sum;
}
long long C(int y, int x) { return jie[y] * ny[x] % mod * ny[y - x] % mod; }
int main() {
  n = read();
  jie[0] = 1;
  for (int i = 1; i < n; i++) {
    X = read();
    Y = read();
    add(X, Y);
    add(Y, X);
  }
  for (int i = 1; i <= n; i++) {
    jie[i] = jie[i - 1] * i % mod;
    ny[i] = ksm(jie[i], mod - 2);
  }
  ny[0] = ny[1];
  f(1, 0);
  ans[n - 1] = dp[1][1][n];
  for (int i = 0; i < n - 1; i++) {
    for (int j = 1; j <= min(n, i + 1); j++)
      ans[i] += dp[1][n - i][j] * j % mod, Mod(ans[i]);
    ans[i] = ans[i] * ksm(n, n - i - 2) % mod;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1, cur = -1; j < n; j++, cur = -cur) {
      ans[i] += (long long)cur * ans[j] * C(j, i) % mod;
      ans[i] %= mod;
    }
    if (ans[i] < 0) ans[i] += mod;
    printf("%lld ", ans[i]);
  }
  return 0;
}
