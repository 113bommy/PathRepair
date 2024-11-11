#include <bits/stdc++.h>
using namespace std;
const int Q = 1e8;
struct llong {
  vector<long long> v;
  llong() {}
  llong(int c) { v.push_back(c); }
  friend llong operator*(llong a, int b) {
    int t = 0;
    for (int i = 0; i < a.v.size(); ++i) {
      a.v[i] = a.v[i] * 10 + t;
      t = a.v[i] / Q;
      a.v[i] %= Q;
    }
    if (t) a.v.push_back(t);
    return a;
  }
  friend llong operator+(llong a, int b) {
    int t = b;
    for (int i = 0; i < a.v.size() && t; ++i) {
      a.v[i] += t;
      t = a.v[i] >= Q;
      a.v[i] %= Q;
    }
    if (t) a.v.push_back(t);
    return a;
  }
  friend llong operator-(llong a, llong b) {
    int t = 0;
    for (int i = 0; i < a.v.size(); ++i) {
      a.v[i] -= (i < b.v.size() ? b.v[i] : 0) + t;
      if (a.v[i] < 0) {
        a.v[i] += Q;
        t = 1;
      }
    }
    return a;
  }
  friend int operator%(llong a, int b) {
    int t = 0;
    for (int i = a.v.size() - 1; i >= 0; --i) {
      t = (t * Q + a.v[i]) % b;
    }
    return t;
  }
  friend llong operator/(llong a, int b) {
    int t = 0;
    for (int i = a.v.size() - 1; i >= 0; --i) {
      long long tt = t * Q + a.v[i];
      t = (tt) % b;
      a.v[i] = tt / b;
    }
    return a;
  }
};
const int N = 1003, K = 102;
int f[N][K], g[N][K];
bool ok(int a) {
  int pw = 10000;
  while (pw != 0) {
    if (a == 0) return false;
    if (a % 3 == 0) return true;
    a %= pw;
    pw /= 10;
  }
  return false;
}
int main() {
  int n, k, m;
  cin >> n >> k >> m;
  if (n == 1) {
    int res = 0;
    for (int i = 1; i < 10; ++i)
      if (i % k == 0) ++res;
    cout << res;
    return 0;
  }
  f[0][0] = 1;
  int ost = 1;
  for (int i = 1; i <= n - 1; ++i) {
    for (int j = 0; j < k; ++j)
      for (int l = 0; l < 10; ++l) {
        f[i][(j + ost * l) % k] += f[i - 1][j];
        f[i][(j + ost * l) % k] %= m;
      }
    for (int j = 0; j < k; ++j)
      for (int l = 0; l < 10; ++l) {
        g[i][(j + ost * l) % k] += g[i - 1][j];
        g[i][(j + ost * l) % k] %= m;
      }
    g[i][0] = f[i][0] - 1;
    ost = ost * 10 % k;
  }
  int res = 0;
  for (int j = 0; j < k; ++j)
    for (int l = 1; l < 10; ++l) {
      f[n][(j + ost * l) % k] += f[n - 1][j];
      f[n][(j + ost * l) % k] %= m;
    }
  for (int i = 0; i < k; ++i) {
    for (int j = 1; j < 10; ++j) {
      g[n][(i + j * ost) % k] += g[n - 1][i];
      g[n][(i + j * ost) % k] %= m;
    }
  }
  g[n][0] = f[n][0];
  for (int i = 0; i < k; ++i) res = (res + g[n][i]) % m;
  cout << res;
  return 0;
}
