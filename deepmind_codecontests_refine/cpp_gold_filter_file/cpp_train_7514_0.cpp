#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <typename T, typename U>
inline ostream &operator<<(ostream &_out, const pair<T, U> &_p) {
  _out << _p.first << ' ' << _p.second;
  return _out;
}
template <typename T, typename U>
inline istream &operator>>(istream &_in, pair<T, U> &_p) {
  _in >> _p.first >> _p.second;
  return _in;
}
template <typename T>
inline ostream &operator<<(ostream &_out, const vector<T> &_v) {
  if (_v.empty()) {
    return _out;
  }
  _out << _v.front();
  for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) {
    _out << ' ' << *_it;
  }
  return _out;
}
template <typename T>
inline istream &operator>>(istream &_in, vector<T> &_v) {
  for (auto &_i : _v) {
    _in >> _i;
  }
  return _in;
}
const long long MAXN = 3604;
const long long MAXM = MAXN / 2;
const long long INF = 1e9;
const long long MOD = 998244353;
long long sum(long long a, long long b) {
  if (a + b >= MOD) {
    return a + b - MOD;
  }
  return a + b;
}
long long mul(long long a, long long b) {
  if (a * b >= MOD) {
    return (a * b) % MOD;
  }
  return a * b;
}
long long sqr(long long a) { return (a * a) % MOD; }
long long bin_pow(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  if (b % 2) {
    return mul(a, bin_pow(a, b - 1));
  }
  return sqr(bin_pow(a, b / 2));
}
long long fact[MAXN];
long long rfact[MAXN];
long long dp[2][MAXM][MAXN];
bool connected[MAXN];
long long dp1[MAXM];
long long dp2[MAXN][MAXM];
inline long long c(long long n, long long k) {
  return mul(fact[n], mul(rfact[k], rfact[n - k]));
}
class FSbalansirovannieRaspolozheniyaDomino {
 public:
  void solve(std::istream &in, std::ostream &out) {
    fact[0] = 1;
    for (long long i = 1; i < MAXN; i++) {
      fact[i] = mul(i, fact[i - 1]);
    }
    rfact[MAXN - 1] = bin_pow(fact[MAXN - 1], MOD - 2);
    for (long long j = MAXN - 1; j >= 1; j--) {
      rfact[j - 1] = mul(rfact[j], j);
    }
    long long h, w;
    in >> h >> w;
    long long n;
    in >> n;
    vector<pair<pair<long long, long long>, pair<long long, long long>>> a(n);
    in >> a;
    {
      for (long long i = 0; i <= h; i++) {
        for (long long j = 0; j < MAXM; j++) {
          dp2[i][j] = 0;
          dp[0][j][i] = 0;
        }
        connected[i] = 0;
      }
      for (long long j = 0; j < MAXM; j++) {
        dp1[j] = 0;
      }
      for (auto v : a) {
        connected[v.first.first - 1] = 1;
        connected[v.second.first - 1] = 1;
      }
      long long counts = 0;
      for (long long j = 0; j < h; j++) {
        counts += !connected[j];
      }
      dp1[0] = 1;
      for (long long i = 0; i <= h; i++) {
        for (long long j = 0; j < MAXM; j++) {
          dp1[j] = sum(dp1[j], dp2[i][j]);
        }
        if (i + 1 < h && connected[i] == 0 && connected[i + 1] == 0) {
          for (long long j = 0; j + 1 < MAXM; j++) {
            dp2[i + 2][j + 1] = dp1[j];
          }
        }
      }
      for (long long i = 0; i < MAXM; i++) {
        for (long long j = 0; j <= counts - 2 * i; j++) {
          dp[0][i][j] =
              mul(dp1[i], mul(fact[counts - 2 * i],
                              mul(fact[i], rfact[counts - 2 * i - j])));
        }
      }
    }
    {
      for (long long i = 0; i <= w; i++) {
        for (long long j = 0; j < MAXM; j++) {
          dp2[i][j] = 0;
          dp[1][j][i] = 0;
        }
        connected[i] = 0;
      }
      for (long long j = 0; j < MAXM; j++) {
        dp1[j] = 0;
      }
      for (auto v : a) {
        connected[v.first.second - 1] = 1;
        connected[v.second.second - 1] = 1;
      }
      long long counts = 0;
      for (long long j = 0; j < w; j++) {
        counts += !connected[j];
      }
      dp1[0] = 1;
      for (long long i = 0; i <= w; i++) {
        for (long long j = 0; j < MAXM; j++) {
          dp1[j] = sum(dp1[j], dp2[i][j]);
        }
        if (i + 1 < w && connected[i] == 0 && connected[i + 1] == 0) {
          for (long long j = 0; j + 1 < MAXM; j++) {
            dp2[i + 2][j + 1] = dp1[j];
          }
        }
      }
      for (long long i = 0; i < MAXM; i++) {
        for (long long j = 0; j <= counts - 2 * i; j++) {
          dp[1][i][j] = mul(dp1[i], c(counts - 2 * i, j));
        }
      }
    }
    long long ans = 0;
    for (long long i = 0; 2 * i <= h; i++) {
      for (long long j = 0; 2 * j <= w; j++) {
        ans += dp[0][i][j] * dp[1][j][i];
        if (ans >= MOD * MOD) {
          ans -= MOD * MOD;
        }
      }
    }
    ans %= MOD;
    out << ans;
  }
};
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  FSbalansirovannieRaspolozheniyaDomino solver;
  std::istream &in(std::cin);
  std::ostream &out(std::cout);
  solver.solve(in, out);
  return 0;
}
