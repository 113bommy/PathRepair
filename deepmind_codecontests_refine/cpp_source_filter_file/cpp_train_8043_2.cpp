#include <bits/stdc++.h>
using namespace std;
const int N = 65537;
const int mod = 998244353;
int n, k, c, sum;
int y[N], s[17], fac[17], finv[17], num[N], Ans[N];
map<vector<int>, int> mp;
vector<int> h[N], Ln[N], g[N];
inline int qpow(int x, int k, int r = 1) {
  for (; k; k >>= 1, x = 1ll * x * x % mod)
    if (k & 1) r = 1ll * r * x % mod;
  return r;
}
inline vector<int> operator*(vector<int> a, vector<int> b) {
  vector<int> c(a.size());
  for (int i = 0; i < c.size(); ++i)
    for (int j = 0; i + j < c.size(); ++j)
      (c[i + j] += 1ll * a[i] * b[j] % mod) %= mod;
  return c;
}
inline vector<int> getinv(vector<int> a, int n) {
  vector<int> b(n);
  const int inv = qpow(a[0], mod - 2);
  b[0] = inv;
  for (int i = 1; i < n; ++i) {
    int v = 0;
    for (int j = 0; j < i; ++j) (v += mod - 1ll * b[j] * a[i - j] % mod) %= mod;
    b[i] = 1ll * v * inv % mod;
  }
  return b;
}
inline vector<int> getdao(vector<int> a, int n) {
  vector<int> b(n);
  for (int i = 0; i < n - 1; ++i) b[i] = a[i + 1] * (i + 1ll) % mod;
  return b;
}
inline vector<int> getji(vector<int> a, int n) {
  vector<int> b(n);
  for (int i = 1; i < n; ++i) b[i] = 1ll * a[i - 1] * qpow(i, mod - 2) % mod;
  return b;
}
inline vector<int> getln(vector<int> a, int n) {
  return getji(getdao(a, n) * getinv(a, n), n);
}
inline vector<int> getexp(vector<int> a, int n) {
  a = getdao(a, n);
  vector<int> b(n);
  b[0] = 1;
  for (int i = 0; i < n - 1; ++i) {
    int v = 0;
    for (int j = 0; j <= i; ++j) (v += 1ll * b[j] * a[i - j] % mod) %= mod;
    b[i + 1] = 1ll * v * qpow(i + 1, mod - 2) % mod;
  }
  return b;
}
int main() {
  scanf("%d%d%d", &n, &k, &c);
  for (int i = fac[0] = 1; i <= k; ++i) fac[i] = 1ll * fac[i - 1] * i % mod;
  finv[k] = qpow(fac[k], mod - 2);
  for (int i = k; i; --i) finv[i - 1] = 1ll * finv[i] * i % mod;
  for (int i = 0; i <= k; ++i)
    s[i] = 1ll * qpow(qpow(n, i), mod - 2) * finv[i] % mod;
  for (int i = 1; i <= n; ++i) scanf("%d", &y[i]), sum ^= y[i];
  for (int i = 1; i <= n; ++i) {
    vector<int> ve;
    for (int j = 0; j <= k; ++j) ve.push_back(y[i] ^ y[i] - j);
    ++mp[ve];
  }
  for (int i = 0; i < 1 << c; ++i) h[i].resize(k + 1);
  for (int i = 1; i < 1 << c; ++i) num[i] = num[i >> 1] + (i & 1);
  for (int i = 0; i < 1 << k; ++i) {
    vector<int> f(k + 1);
    f[0] = 1;
    for (int j = 1; j <= k; ++j) f[j] = i >> j - 1 & 1 ? mod - s[j] : s[j];
    Ln[i] = getln(f, k + 1);
  }
  for (auto p : mp) {
    vector<int> f = p.first;
    for (int i = 0; i < 1 << c; ++i) {
      int s = 0;
      for (int j = 1; j <= k; ++j) s |= num[i & f[j]] & 1 << j - 1;
      for (int j = 0; j <= k; ++j)
        (h[i][j] += 1ll * Ln[s][j] * p.second % mod) %= mod;
    }
  }
  for (int i = 0; i < 1 << c; ++i) {
    h[i] = getexp(h[i], k + 1);
    Ans[i] = 1ll * h[i][k] * fac[k] % mod;
  }
  for (int i = 1; i < 1 << c; i <<= 1)
    for (int j = 0; j < 1 << c; j += i << 1)
      for (int k = 0; k < i; ++k) {
        int x = Ans[j + k], y = Ans[j + k + i];
        Ans[j + k] = (x + y) % mod;
        Ans[j + k + i] = (x - y + mod) % mod;
      }
  const int inv = qpow(1 << c, mod - 2);
  for (int i = 0; i < 1 << c; ++i) Ans[i] = 1ll * Ans[i] * inv % mod;
  for (int i = 0; i < 1 << c; ++i) printf("%d ", Ans[i ^ sum]);
  return puts(""), 0;
}
