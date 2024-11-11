#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long inf = 1LL << 50;
const int N = 75;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  for (int z = 0; z < T; z++) {
    int n, k;
    cin >> n >> k;
    vector<vector<pair<long long, vector<int>>>> dp(
        n, vector<pair<long long, vector<int>>>(k + 1, {-inf, vector<int>()}));
    vector<pair<int, pair<int, int>>> srted(n);
    for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      srted[i].first = b;
      srted[i].second.first = a;
      srted[i].second.second = i;
    }
    sort(srted.begin(), srted.end());
    dp[0][1].first = srted[0].second.first;
    dp[0][1].second.push_back(srted[0].second.second);
    dp[0][0].first = (n - 1) * srted[0].first;
    for (int i = 1; i < n; i++) {
      dp[i][0].first = dp[i - 1][0].first + srted[i].first * (n - 1);
      for (int a = 1; a <= k; a++) {
        if (dp[i - 1][a].first + srted[i].first * (n - 1) >
            dp[i - 1][a - 1].first + srted[i].first * (a - 1) +
                srted[i].second.first) {
          dp[i][a].first = dp[i - 1][a].first + srted[i].first * (n - 1);
          dp[i][a].second = dp[i - 1][a].second;
        } else {
          dp[i][a].first = dp[i - 1][a - 1].first + srted[i].first * (a - 1) +
                           srted[i].second.first;
          dp[i][a].second = dp[i - 1][a - 1].second;
          dp[i][a].second.push_back(srted[i].second.second);
        }
      }
    }
    cout << n + (n - k) << "\n";
    vector<bool> visited(n, false);
    for (int i = 0; i < dp[n - 1][k].second.size() - 1; i++) {
      cout << dp[n - 1][k].second[i] + 1 << " ";
      visited[dp[n - 1][k].second[i]] = true;
    }
    for (int i = 0; i < n; i++) {
      if (!visited[i] && i != dp[n - 1][k].second.back()) {
        cout << i + 1 << " " << -(i + 1) << " ";
      }
    }
    cout << dp[n - 1][k].second.back() + 1 << '\n';
  }
}
