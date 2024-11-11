#include <bits/stdc++.h>
using namespace std;
template <class T>
using v2d = vector<vector<T> >;
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int maxN = 2e3 + 10;
int n, k, a[maxN], dp[maxN][maxN];
void solve() {
  cin >> n >> k;
  for (int i = 1; i <= (int)(n); ++i) {
    cin >> a[i];
  }
  for (int i = (int)(0); i <= (int)(n); ++i) {
    for (int j = (int)(0); j <= (int)(n); ++j) {
      dp[i][j] = -1e9;
    }
  }
  dp[0][0] = 0;
  for (int i = 1; i <= (int)(n); ++i) {
    for (int j = (int)(0); j <= (int)(i); ++j) {
      if (j > 0) {
        uax(dp[i][j], dp[i - 1][j - 1]);
      }
      uax(dp[i][j], dp[i - 1][j] + (a[i] == i - j));
    }
  }
  for (int i = 0; i < (int)(n); ++i) {
    if (dp[n][i] >= k) {
      cout << i << "\n";
      return;
    }
  }
  cout << -1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
