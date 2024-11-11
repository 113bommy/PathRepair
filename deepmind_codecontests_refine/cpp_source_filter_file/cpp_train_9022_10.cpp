#include <bits/stdc++.h>
template <typename Y>
inline bool updmin(Y &a, Y b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename Y>
inline bool updmax(Y &a, Y b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename Y>
inline Y abs(Y a) {
  if (a < 0) a = -a;
  return a;
}
template <typename Y>
inline Y sqr(Y a) {
  return a * a;
}
int read() {
  int w = 1, q = 0, ch = ' ';
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') w = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) q = q * 10 + ch - 48;
  return q * w;
}
inline void FileIO() {
  freopen(
      ""
      ".in",
      "r", stdin);
  freopen(
      ""
      ".out",
      "w", stdout);
}
const int N = 4010;
const int mod = 998244353;
int fn, gn, k;
long long f[N][80], g[N][80];
std::vector<int> F[N], G[N];
int inv[N], fac[N];
inline int C(int x, int y) {
  if (x < y || y < 0) return 0;
  return (long long)fac[x] * inv[y] % mod * inv[x - y] % mod;
}
long long sum[N][80], pd[N][80], dd[N][80];
void up(int x, int pre, std::vector<int> *G) {
  for (auto y : G[x]) {
    if (y != pre) {
      up(y, x, G);
    }
  }
  pd[x][0] = 1;
  memset(sum[x], 0, sizeof sum[x]);
  for (int i = 0; i <= k; i += 2) {
    for (auto y : G[x]) {
      (sum[x][i] += pd[y][i]) %= mod;
    }
  }
  for (int i = 2; i <= k; i += 2) {
    pd[x][i] = 0;
    for (int j = 0; j <= i - 2; j += 2) {
      (pd[x][i] += sum[x][j] * pd[x][i - j - 2]) %= mod;
    }
  }
}
void down(int x, int pre, std::vector<int> *G, long long f[][80]) {
  for (int i = 0; i <= k; i += 2) {
    (sum[x][i] += dd[x][i]);
  }
  f[x][0] = 1;
  for (int i = 2; i <= k; i += 2) {
    f[x][i] = 0;
    for (int j = 0; j <= i - 2; j += 2) {
      (f[x][i] += sum[x][j] * f[x][i - j - 2]) %= mod;
    }
  }
  for (auto y : G[x]) {
    if (y == pre) continue;
    for (int i = 0; i <= k; i += 2) {
      (sum[x][i] += mod - pd[y][i]) %= mod;
    }
    dd[y][0] = 1;
    for (int i = 2; i <= k; i += 2) {
      dd[y][i] = 0;
      for (int j = 0; j <= i - 2; j += 2) {
        (dd[y][i] += sum[x][j] * dd[y][i - j - 2]) %= mod;
      }
    }
    for (int i = 0; i <= k; i += 2) {
      (sum[x][i] += pd[y][i]) %= mod;
    }
    down(y, x, G, f);
  }
}
inline void DP(std::vector<int> *G, long long dp[][80]) {
  memset(sum, 0, sizeof sum);
  memset(pd, 0, sizeof pd);
  memset(dd, 0, sizeof dd);
  up(1, 0, G);
  down(1, 0, G, dp);
}
int main() {
  fn = read();
  gn = read();
  k = read();
  inv[0] = inv[1] = 1;
  for (int i = 2; i <= k; i++) {
    inv[i] = mod - (long long)mod / i * inv[mod % i] % mod;
  }
  fac[0] = fac[1] = 1;
  for (int i = 2; i <= k; i++) {
    inv[i] = (long long)inv[i] * inv[i - 1] % mod;
    fac[i] = (long long)fac[i - 1] * i % mod;
  }
  if (k & 1) {
    puts("0");
    return 0;
  }
  for (int i = 1; i < fn; i++) {
    int x = read(), y = read();
    F[x].push_back(y);
    F[y].push_back(x);
  }
  for (int i = 1; i < gn; i++) {
    int x = read(), y = read();
    G[x].push_back(y);
    G[y].push_back(x);
  }
  DP(F, f);
  DP(G, g);
  int ans = 0;
  for (int c = 0; c <= k; c += 2) {
    int x = 0, y = 0;
    for (int i = 1; i <= fn; i++) {
      (x += f[i][c]) %= mod;
    }
    for (int i = 1; i <= gn; i++) {
      (y += g[i][c]) %= mod;
    }
    ans = (ans + (long long)x * y % mod * C(k, c)) % mod;
  }
  printf("%d\n", ans);
  return 0;
}
