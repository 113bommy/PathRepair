#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int NAX = 50 + 10;
const ll INF = 1e10 + 10;
int n;
pair<ll, ll> arr[NAX];
ll dp[NAX][NAX][NAX];
bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
  if (a.first == b.first)
    return a.second < b.second;
  else
    return a.first > b.first;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i].first;
    arr[i].first *= 1000;
  }
  for (int i = 0; i < n; ++i) cin >> arr[i].second;
  sort(arr, arr + n, cmp);
  ll l = 0, r = INF, thresh;
  if (n == 1) {
    cout << ceil(arr[0].first / arr[0].second) << "\n";
    return 0;
  }
  while (l < r) {
    thresh = (l + r) >> 1;
    for (int i = 1; i <= n; i++)
      for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++) dp[i][j][k] = INF;
    if (arr[0].first != arr[1].first)
      dp[1][1][0] = arr[0].first - thresh * arr[0].second;
    else
      dp[1][1][1] = arr[0].first - thresh * arr[0].second;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        for (int k = 0; k <= j; k++) {
          if (dp[i][j][k] == INF) continue;
          if (arr[i].first == arr[i + 1].first) {
            dp[i + 1][j + 1][k + 1] =
                min(dp[i + 1][j + 1][k + 1],
                    dp[i][j][k] + arr[i].first - thresh * arr[i].second);
          } else
            dp[i + 1][j + 1][0] =
                min(dp[i + 1][j + 1][0],
                    dp[i][j][k] + arr[i].first - thresh * arr[i].second);
          if (k < j)
            dp[i + 1][j - 1][k] = min(dp[i + 1][j - 1][k], dp[i][j][k]);
        }
      }
    }
    ll ans = INF;
    for (int j = 0; j < n; j++)
      for (int k = 0; k <= j; k++) ans = min(ans, dp[n][j][k]);
    if (ans > 0)
      l = thresh + 1;
    else
      r = thresh;
  }
  cout << r << "\n";
  return 0;
}
