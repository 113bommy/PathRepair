#include <bits/stdc++.h>
using namespace std;
void dout() { cerr << "\n"; }
template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
  cerr << H << ' ';
  dout(T...);
}
long long bit(signed x) { return __builtin_popcount(x); }
long long bit(long long x) { return __builtin_popcountll(x); }
const long long N = 2007, MOD = 1e9 + 7;
long long n, m, a[N][N], c[N][N], r[N][N], up[N][N], alimq[N][N];
void add(long long& x, long long y) {
  x += y;
  if (x < 0) {
    x += MOD;
  }
  if (x >= MOD) {
    x -= MOD;
  }
}
void solve(long long tc) {
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      char c;
      cin >> c;
      if (c == 'R') {
        a[i][j] = 1;
      }
    }
  }
  for (long long i = n; i >= 1; i--) {
    for (long long j = m; j >= 1; j--) {
      r[i][j] = r[i][j + 1];
      c[i][j] = c[i + 1][j];
      if (a[i][j]) {
        r[i][j]++;
        c[i][j]++;
      }
    }
  }
  if (r[1][1] == m && c[1][1] == n) {
    cout << 0;
    return;
  }
  if (n == 1 && m == 1) {
    cout << 1;
    return;
  }
  up[1][1] = 1;
  alimq[1][1] = 1;
  up[2][1] = MOD - 1;
  alimq[1][2] = MOD - 1;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      add(up[i][j], up[i - 1][j]);
      add(alimq[i][j], alimq[i][j - 1]);
      long long rl = m - r[i][j + 1] + 1;
      long long cl = n - c[i + 1][j] + 1;
      add(up[i + 1][j], alimq[i][j]);
      add(alimq[i][j + 1], up[i][j]);
      add(up[cl][j], -alimq[i][j]);
      add(alimq[i][rl], -up[i][j]);
    }
  }
  cout << (up[n][m] + alimq[n][m]) % MOD;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tc = 1;
  for (long long i = 0; i < tc; i++) {
    solve(i);
  }
}
