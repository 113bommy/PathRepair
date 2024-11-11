#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using i64 = long long;
using namespace std;
void yes(bool y) { cout << (y ? "YES\n" : "NO\n"); }
template <typename T>
ostream& operator<<(ostream& os, vector<T> const& v) {
  for (T x : v) {
    os << x << ' ';
  }
  cout << '\n';
  return os;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v) {
    is >> x;
  }
  return is;
}
const int mod = 998244353;
const int maxn = 3e5;
int dp[3][maxn + 1], p;
int mex(vector<int> a) {
  sort((a).begin(), (a).end());
  a.resize(unique((a).begin(), (a).end()) - a.begin());
  for (int i = 0; i < a.size(); ++i) {
    if (i != a[i]) return i;
  }
  return a.back() + 1;
}
int get(int dp[maxn], int n) {
  if (n <= 200) return dp[n];
  return dp[(n - 200) % p + 200];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int _t;
  cin >> _t;
  while (_t--) {
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<int> a(n);
    cin >> a;
    p = -1;
    for (int i = 1; i <= 300; i++) {
      dp[0][i] = mex(
          {dp[0][max(i - x, 0)], dp[1][max(i - y, 0)], dp[2][max(i - z, 0)]});
      dp[1][i] = mex({dp[0][max(i - x, 0)], dp[2][max(i - z, 0)]});
      dp[2][i] = mex({dp[0][max(i - x, 0)], dp[1][max(i - y, 0)]});
      if (i <= 200) continue;
      bool ok = true;
      for (int j = 0; j < 5; j++) {
        ok &= dp[0][200 - j] == dp[0][i - j];
        ok &= dp[1][200 - j] == dp[1][i - j];
        ok &= dp[2][200 - j] == dp[2][i - j];
      }
      if (ok) {
        p = i;
        break;
      }
    }
    p -= 200;
    int xo = 0;
    for (int i = 0; i < n; i++) {
      xo ^= get(dp[0], a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      xo ^= get(dp[0], a[i]);
      ans += (xo ^ get(dp[0], a[i] - x)) == 0;
      ans += (xo ^ get(dp[1], a[i] - y)) == 0;
      ans += (xo ^ get(dp[2], a[i] - z)) == 0;
      xo ^= get(dp[0], a[i]);
    }
    cout << ans << '\n';
  }
}
