#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template <class T>
bool ckmin(T& a, const T& b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int B = 31, M = 1e9 + 7;
template <class T>
void add(T& x, int y) {
  x += y;
  if (M <= x) x -= M;
}
template <class T>
void sub(T& x, int y) {
  x -= y;
  if (x < 0) x += M;
}
int dp[B + 1][2][2][2], f[B + 1][2][2][2];
void add(int& x, int y) {
  x += y;
  if (M <= x) x -= M;
}
void sub(int& x, int y) {
  x -= y;
  if (x < 0) x += M;
}
int g(int x, int y, int k) {
  for (auto i = (0); i < (B); ++i)
    for (auto a = (0); a < (2); ++a)
      for (auto b = (0); b < (2); ++b)
        for (auto c = (0); c < (2); ++c) dp[i][a][b][c] = f[i][a][b][c] = 0;
  f[B][0][0][0] = 1;
  for (auto z = (B); z-- > (0);) {
    int u = x >> z & 1, v = y >> z & 1, w = k >> z & 1;
    for (auto a : {0, 1}) {
      for (auto b : {0, 1}) {
        for (auto c : {0, 1}) {
          for (auto p : {0, 1}) {
            for (auto q : {0, 1}) {
              auto r = p ^ q;
              if ((!a && p > u) || (!b && q > v) || (!c && r > w)) continue;
              auto i = a || p != u, j = b || q != v, k = c || r != w;
              add(dp[z][i][j][k], dp[z + 1][a][b][c]);
              if (r) add(dp[z][i][j][k], ll(f[z + 1][a][b][c]) << z % M);
              add(f[z][i][j][k], f[z + 1][a][b][c]);
            }
          }
        }
      }
    }
  }
  return (dp[0][1][1][1] + f[0][1][1][1]) % M;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    --a;
    --b;
    int ans = 0;
    add(ans, g(c, d, k));
    sub(ans, g(a, d, k));
    sub(ans, g(c, b, k));
    add(ans, g(a, b, k));
    cout << ans << '\n';
  }
}
