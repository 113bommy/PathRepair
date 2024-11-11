#include <bits/stdc++.h>
using namespace std;
template <class T>
bool uin(T &a, T b) {
  return (a > b ? a = b, true : false);
}
template <class T>
bool uax(T &a, T b) {
  return (a < b ? a = b, true : false);
}
int const X = 8;
int const L = 17;
int const N = 41;
long long const INF = 3e18 + 41;
int x, k, n, q;
int c[N];
int p[N], w[N];
long long d[(1 << X)][(1 << X)][L];
long long ans;
bool bit(int m, int i) { return (m & (1 << i)); }
int xorbit(int m, int i) { return (m ^ (1 << i)); }
int dx[(1 << X)][(1 << X)];
unordered_map<int, int> a;
void build() {
  for (int i = 0; i < (1 << X); ++i)
    for (int j = 0; j < (1 << X); ++j)
      for (int o = 0; o < L; ++o) d[i][j][o] = INF;
  memset(dx, 255, sizeof(dx));
  for (int i = 0; i < (1 << k); ++i) {
    if (!bit(i, 0)) {
      int m0 = i;
      int m1 = (m0 >> 1);
      uin(d[m0][m1][0], 0ll);
    } else {
      int m0 = i;
      for (int j = 1; j < k + 1; ++j) {
        if (bit(m0, j)) continue;
        int m1 = xorbit(m0, j);
        m1 = xorbit(m1, 0);
        m1 >>= 1;
        if (uin(d[m0][m1][0], (long long)c[j - 1])) dx[m0][m1] = j;
      }
    }
  }
  for (int o = 1; o < L; ++o) {
    for (int t = 0; t < (1 << k); ++t) {
      for (int i = 0; i < (1 << k); ++i) {
        for (int j = 0; j < (1 << k); ++j) {
          uin(d[i][j][o], d[i][t][o - 1] + d[t][j][o - 1]);
        }
      }
    }
  }
}
long long f[(1 << X)], nf[(1 << X)];
void solve() {
  int p1 = 0;
  int x0 = 0;
  for (int i = 0; i < (1 << X); ++i) f[i] = INF;
  f[(1 << x) - 1] = 0;
  while (x0 < n - x) {
    while (p1 < q && x0 > p[p1]) ++p1;
    int s;
    for (int i = L - 1; i >= 0; --i) {
      s = i;
      if (x0 + (1 << i) + k - 1 > n - 1) continue;
      if (p1 != q && x0 + (1 << i) + k - 1 >= p[p1]) continue;
      break;
    }
    if ((p1 < q && p[p1] - x0 < 20) || (n - x0 < 20)) {
      s = 0;
    }
    for (int i = 0; i < (1 << k); ++i) nf[i] = INF;
    for (int i = 0; i < (1 << k); ++i)
      for (int j = 0; j < (1 << k); ++j) {
        long long v = f[i] + d[i][j][s];
        if (s == 0 && dx[i][j] != -1 && a.find(x0 + dx[i][j]) != a.end()) {
          v += a[x0 + dx[i][j]];
        }
        uin(nf[j], v);
      }
    memcpy(f, nf, sizeof(f));
    x0 += (1 << s);
  }
  ans = f[(1 << x) - 1];
}
int main() {
  scanf("%d %d %d %d", &x, &k, &n, &q);
  for (int i = 0; i < k; ++i) scanf("%d", &c[i]);
  for (int i = 0; i < q; ++i) {
    scanf("%d %d", &p[i], &w[i]);
    --p[i];
    a[p[i]] = w[i];
  }
  for (int i = 0; i < q; ++i)
    for (int j = i + 1; j < q; ++j)
      if (p[j] < p[i]) {
        swap(p[j], p[i]);
        swap(w[j], w[i]);
      }
  build();
  solve();
  printf("%I64d\n", ans);
  return 0;
}
