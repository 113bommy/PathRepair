#include <bits/stdc++.h>
const long long inf = 9999999999;
using namespace std;
pair<long long, long long> c[300100];
pair<long long, long long> dp[300100][2];
pair<long long, long long> minn(pair<long long, long long> a,
                                pair<long long, long long> b) {
  if (a.second < b.second) {
    return a;
  }
  return b;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, x, y;
  cin >> n >> x >> y;
  for (long long i = 0; i < n; i++) {
    long long uu;
    cin >> uu;
    c[i] = {uu, i + 1};
  }
  sort(c, c + n);
  memset(dp, 0, sizeof dp);
  for (long long i = n - 1; i > -1; i--) {
    long long ans0 = (x + c[i].first - 1) / c[i].first;
    if (ans0 + i <= n) {
      if (dp[i + 1][0].second != 0) {
        dp[i][0] = minn(dp[i + 1][0], {i, i + ans0});
      } else {
        dp[i][0] = {i, i + ans0};
      }
    } else {
      dp[i][0] = dp[i + 1][0];
    }
    ans0 = (y + c[i].first - 1) / c[i].first;
    if (ans0 + i <= n) {
      if (dp[i + 1][1].second != 0) {
        dp[i][1] = minn(dp[i + 1][1], {i, i + ans0});
      } else {
        dp[i][1] = {i, i + ans0};
      }
    } else {
      dp[i][1] = dp[i + 1][1];
    }
  }
  for (long long i = 0; i < n; i++) {
    if (dp[i][0].second != 0) {
      if (dp[dp[i][0].second][1].second != 0) {
        cout << "Yes" << endl;
        cout << dp[i][0].second - dp[i][0].first << ' '
             << dp[dp[i][0].second][1].second - dp[dp[i][0].second][1].first
             << endl;
        for (long long j = dp[i][0].first; j < dp[i][0].second; j++)
          cout << c[j].second << ' ';
        cout << endl;
        for (long long j = dp[dp[i][0].second][1].first;
             j < dp[dp[i][0].second][1].second; j++)
          cout << c[j].second << ' ';
        return 0;
      }
    }
    if (dp[i][1].second != 0) {
      if (dp[dp[i][1].second][0].second != 0) {
        cout << "Yes" << endl;
        cout << dp[dp[i][1].second][0].second - dp[dp[i][1].second][0].first
             << ' ' << dp[i][1].second - dp[i][1].first << endl;
        for (long long j = dp[dp[i][1].second][0].first;
             j < dp[dp[i][1].second][0].second; j++)
          cout << c[j].second << ' ';
        cout << endl;
        for (long long j = dp[i][1].first; j < dp[i][1].second; j++)
          cout << c[j].second << ' ';
        return 0;
      }
    }
  }
  cout << "No";
  return 0;
}
