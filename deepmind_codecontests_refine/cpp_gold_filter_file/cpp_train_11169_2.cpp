#include <bits/stdc++.h>
using ll = long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;
template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
T mypow(T x, T n, const T &p = -1) {
  T ret = 1;
  while (n > 0) {
    if (n & 1) {
      if (p != -1)
        ret = (ret * x) % p;
      else
        ret *= x;
    }
    if (p != -1)
      x = (x * x) % p;
    else
      x *= x;
    n >>= 1;
  }
  return ret;
}
using namespace std;
int lcs(string a, string b) {
  int n = a.size(), m = b.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  int res = 0;
  for (int i = (int)0; i < (int)n; ++i) {
    for (int j = (int)0; j < (int)m; ++j) {
      if (a[i] == b[j]) {
        dp[i + 1][j + 1] = dp[i][j] + 2;
        chmax(res, dp[i + 1][j + 1]);
      } else {
        dp[i + 1][j + 1] = max(0, max(dp[i + 1][j], dp[i][j + 1]) - 1);
      }
    }
  }
  return res;
}
void solve() {
  int n, m;
  cin >> n >> m;
  string a, b;
  cin >> a >> b;
  int ans = lcs(a, b);
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(15);
  solve();
  return 0;
}
