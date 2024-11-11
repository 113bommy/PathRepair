#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (T e : v) {
    os << e << ' ';
  }
  return os;
}
constexpr int MAXN = 101;
ll dp[MAXN][MAXN][MAXN];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<ll> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  function<ll(int, int, int)> solve = [&](int l, int r, int cur) {
    if (l > r) {
      return 0LL;
    }
    if (l == r) {
      return a[cur];
    }
    if (dp[l][r][cur]) {
      return dp[l][r][cur];
    }
    ll best = a[cur] + solve(l + 1, r, 1);
    for (int k = l + 1; k <= r; ++k) {
      if (s[k] == s[l]) {
        best = max(best, solve(l + 1, k - 1, 1) + solve(k, r, cur + 1));
      }
    }
    return dp[l][r][cur] = best;
  };
  cout << solve(0, n - 1, 1) << endl;
  return 0;
}
