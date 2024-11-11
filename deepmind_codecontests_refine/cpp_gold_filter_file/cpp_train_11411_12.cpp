#include <bits/stdc++.h>
using namespace std;
inline bool eq(double a, double b) { return fabs(a - b) < 1e-9; }
const int inf = 1 << 29;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n >> b) & 1; }
inline void set_bit(int& n, int b) { n |= two(b); }
inline void unset_bit(int& n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) {
  int res = 0;
  while (n && ++res) n -= n & (-n);
  return res;
}
int dp[104][104][12];
long long int t;
int x1, y111, x2, y2;
void solve() {
  for (int i = (1); i < (104); i++) {
    for (int j = (1); j < (104); j++) {
      for (int k = (0); k < (12); k++) {
        dp[i][j][k] += dp[i][j - 1][k];
      }
    }
  }
  for (int j = (1); j < (104); j++) {
    for (int i = (1); i < (104); i++) {
      for (int k = (0); k < (12); k++) {
        dp[i][j][k] += dp[i - 1][j][k];
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, q, c;
  cin >> n >> q >> c;
  for (int i = 0; i < (n); i++) {
    int a, b, c;
    cin >> a >> b >> c;
    dp[a][b][c] += 1;
  }
  solve();
  for (int i = 0; i < (q); i++) {
    cin >> t >> x1 >> y111 >> x2 >> y2;
    int second[12] = {0};
    long long int ans = 0;
    for (int j = (0); j < (12); j++) {
      second[j] = dp[x2][y2][j] - dp[x1 - 1][y2][j] - dp[x2][y111 - 1][j] +
                  dp[x1 - 1][y111 - 1][j];
      ans += second[j] * ((j + t) % (c + 1));
    }
    cout << ans << endl;
  }
  return 0;
}
