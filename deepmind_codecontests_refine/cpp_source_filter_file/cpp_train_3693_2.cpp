#include <bits/stdc++.h>
using namespace std;
const int maxn = 210, maxk = 1010, K = 1000, mod = 10007;
namespace BM {
inline int pow_mod(int x, int n = mod - 2) {
  int y = 1;
  while (n) {
    if (n & 1) y = (long long)y * x % mod;
    x = (long long)x * x % mod;
    n >>= 1;
  }
  return y;
}
const int maxn = 1e4 + 10;
vector<int> p[2], t, P, x, y;
int pn, fail[2], dlt[maxn], N, f[maxn];
void B(int n, int *x) {
  fail[1] = -1;
  for (int i = 0; i < n; ++i) {
    f[i] = x[i];
    int dt = -x[i];
    auto &cur = p[pn];
    for (int j = 0; j < cur.size(); ++j)
      dt = ((long long)x[i - j - 1] * cur[j] + dt) % mod;
    if (!(dlt[i] = dt)) continue;
    fail[pn] = i;
    if (!~fail[pn ^ 1]) {
      pn ^= 1;
      p[pn].resize(i + 1);
      continue;
    }
    auto &ls = p[pn ^ 1];
    t.clear();
    t.resize(i - fail[pn ^ 1] - 1);
    int k = -(long long)pow_mod(dlt[fail[pn ^ 1]]) * dt % mod;
    t.push_back(-k);
    for (auto &x : ls) t.push_back((long long)x * k % mod);
    if (t.size() < cur.size()) t.resize(cur.size());
    for (int j = 0; j < cur.size(); ++j) t[j] = (t[j] + cur[j]) % mod;
    ls = t;
    pn ^= 1;
  }
  P = p[pn];
  N = P.size();
  return;
}
inline void mul(vector<int> &a, vector<int> &b, vector<int> &c) {
  static int d[maxn << 1];
  int na = a.size(), nb = b.size(), n = na + nb - 1;
  memset(d, 0, sizeof(d[0]) * n);
  for (int i = 0; i < na; ++i)
    for (int x = a[i], j = 0; j < nb; ++j)
      d[i + j] = ((long long)x * b[j] + d[i + j]) % mod;
  for (int t, i = n - 1; i >= N; --i)
    if (t = d[i]) {
      for (int j = 0; j < N; ++j)
        d[i - j - 1] = ((long long)t * P[j] + d[i - j - 1]) % mod;
    }
  c.resize(n = min(n, N));
  for (int i = 0; i < n; ++i) c[i] = d[i];
  return;
}
int F(int n) {
  x = vector<int>{0, 1};
  y = vector<int>{1};
  while (n) {
    if (n & 1) mul(x, y, y);
    mul(x, x, x);
    n >>= 1;
  }
  int z = 0;
  for (int i = 0; i < y.size(); ++i) z = ((long long)y[i] * f[i] + z) % mod;
  return (z + mod) % mod;
}
}  // namespace BM
char s[maxn];
int n, dp[maxk][maxn][maxn], f[maxk], N;
void upd(int &x, const int &y) {
  x += y;
  if (x >= mod) x -= mod;
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  dp[0][0][n + 1] = 1;
  for (int i = 0; i < (K >> 1); ++i)
    for (int l = 0; l <= n; ++l)
      for (int t, r = 1; r <= n + 1; ++r)
        if (t = dp[i][l][r]) {
          if (l == n) {
            if (r == 1)
              upd(dp[i + 1][l][r], 26 * t % mod);
            else
              upd(dp[i + 1][l][r], 25 * t % mod), upd(dp[i + 1][l][r - 1], t);
            continue;
          }
          if (r == 1) {
            upd(dp[i + 1][l][r], 25 * t % mod), upd(dp[i + 1][l + 1][r], t);
            continue;
          }
          if (s[l + 1] == s[r - 1]) {
            upd(dp[i + 1][l + 1][r - 1], t);
            upd(dp[i + 1][l][r], 25 * t % mod);
            continue;
          }
          upd(dp[i + 1][l + 1][r], t);
          upd(dp[i + 1][l][r - 1], t);
          upd(dp[i + 1][l][r], 24 * t % mod);
        }
  for (int len = n; len <= K; ++len) {
    int i = len >> 1;
    if (~len & 1) {
      for (int l = 0; l <= n; ++l)
        for (int r = 1; r <= l + 1; ++r) upd(f[len - n], dp[i][l][r]);
    } else {
      for (int l = 0; l <= n; ++l)
        for (int r = 1; r <= l + 1; ++r)
          upd(f[len - n], 26 * dp[i][l][r] % mod);
      for (int l = 0; l < n; ++l) upd(f[len - n], dp[i][l][l + 2]);
    }
  }
  scanf("%d", &N);
  if (N + n <= K) {
    printf("%d\n", f[N]);
    return 0;
  }
  BM::B(K - n + 1, f);
  printf("%d\n", BM::F(N));
  return 0;
}
