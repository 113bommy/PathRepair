#include <bits/stdc++.h>
using namespace std;
template <class T>
void printvec(vector<T>& x, int a, int b) {
  for (int i = (a); i <= (b); i++) cout << x[i] << " ";
  cout << "\n";
}
const double PI = acos((double)-1);
const double EPSILON = 1e-7;
const int N = 1e6 + 1;
const int NN = 1e3 + 1;
const long long MOD = 1e9 + 7;
const long long oo = LLONG_MAX;
const int BASE = 10000;
const int di[4] = {-1, 0, 1, 0};
const int dj[4] = {0, 1, 0, -1};
const char dr[4] = {'U', 'R', 'D', 'L'};
void query() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> seg(n + 1, vector<pair<int, int>>(m + 1));
  for (int i = 1; i <= n; i++) {
    int c;
    cin >> c;
    for (int j = 1; j <= c; j++) {
      pair<int, int> e;
      cin >> e.first >> e.second;
      for (int k = e.first; k <= e.second; k++) {
        seg[i][k] = e;
      }
    }
  }
  cerr << "DONE"
       << "\n";
  vector<vector<int>> dp(200, vector<int>(200));
  for (int i = 1; i <= m; i++) {
    for (int l = 1; l <= n; l++) {
      int r = l + i - 1;
      if (r > m) {
        continue;
      }
      for (int k = l; k <= r; k++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
          cnt += (seg[j][k].first >= l && seg[j][k].second <= r);
        }
        dp[l][r] = max(dp[l][r], dp[l][k - 1] + dp[k + 1][r] + cnt * cnt);
      }
    }
  }
  cout << dp[1][m];
}
void solve() {
  int t = 1;
  while (t--) {
    query();
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(4);
  solve();
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
  return 0;
}
