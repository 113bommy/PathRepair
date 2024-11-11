#include <bits/stdc++.h>
using namespace std;
const long long N = 55;
long long mod = 1e9 + 7;
long long n, T, ans = 0;
long long duration[4], sz[4];
long long fact[N];
long long cnt[N][N][N], val[N][N][N][4];
long long dp1[N][N * N], dp23[N][N][N * N];
long long add(long long a, long long b) { return (a + b) % mod; }
long long mul(long long a, long long b) { return a * b % mod; }
void init() {
  fact[0] = 1;
  for (long long i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i % mod;
  val[1][0][0][1] = val[0][1][0][2] = val[0][0][1][3] = 1;
  for (long long i = 0; i <= n; ++i) {
    for (long long j = 0; j <= n; ++j) {
      for (long long k = 0; k <= n; ++k) {
        for (long long l = 1; l <= 3; ++l) {
          if (l != 1)
            val[i + 1][j][k][1] = add(val[i][j][k][l], val[i + 1][j][k][1]);
          if (l != 2)
            val[i][j + 1][k][2] = add(val[i][j][k][l], val[i][j + 1][k][2]);
          if (l != 3)
            val[i][j][k + 1][3] = add(val[i][j][k][l], val[i][j][k + 1][3]);
        }
        cnt[i][j][k] =
            mul(mul(fact[i], mul(fact[j], fact[k])),
                add(val[i][j][k][1], add(val[i][j][k][2], val[i][j][k][3])));
      }
    }
  }
}
void solve() {
  for (long long i = 0; i <= sz[1]; ++i) {
    for (long long j = 0; j <= sz[2]; ++j) {
      for (long long k = 0; k <= sz[3]; ++k) {
        for (long long dur = 0; dur <= T; ++dur) {
          ans = add(ans,
                    mul(cnt[i][j][k], mul(dp1[i][dur], dp23[j][k][T - dur])));
        }
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> T;
  init();
  dp1[0][0] = dp23[0][0][0] = 1;
  for (long long i = 1; i <= n; ++i) {
    long long dur, type;
    cin >> dur >> type;
    if (type == 1) {
      for (long long i = sz[1]; i >= 0; --i) {
        for (long long j = 0; j <= duration[1]; ++j) {
          dp1[i + 1][j + dur] = add(dp1[i + 1][j + dur], dp1[i][j]);
        }
      }
    } else {
      for (long long i = sz[2]; i >= 0; --i) {
        for (long long j = sz[3]; j >= 0; --j) {
          for (long long k = 0; k <= duration[2] + duration[3]; ++k) {
            dp23[i + (type == 2)][j + (type == 3)][k + dur] = add(
                dp23[i + (type == 2)][j + (type == 3)][k + dur], dp23[i][j][k]);
          }
        }
      }
    }
    sz[type] += 1;
    duration[type] += dur;
  }
  solve();
  cout << ans;
}
