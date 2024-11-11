#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;
inline long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline long long pwm(long long xx, long long pow, long long MD) {
  if (pow < 0) {
    pow = pow % (MD - 1) + MD - 1;
  }
  long long mlt = 1;
  while (pow) {
    if (pow & 1) {
      mlt *= xx;
      mlt %= MD;
    }
    xx *= xx;
    pow >>= 1;
    xx %= MD;
  }
  return mlt;
}
inline long long gcdex(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long xx, yy;
  long long gc = gcdex(b, a % b, yy, xx);
  x = xx;
  y = yy - (a / b) * xx;
  return gc;
}
inline int inv(long long r, int _mod) { return pwm(r % _mod, _mod - 2, _mod); }
inline int64_t hilbertOrder(int x, int y, int pow, int rotate) {
  if (pow == 0) {
    return 0;
  }
  int hpow = 1 << (pow - 1);
  int seg = (x < hpow) ? ((y < hpow) ? 0 : 3) : ((y < hpow) ? 1 : 2);
  seg = (seg + rotate) & 3;
  const int rotateDelta[4] = {3, 0, 0, 1};
  int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
  int nrot = (rotate + rotateDelta[seg]) & 3;
  int64_t subSquareSize = int64_t(1) << (2 * pow - 2);
  int64_t ans = seg * subSquareSize;
  int64_t add = hilbertOrder(nx, ny, pow - 1, nrot);
  ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
  return ans;
}
pair<int, int> dp[401][401];
string s, t;
int n, m;
int pref[401][26];
int leftpref[401][26];
void precalc() {
  for (int j = 0; j < 'z' - 'a' + 1; j++) {
    pref[0][j] = -1;
    for (int i = 1; i <= n; i++) {
      pref[i][j] = (s[i - 1] - 'a' == j) ? j : pref[i - 1][j];
    }
  }
  for (int j = 0; j < 'z' - 'a' + 1; j++) {
    leftpref[n][j] = -1;
    for (int i = n - 1; i >= 0; i--) {
      leftpref[i][j] = (s[i] - 'a' == j) ? i : leftpref[i + 1][j];
    }
  }
}
bool solve1(int left, int right) {
  dp[0][0] = {1, 0};
  for (int i = 0; i <= left; i++) {
    for (int j = 0; j <= right; j++) {
      if (i == 0 && j == 0) continue;
      dp[i][j] = {0, n};
      if (i - 1 >= 0 && dp[i - 1][j].first && dp[i - 1][j].second < n) {
        int next = leftpref[dp[i - 1][j].second][t[i - 1] - 'a'];
        if (next != -1 && next < n) {
          dp[i][j] = {1, next + 1};
        }
      }
      if (j - 1 >= 0 && dp[i][j - 1].first && dp[i][j - 1].second < n) {
        int next = leftpref[dp[i][j - 1].second][t[left + j - 1] - 'a'];
        if (next != -1 && next < n) {
          dp[i][j] = {1, min(dp[i][j].second, next + 1)};
        }
      }
    }
  }
  return dp[left][right].first != 0;
}
void solve() {
  cin >> s >> t;
  n = s.size();
  m = t.size();
  precalc();
  for (int i = 0; i < m; i++) {
    if (solve1(i, m - i)) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  unsigned int beg_time = clock();
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) solve();
  unsigned int end_time = clock();
  return 0;
}
