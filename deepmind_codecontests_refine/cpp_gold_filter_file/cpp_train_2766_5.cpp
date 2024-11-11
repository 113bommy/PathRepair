#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const long long INF = 1e18;
long long power(long long x, long long y, long long mod) {
  long long t = 1;
  while (y > 0) {
    if (y % 2)
      y -= 1, t = t * x % mod;
    else
      y /= 2, x = x * x % mod;
  }
  return t;
}
using namespace std;
long long fpw(long long a, long long b, long long p) {
  long long r = 1;
  while (b) {
    if (b & 1) r = r * a % p;
    a = a * a % p;
    b /= 2;
  }
  return r;
}
int ext = 16;
const long long MOD = 998244353;
long long ROOT = 440564289;
vector<long long> e, er;
void FFT(vector<int> &first, long long d = 1) {
  int n = first.size();
  if (n != ((int)(e).size())) {
    e.resize(n);
    er.resize(n);
    e[0] = 1;
    e[1] = fpw(ROOT, (1 << ext) / n, MOD);
    er[0] = 1;
    er[1] = fpw(e[1], MOD - 2, MOD);
    for (int i = (2); i < (n); ++i) e[i] = e[i - 1] * e[1] % MOD;
    for (int i = (2); i < (n); ++i) er[i] = er[i - 1] * er[1] % MOD;
  }
  if (d == -1) swap(e, er);
  for (int i = (0); i < (n); ++i) {
    int j = 0;
    for (int k = 1; k < n; k <<= 1, j <<= 1)
      if (k & i) j++;
    j >>= 1;
    if (i < j) swap(first[i], first[j]);
  }
  int k = 0;
  while ((1 << k) < n) k++;
  for (int s = 1; s < n; s <<= 1) {
    --k;
    for (int i = 0; i < n; i += 2 * s)
      for (int j = (0); j < (s); ++j) {
        long long u = first[i + j], v = first[i + j + s] * e[j << k] % MOD;
        first[i + j] = u + v - (u + v >= MOD ? MOD : 0);
        first[i + j + s] = u - v + (u - v < 0 ? MOD : 0);
      }
  }
  if (d == -1) swap(e, er);
}
vector<int> convolution(vector<int> a, vector<int> b) {
  int n = 1;
  while (n < (int)max(a.size(), b.size())) n *= 2;
  n *= 2;
  n = max(n, 32768);
  a.resize(n);
  b.resize(n);
  long long c = fpw(n, MOD - 2, MOD);
  FFT(a);
  FFT(b);
  for (int i = (0); i < (n); ++i) a[i] = (long long)a[i] * b[i] % MOD * c % MOD;
  FFT(a, -1);
  return a;
}
vector<int> ak[10];
int n, k;
vector<vector<int> > calc(int n) {
  if (n < 10) {
    assert(n >= 2);
    vector<vector<int> > z;
    z.push_back(ak[n]);
    z.push_back(ak[n - 1]);
    z.push_back(ak[n - 2]);
    return z;
  }
  if (n % 2 == 1) {
    vector<vector<int> > z = calc(n - 1);
    vector<int> nw;
    nw.resize(k + 1);
    for (int j = 0; j < k + 1; ++j) {
      nw[j] = (z[0][j] + (j > 0 ? (z[0][j - 1] + z[1][j - 1]) % MOD : 0)) % MOD;
    }
    z[2] = z[1];
    z[1] = z[0];
    z[0] = nw;
    return z;
  } else {
    vector<vector<int> > z = calc(n / 2);
    vector<int> a[5];
    a[0] = convolution(z[0], z[0]), a[1] = convolution(z[1], z[1]),
    a[2] = convolution(z[2], z[2]);
    a[3] = convolution(z[0], z[1]);
    a[4] = convolution(z[1], z[2]);
    for (int i = 0; i < k + 1; ++i) {
      z[0][i] = (a[0][i] + (i > 0 ? a[1][i - 1] : 0)) % MOD;
      z[1][i] = (a[3][i] + (i > 0 ? a[4][i - 1] : 0)) % MOD;
      z[2][i] = (a[1][i] + (i > 0 ? a[2][i - 1] : 0)) % MOD;
    }
    return z;
  }
}
int main() {
  ROOT = 1;
  while (1) {
    if (power(ROOT, 1 << ext, MOD) == 1 &&
        power(ROOT, 1 << (ext - 1), MOD) != 1)
      break;
    ROOT++;
  }
  scanf("%d%d", &n, &k);
  ak[0].resize(k + 1);
  ak[0][0] = 1;
  for (int i = 1; i < 10; ++i) {
    ak[i].resize(k + 1);
    for (int j = 0; j < k + 1; ++j) {
      ak[i][j] = (ak[i - 1][j] + ((j > 0 ? ak[i - 1][j - 1] : 0) +
                                  ((i > 1 && j > 0) ? ak[i - 2][j - 1] : 0)) %
                                     MOD) %
                 MOD;
    }
  }
  vector<int> ans;
  if (n < 10) {
    ans = ak[n];
  } else {
    ans = calc(n)[0];
  }
  for (int i = 1; i < k + 1; ++i) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
