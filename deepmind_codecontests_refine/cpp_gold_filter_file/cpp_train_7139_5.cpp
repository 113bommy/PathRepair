#include <bits/stdc++.h>
using namespace std;
struct CP {
  long double x, y;
  CP(long double xx = 0, long double yy = 0) {
    x = xx;
    y = yy;
  }
  CP operator+(CP const &A) const { return CP(x + A.x, y + A.y); }
  CP operator-(CP const &A) const { return CP(x - A.x, y - A.y); }
  CP operator*(CP const &A) const {
    return CP(x * A.x - y * A.y, x * A.y + y * A.x);
  }
};
const long double Pi = acos(-1);
void dft(vector<CP> &f, int n, bool flag) {
  vector<int> idx(n);
  for (int i = 0; i < n; i++)
    idx[i] = (idx[i >> 1] >> 1) + ((i & 1) * (n >> 1));
  for (int i = 0; i < n; i++)
    if (i < idx[i]) swap(f[i], f[idx[i]]);
  for (int p = 2; p <= n; p *= 2) {
    int m = p >> 1;
    vector<CP> w(m);
    for (int i = 0; i < m; i++) {
      w[i].x = cos(2 * Pi / p * i);
      w[i].y = sin(2 * Pi / p * i);
      if (flag) w[i].y *= -1;
    }
    for (int i = 0; i < n; i += p) {
      for (int j = 0; j < m; j++) {
        CP tmp = f[i + m + j] * w[j];
        f[i + j + m] = f[i + j] - tmp;
        f[i + j] = f[i + j] + tmp;
      }
    }
  }
  if (flag)
    for (int i = 0; i < n; i++) {
      f[i].x /= n;
      f[i].y /= n;
    }
}
void mtt(vector<int> &A, vector<int> &B, vector<int> &C, int n, int P) {
  int u = 0, v = 0;
  for (int i = 0; i < n; i++)
    if (A[i]) u = i;
  for (int i = 0; i < n; i++)
    if (B[i]) v = i;
  if (u + v >= n) {
    printf("WRN: the degree of poly A*B is greater than n!\n");
  }
  const long long k = 32768;
  vector<CP> f(n), g(n), h(n), t0(n), t1(n);
  for (int i = 0; i < n; i++) {
    f[i].x = A[i] >> 15;
    f[i].y = A[i] & (k - 1);
    g[i].x = A[i] >> 15;
    g[i].y = -(A[i] & (k - 1));
    h[i].x = B[i] >> 15;
    h[i].y = B[i] & (k - 1);
  }
  dft(f, n, 0);
  dft(g, n, 0);
  dft(h, n, 0);
  for (int i = 0; i < n; i++) {
    CP fh = f[i] * h[i], gh = g[i] * h[i];
    t0[i] = fh + gh;
    t1[i] = gh - fh;
  }
  dft(t0, n, 1);
  dft(t1, n, 1);
  for (int i = 0; i < n; i++) {
    long long a0b0 = (long long)(t0[i].x / 2.0 + 0.49) % P;
    long long a0b1 = (long long)(t0[i].y / 2.0 + 0.49) % P;
    long long a1b1 = (long long)(t1[i].x / 2.0 + 0.49) % P;
    long long a1b0 = (long long)(-t1[i].y / 2.0 + 0.49) % P;
    C[i] = (a0b0 * k % P * k + (a0b1 + a1b0) * k % P + a1b1) % P;
    if (C[i] < 0) C[i] += P;
  }
}
int extend_len(int n) {
  int m = 1;
  while (m < n) m *= 2;
  return m;
}
const int maxn = 65536;
vector<int> f(maxn), g(maxn), rf(maxn), rg(maxn), tf(maxn), tg(maxn), rh(maxn);
int max_a, max_n, mod;
vector<vector<int> > ff, gg;
int dp(int n, int a, int mod) {
  if (a == 1) {
    return 0;
  }
  f[0] = f[1] = g[0] = g[1] = 1;
  ff.push_back(f);
  gg.push_back(g);
  f[0] = f[1] = 1;
  g[0] = g[2] = 1;
  g[1] = 2;
  ff.push_back(f);
  gg.push_back(g);
  int m = extend_len((n + 1) * 2);
  vector<int> bits;
  bits.clear();
  for (; a; a /= 2) bits.push_back(a & 1);
  int now = 0;
  int res = 0;
  for (int j = bits.size() - 1, k = 0; j; j--, k++) {
    if (k == 0) {
      rf = ff[0];
      rg = gg[0];
      now = 1;
    } else {
      if (now & 1) {
        for (int i = 0; i < m; i++) rh[i] = (rg[i] - rf[i] + mod) % mod;
        rh[0] = 1;
        mtt(rg, rh, tf, m, mod);
      } else
        mtt(rg, rf, tf, m, mod);
      mtt(rg, rg, tg, m, mod);
      for (int i = 0; i < m; i++)
        if (i <= n) {
          rf[i] = (tf[i] - rg[i] + rf[i] + mod) % mod;
          rg[i] = tg[i];
        } else
          rf[i] = rg[i] = 0;
      now *= 2;
      if (bits[j]) {
        tf[0] = rf[0];
        tg[0] = rg[0];
        for (int i = 1; i < m; i++) {
          tf[i] = rf[i] + rg[i - 1];
          tg[i] = rg[i] + rg[i - 1];
        }
        for (int i = 0; i < m; i++) {
          if (i <= n) {
            rf[i] = tf[i] % mod;
            rg[i] = tg[i] % mod;
          } else
            rf[i] = rg[i] = 0;
        }
        now++;
      }
    }
    for (int i = 1; i <= n; i += 2) res = (res + rf[i]) % mod;
  }
  return res;
}
int main() {
  scanf("%d%d%d", &max_n, &max_a, &mod);
  int res = 0;
  printf("%d\n", dp(max_n, max_a, mod));
  return 0;
}
