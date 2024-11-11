#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream &operator<<(ostream &os, const vector<T> &p) {
  os << "[";
  for (auto &it : p) os << it << " ";
  return os << "]";
}
template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &p) {
  return os << "(" << p.first << "," << p.second << ")";
}
template <class T>
bool umin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool umax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
const long long N = 2e5 + 10;
const long long inf = 1e18;
void solve() {
  long long n;
  cin >> n;
  vector<long long> h(n + 5), cost(n + 5);
  for (long long i = 1; i <= n; i++) {
    cin >> h[i] >> cost[i];
  }
  long long dp[n + 5][2];
  for (long long i = 0; i < n + 5; i++) {
    for (long long j = 0; j < 3; j++) {
      dp[i][j] = inf;
    }
  }
  dp[1][0] = 0;
  dp[1][1] = cost[1];
  dp[1][2] = cost[1] * 2;
  for (long long i = 2; i <= n; i++) {
    for (long long j = 0; j < 3; j++) {
      for (long long k = 0; k < 3; k++) {
        if (dp[i - 1][k] >= inf) continue;
        if ((h[i] + j) != (h[i - 1] + k)) {
          umin(dp[i][j], dp[i - 1][k] + j * cost[i]);
        }
      }
    }
  }
  cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << endl;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  long long q = 1;
  cin >> q;
  while (q--) solve();
  return 0;
}
