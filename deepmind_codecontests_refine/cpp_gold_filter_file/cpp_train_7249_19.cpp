#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e17;
const int N = 30;
int x, k, n, q, mx;
int cnt[N * 50];
long long c[30];
vector<int> ve;
map<int, int> mp;
struct Stone {
  int p, w;
  friend bool operator<(Stone a, Stone b) { return a.p < b.p; }
} t[N];
struct Matrix {
  long long f[72][72];
  friend Matrix operator*(const Matrix &a, const Matrix &b) {
    Matrix c;
    memset(c.f, 0x3f, sizeof(c.f));
    for (int i = 0; i < mx; ++i)
      for (int j = 0; j < mx; ++j)
        if (a.f[j][i] < inf)
          for (int k = 0; k < mx; ++k)
            c.f[j][k] = min(c.f[j][k], a.f[j][i] + b.f[i][k]);
    return c;
  }
  friend Matrix operator^(const Matrix &a, const Matrix &b) {
    Matrix c;
    for (int i = 0; i < mx; ++i) {
      c.f[0][i] = inf;
      for (int j = 0; j < mx; ++j)
        c.f[0][i] = min(c.f[0][i], a.f[0][j] + b.f[j][i]);
    }
    return c;
  }
} a, b[30];
int main() {
  cin >> x >> k >> n >> q;
  const int lim = (1 << k) - 1;
  for (int i = 1; i <= k; ++i) cin >> c[i];
  for (int i = 1; i <= q; ++i) cin >> t[i].p >> t[i].w;
  for (int i = 1; i <= lim; ++i) cnt[i] = cnt[i ^ (i & -i)] + 1;
  for (int i = 1; i <= lim; ++i)
    if (cnt[i] == x) ve.push_back(i);
  mx = ve.size();
  sort(t + 1, t + q + 1);
  for (int i = 0; i < mx; ++i) mp[ve[i]] = i;
  memset(b[0].f, 0x3f, sizeof(b[0].f));
  memset(a.f, 0x3f, sizeof(a.f));
  a.f[0][0] = 0;
  for (int i = 0; i < mx; ++i) {
    if (ve[i] & 1) {
      for (int j = 1; j <= k; ++j)
        if (!(ve[i] >> j & 1))
          b[0].f[i][mp[(ve[i] >> 1) | (1 << j - 1)]] = c[j];
    } else
      b[0].f[i][mp[ve[i] >> 1]] = 0;
  }
  for (int i = 1; i <= 28; ++i) b[i] = b[i - 1] * b[i - 1];
  int las = 1;
  long long sum = 0;
  for (int i = 1; i <= q; ++i) {
    if (t[i].p >= n - x + 1) {
      sum += t[i].w;
      continue;
    }
    int p = t[i].p - las;
    long long mi = 1e18;
    for (int j = 0; j <= 28; ++j)
      if (p >> j & 1) a = a ^ b[j];
    for (int j = 0; j < mx; ++j)
      if (ve[j] & 1) a.f[0][j] += t[i].w;
    las = t[i].p;
    for (int j = 0; j < mx; ++j) mi = min(mi, a.f[0][j]);
  }
  int p = n - x + 1 - las;
  for (int i = 0; i <= 28; ++i)
    if (p >> i & 1) a = a ^ b[i];
  printf("%lld\n", a.f[0][0] + sum);
  return 0;
}
