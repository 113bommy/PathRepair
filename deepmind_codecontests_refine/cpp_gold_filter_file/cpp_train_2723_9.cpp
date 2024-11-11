#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353, N = 56, M = 2 * N, C = 5005;
int a[N], b[N], memo[C][C];
int dp[2][M][M][M][2];
void add(int& a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
ll binPow(ll x, ll y) {
  ll ans = 1;
  while (y) {
    if (y & 1) ans = ans * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return ans;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i];
  int sumA = 0, sumB = 0;
  for (int i = 1; i <= n; ++i) {
    sumA += a[i] * b[i];
    sumB += (!a[i]) * b[i];
  }
  for (int x = 0; x < M; ++x) {
    for (int y = 0; y < M; ++y) {
      for (int me = 0; me < M; ++me) {
        for (int p = 0; p < 2; ++p) {
          dp[0][x][y][me][p] = me;
        }
      }
    }
  }
  for (int i = 0; i < C; ++i) {
    ll save = binPow(i, MOD - 2);
    for (int j = 0; j <= i; ++j) {
      memo[j][i] = j * save % MOD;
    }
  }
  for (int move = 1; move <= m; ++move) {
    for (int x = 0; x < M; ++x) {
      for (int y = 0; y < M; ++y) {
        for (int me = 0; me < M; ++me) {
          int sA = sumA + x - N, sB = sumB + y - N;
          int& dp0 = dp[1][x][y][me][0];
          int& dp1 = dp[1][x][y][me][1];
          if (sA < 0 || sB < 0) continue;
          if (me <= sA) {
            int opt0 = memo[me][sA + sB];
            if (x + 1 < M && me + 1 < M) {
              add(dp0, (ll)opt0 * dp[0][x + 1][y][me + 1][0] % MOD);
            }
            int opt1 = memo[sA - me][sA + sB];
            if (x + 1 < M) {
              add(dp0, (ll)opt1 * dp[0][x + 1][y][me][0] % MOD);
            }
            int opt2 = memo[sB][sA + sB];
            if (y > 0) {
              add(dp0, (ll)opt2 * dp[0][x][y - 1][me][0] % MOD);
            }
          }
          if (me <= sB) {
            int opt0 = memo[me][sA + sB];
            if (y > 0 && me > 0) {
              add(dp1, (ll)opt0 * dp[0][x][y - 1][me - 1][1] % MOD);
            }
            int opt1 = memo[sB - me][sA + sB];
            if (y > 0) {
              add(dp1, (ll)opt1 * dp[0][x][y - 1][me][1] % MOD);
            }
            int opt2 = memo[sA][sA + sB];
            if (x + 1 < M) {
              add(dp1, (ll)opt2 * dp[0][x + 1][y][me][1] % MOD);
            }
          }
        }
      }
    }
    for (int x = 0; x < M; ++x) {
      for (int y = 0; y < M; ++y) {
        for (int me = 0; me < M; ++me) {
          for (int p = 0; p < 2; ++p) {
            dp[0][x][y][me][p] = dp[1][x][y][me][p];
            dp[1][x][y][me][p] = 0;
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << dp[0][N][N][b[i]][!a[i]] << '\n';
  }
}
