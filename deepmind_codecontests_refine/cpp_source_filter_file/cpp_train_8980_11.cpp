#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
const long long MOD = 1E9 + 7;
struct Rect {
  pair<int, int> up_left;
  pair<int, int> low_right;
};
int n, m, r;
int a[MAXN + 1][MAXN + 1];
pair<int, int> snakes[2 * MAXN + 2];
int b[2 * MAXN + 2];
long long C[MAXN + 2][MAXN + 2];
int subsum(pair<int, int> x, pair<int, int> u) {
  if (x.first <= u.first && x.second <= u.second) {
    return a[u.first][u.second] - a[u.first][x.second - 1] -
           a[x.first - 1][u.second] + a[x.first - 1][x.second - 1];
  }
  return 0;
}
int snakesum(pair<int, int> x) {
  return subsum(make_pair(max(x.first - r, 1), max(x.second - r, 1)),
                make_pair(min(x.first + r, MAXN), min(x.second + r, MAXN)));
}
int rectsum(Rect x) { return subsum(x.up_left, x.low_right); }
Rect overlapRec(pair<int, int> x, pair<int, int> u) {
  Rect res;
  res.up_left = {max(max(x.first - r, u.first - r), 1),
                 max(max(x.second - r, u.second - r), 1)};
  res.low_right = {min(min(x.first + r, u.first + r), MAXN),
                   min(min(x.second + r, u.second + r), MAXN)};
  return res;
}
signed main() {
  cin >> n >> m >> r;
  for (int i = 1; i <= n; ++i) {
    cin >> snakes[i].first >> snakes[i].second >> b[i];
    a[snakes[i].first][snakes[i].second] = 1;
  }
  for (int i = 1; i <= MAXN; ++i) {
    for (int j = 1; j <= MAXN; ++j) {
      a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    }
  }
  for (int i = 0; i <= n; ++i) {
    C[0][i] = 1;
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      C[i][j] = (C[i - 1][j - 1] + C[i][j - 1]) % MOD;
    }
  }
  long long ans = 0LL;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      int save_both = C[m][n - snakesum(snakes[i]) - snakesum(snakes[j]) +
                           rectsum(overlapRec(snakes[i], snakes[j]))];
      long long x1 = ((1LL * b[i] * 1LL * b[j]) % MOD);
      long long x2 = ((C[m][n] + MOD - C[m][n - snakesum(snakes[i])] + MOD -
                       C[m][n - snakesum(snakes[j])] + save_both)) %
                     MOD;
      ans += x1 * x2 % MOD;
      ans %= MOD;
    }
  }
  cout << ans << "\n";
}
