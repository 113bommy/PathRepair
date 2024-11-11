#include <bits/stdc++.h>
const int maxn = 4000;
const double EPS = 1e-9;
const double PI = 3.141592653589793;
using namespace std;
const long long MOD = 1e9 + 7;
long long a[maxn];
int b[maxn];
vector<pair<long long, int>> v;
long long w[maxn];
long long dp[101][101][101];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] = a[i] * 1000;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; ++i) {
    v.push_back(make_pair(a[i], b[i]));
  }
  sort(v.rbegin(), v.rend());
  long long l = 0;
  long long r = 1e12;
  long long ans = -1;
  while (l <= r) {
    long long m = (l + r) / 2;
    for (int i = 0; i < n; ++i) {
      w[i] = v[i].first - m * v[i].second;
    }
    for (int i = 0; i <= 50; ++i)
      for (int j = 0; j <= 50; ++j)
        for (int e = 0; e <= 50; ++e) dp[i][j][e] = 1e15;
    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= n; ++j) {
        for (int e = 0; e <= n; ++e) {
          bool eq = 1;
          if (i && v[i].first != v[i - 1].first) eq = 0;
          if (eq && e + 1 <= 50) {
            dp[i + 1][j][e + 1] = min(dp[i + 1][j][e + 1], dp[i][j][e] + w[i]);
          }
          if (!eq && j + e <= 50) {
            dp[i + 1][j + e][1] = min(dp[i + 1][j + e][1], dp[i][j][e] + w[i]);
          }
          if (j && eq) {
            dp[i + 1][j - 1][e] = min(dp[i + 1][j - 1][e], dp[i][j][e]);
          }
          if ((j || e) && !eq && j - 1 + e <= 50) {
            dp[i + 1][j - 1 + e][0] = min(dp[i + 1][j - 1 + e][0], dp[i][j][e]);
          }
        }
      }
    }
    long long mn = 1e15;
    for (int i = 0; i <= n; ++i)
      for (int j = 0; j <= n; ++j) {
        mn = min(mn, dp[n][i][j]);
      }
    if (mn <= 0) {
      ans = m;
      r = m - 1;
    } else
      l = m + 1;
  }
  cout << ans;
}
