#include <bits/stdc++.h>
using namespace std;
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
const long long M = 1e9 + 7;
const long long MOD = 1e9 + 7;
const double PI = atan2(0, -1);
const long long inf = 1e9;
const long long infl = 2e18;
const long long N = 1e5 + 10;
long long dp[N][6], prevv[N][6];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << setprecision(20) << fixed;
  long long n;
  cin >> n;
  vector<long long> a(n + 1);
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 1; i <= 5; i++) dp[1][i] = 1;
  for (long long i = 2; i <= n; i++) {
    for (long long j = 1; j <= 5; j++) {
      for (long long k = 1; k <= 5; k++) {
        if (a[i] > a[i - 1] and j > k or a[i] == a[i - 1] and j == k or
            a[i] < a[i - 1] and j < k) {
          if (uax(dp[i][j], dp[i - 1][k])) prevv[i][j] = k;
        }
      }
    }
  }
  long long mx = 0, s = -1;
  for (long long i = 1; i <= 5; i++)
    if (uax(mx, dp[n][i])) s = i;
  if (s == 0)
    cout << -1;
  else {
    long long i = n;
    vector<long long> ans;
    ans.push_back(s);
    while (prevv[i][s] != 0) {
      s = prevv[i][s];
      i--;
      ans.push_back(s);
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans) cout << i << " ";
  }
}
