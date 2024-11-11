#include <bits/stdc++.h>
const int mod = 998244353, N = 3600;
int n, m, k, dp[N][N], row[N], col[N], factor[N], ifactor[N];
bool ban_x[N], ban_y[N];
void up(int &x, int y) { x += y - mod, x += x >> 31 & mod; }
void up(int &x, int y, int z) { x = (x + (long long)y * z) % mod; }
int pow(int x, int y, int ans = 1) {
  for (; y; y >>= 1, x = (long long)x * x % mod)
    if (y & 1) ans = (long long)ans * x % mod;
  return ans;
}
void convolute(int *a, int *b, int &n, int m) {
  static int ret[N];
  std::memset(ret, 0, n + m + 1 << 2);
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= m; ++j) up(ret[i + j], a[i], b[j]);
  std::memcpy(a, ret, n + m + 1 << 2), n += m;
}
int max = 2;
void init(int n) {
  factor[0] = 1;
  for (int i = 1; i <= n; ++i) factor[i] = (long long)factor[i - 1] * i % mod;
  ifactor[n] = pow(factor[n], mod - 2);
  for (int i = n; i; --i) ifactor[i - 1] = (long long)ifactor[i] * i % mod;
}
int power(int x, int y) {
  return x < y ? 0 : (long long)factor[x] * ifactor[x - y] % mod;
}
void upto(int q) {
  for (; max <= q; ++max) {
    for (int i = 1; i <= max / 2; ++i)
      up(dp[max][i] = dp[max - 1][i], dp[max - 2][i - 1]);
  }
}
int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  std::cin >> n >> m >> k, k *= 2, init(std::max(n, m));
  row[0] = col[0] = 1;
  for (int i = 0; i <= std::max(n, m); ++i) dp[i][0] = 1;
  for (int i = 1, x, y; i <= k; ++i)
    std::cin >> x >> y, ban_x[x] = ban_y[y] = 1;
  ban_x[n + 1] = ban_y[m + 1] = 1;
  int lst = 0, rsize = 0, csize = 0;
  int rtot = 0, ctot = 0;
  for (int i = 1; i <= n + 1; ++i)
    if (ban_x[i]) {
      if (i - lst > 1) {
        int t = i - lst - 1;
        upto(t), rtot += t;
        convolute(row, dp[t], rsize, t / 2);
      }
      lst = i;
    }
  lst = 0;
  for (int i = 1; i <= m + 1; ++i)
    if (ban_y[i]) {
      if (i - lst > 1) {
        int t = i - lst - 1;
        upto(t), ctot += t;
        convolute(col, dp[t], csize, t / 2);
      }
      lst = i;
    }
  int ans = 0;
  for (int i = 0; i <= rsize; ++i)
    for (int j = 0; j <= csize; ++j)
      ans = (ans + (long long)row[i] * col[j] % mod * power(rtot - i * 2, j) %
                       mod * power(ctot - j * 2, i)) %
            mod;
  std::cout << ans << '\n';
  return 0;
}
