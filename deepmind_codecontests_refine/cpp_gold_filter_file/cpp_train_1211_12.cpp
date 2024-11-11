#include <bits/stdc++.h>
using namespace std;
const int md = 1000000007, MX = 105;
int n, G[MX][MX];
struct poly {
  int a[MX];
  poly() { memset(a, 0, sizeof(a)); }
  inline int &operator[](const int x) { return a[x]; }
  inline int deg() {
    for (int i = n; i; i--)
      if (a[i - 1]) return i;
    return 0;
  }
  inline void mod() {
    for (int i = 0; i < n; i++) a[i] = (md + a[i]) % md;
  }
  inline int operator()(const int x) {
    return (a[0] + (long long)a[1] * x) % md;
  }
} I, X, O;
inline poly operator+(const poly &l, const poly &r) {
  poly res;
  for (int i = 0; i < n; i++) res.a[i] = (l.a[i] + r.a[i]) % md;
  return res;
}
inline poly operator-(const poly &l, const poly &r) {
  poly res;
  for (int i = 0; i < n; i++) res.a[i] = (md + l.a[i] - r.a[i]) % md;
  return res;
}
inline poly operator*(const int x, const poly &r) {
  poly res;
  for (int i = 0; i < n; i++) res.a[i] = (long long)r.a[i] * x % md;
  return res;
}
inline poly mul(const poly &l, const poly &r) {
  poly res;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (i + j < n)
        res.a[i + j] = (res.a[i + j] + (long long)l.a[i] * r.a[j]) % md;
  return res;
}
inline poly tx(const poly &p, int x) {
  poly res;
  for (int i = 0; i + x < n; i++) res.a[i + x] = p.a[i];
  return res;
}
poly A[MX][MX];
int ans[MX], y[MX];
inline int pw(int x, int y) {
  int a = 1;
  while (y) {
    if (y & 1) a = (long long)a * x % md;
    x = (long long)x * x % md;
    y >>= 1;
  }
  return a;
}
pair<int, int> fp(int i) {
  int a[2], c = 0;
  for (int j = i; j < n; j++)
    if (A[j][i].deg()) {
      a[c++] = j;
      if (c == 2) break;
    }
  if (c < 2) return make_pair(0, 0);
  return make_pair(a[0], a[1]);
}
void det_gauss() {
  int v, i, j, k, N = n - 1, K;
  pair<int, int> pt;
  for (v = 0; v < n; v++) {
    K = 1;
    for (i = 1; i <= N; i++)
      for (j = 1; j <= N; j++) G[i][j] = A[i][j](v);
    for (i = 1; i <= N; i++) {
      for (j = i; j <= N; j++)
        if (G[j][i]) break;
      if (j == N + 1) {
        y[v] = 0;
        break;
      }
      if (j != i) {
        K = md - K;
        for (k = i; k <= N; k++) swap(G[i][k], G[j][k]);
      }
      for (j = i + 1; j <= N; j++)
        if (G[j][i]) {
          int tk = (long long)pw(G[i][i], md - 2) * (md - G[j][i]) % md;
          for (k = i; k <= N; k++)
            G[j][k] = (G[j][k] + (long long)G[i][k] * tk) % md;
        }
    }
    y[v] = K;
    for (i = 1; i <= N; i++) y[v] = (long long)y[v] * G[i][i] % md;
  }
  poly res;
  for (v = 0; v < n; v++) {
    K = 1;
    for (i = 0; i < n; i++)
      if (i != v) K = (long long)K * pw((v - i + md) % md, md - 2) % md;
    poly tmp = I;
    for (i = 0; i < n; i++)
      if (i != v) {
        poly t2 = O;
        for (j = 0; j + 1 < n; j++) t2[j + 1] = (t2[j + 1] + tmp[j]) % md;
        for (j = 0; j < n; j++)
          t2[j] = (t2[j] + (long long)tmp[j] * (md - i)) % md;
        tmp = t2;
      }
    for (i = 0; i < n; i++) tmp[i] = (long long)tmp[i] * K % md * y[v] % md;
    res = res + tmp;
  }
  memcpy(ans, res.a, sizeof(int) * n);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  I.a[0] = X.a[1] = 1;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    G[u][v] = G[v][u] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      ++A[i][i][G[i][j]], ++A[j][j][G[i][j]];
      --A[i][j][G[i][j]], --A[j][i][G[i][j]];
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) A[i][j].mod();
  det_gauss();
  for (int i = 0; i < n; i++) cout << ans[i] << ' ';
  return 0;
}
