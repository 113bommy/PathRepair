#include <bits/stdc++.h>
using namespace std;
const long long mod = static_cast<long long>(1e9 + 7);
long long P, Q = 1;
int n;
long long a[15];
pair<long long, long long> f[15][1 << 14];
pair<long long, long long> g[5000000];
pair<long long, long long> p[1 << 14];
pair<long long, long long> h[1 << 14];
int count(int x) {
  if (!x) return 0;
  return (x & 1) + count(x >> 1);
}
void Init_F() {
  for (int i = 1; i <= n; ++i) {
    for (int s = 0; s < (1 << n); ++s) {
      if ((1 << (i - 1)) & s) {
        continue;
      }
      f[i][s] = make_pair(1, 1);
      for (int j = 1; j <= n; ++j) {
        if ((1 << (j - 1)) & s) {
          f[i][s].first = f[i][s].first * a[i] % mod;
          f[i][s].second = f[i][s].second * (a[i] + a[j]) % mod;
        }
      }
    }
  }
}
int GetIndexBase3(int left, int right) {
  int idx = 0;
  for (int i = n; i > 0; --i) {
    idx *= 3;
    if (left & (1 << (i - 1))) {
      idx += 1;
    } else if (right & (1 << (i - 1))) {
      idx += 2;
    }
  }
  return idx;
}
void Recursively_Init_G(int left, int right, int cur) {
  if (cur > n) {
    int idx = GetIndexBase3(left, right);
    g[idx] = make_pair(1, 1);
    for (int i = 1; i <= n; ++i) {
      if ((1 << (i - 1)) & left) {
        g[idx].first = g[idx].first * f[i][right].first % mod;
        g[idx].second = g[idx].second * f[i][right].second % mod;
      }
    }
  } else {
    Recursively_Init_G(left, right, cur + 1);
    Recursively_Init_G(left + (1 << (cur - 1)), right, cur + 1);
    Recursively_Init_G(left, right + (1 << (cur - 1)), cur + 1);
  }
}
void Init_P() {
  for (int i = 1; i < (1 << n); ++i) {
    p[i] = make_pair(1, 1);
    for (int j = 1; j < i; ++j) {
      if ((i | j) == i) {
        long long upper = p[j].first * g[GetIndexBase3(j, i - j)].first % mod;
        long long lower = p[j].second * g[GetIndexBase3(j, i - j)].second % mod;
        p[i].first =
            ((p[i].first * lower - upper * p[i].second) % mod + mod) % mod;
        p[i].second = p[i].second * lower % mod;
      }
    }
  }
}
void Solve() {
  Init_F();
  Recursively_Init_G(0, 0, 1);
  Init_P();
  for (int i = 1; i < (1 << n); ++i) {
    int j = (1 << n) - 1 - i;
    long long upper =
        count(i) * p[i].first * g[GetIndexBase3(i, j)].first % mod;
    long long lower = p[i].second * g[GetIndexBase3(i, j)].second % mod;
    P = (P * lower + Q * upper) % mod;
    Q = Q * lower % mod;
  }
}
long long Pow(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) {
      res = res * x % mod;
    }
    x = x * x % mod;
    y >>= 1;
  }
  return res;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  Solve();
  cout << P * Pow(Q, mod - 2) % mod << endl;
  return 0;
}
