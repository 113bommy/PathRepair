#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wunused-variable"
using namespace std;
const long long maxn = 1e6 + 50;
const long long mod = 1e9 + 7;
const long long phi = mod - 2;
inline long long fpow(long long a, long long p) {
  long long res = 1;
  for (; p; p >>= 1, a *= a, a %= mod) {
    if (p & 1) res *= a, res %= mod;
  }
  return res;
}
vector<vector<long long>> operator*(const vector<vector<long long>> &a,
                                    const vector<vector<long long>> &b) {
  vector<vector<long long>> c(a.size(), vector<long long>(b[0].size()));
  for (long long i = 0; i < a.size(); ++i) {
    for (long long j = 0; j < b[0].size(); ++j) {
      for (long long k = 0; k < b.size(); ++k) {
        c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % phi;
      }
    }
  }
  return c;
}
vector<vector<long long>> operator^(vector<vector<long long>> a, long long p) {
  vector<vector<long long>> c = a;
  for (long long i = 0; i < a.size(); ++i)
    for (long long j = 0; j < a.size(); ++j) c[i][j] = i == j;
  for (; p; p >>= 1, a = a * a) {
    if (p & 1) c = c * a;
  }
  return c;
}
signed main() {
  long long n, f1, f2, f3, c;
  cin >> n >> f1 >> f2 >> f3 >> c;
  vector<vector<long long>> first = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}};
  vector<vector<long long>> rF1{{1}, {0}, {0}};
  vector<vector<long long>> rF2{{0}, {1}, {0}};
  vector<vector<long long>> rF3{{0}, {0}, {1}};
  vector<vector<long long>> C = {{0, 1, 0, 0, 0},
                                 {0, 0, 1, 0, 0},
                                 {1, 1, 1, 1, 1},
                                 {0, 0, 0, 1, 1},
                                 {0, 0, 0, 0, 1}};
  vector<vector<long long>> rC = {{0}, {0}, {2}, {2}, {2}};
  C = (C ^ (n - 4));
  C = C * rC;
  first = first ^ (n - 3), rF3 = first * rF3, rF2 = first * rF2,
  rF1 = first * rF1;
  long long ans = fpow(c, C[2][0]) * fpow(f1, rF1[2][0]) % mod *
                  fpow(f2, rF2[2][0]) % mod * fpow(f3, rF3[2][0]) % mod;
  cout << ans << '\n';
}
